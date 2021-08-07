#include "myVideos.hpp"

ofDirectory myVideos::videoDirectory;
map<string, ofFile> myVideos::videoFiles;
map<string, myVideoPlayer*> myVideos::videoPlayers;

void myVideos::setup() {
    initialiseDirectory();
    initialiseVideoMap();
    printNames();
}

void myVideos::initialiseDirectory() {
    videoDirectory = ofDirectory(ofToDataPath("videos"));
    videoDirectory.listDir();
}

void myVideos::initialiseVideoMap() {
    for (ofFile const &file: videoDirectory){
        videoFiles.insert (make_pair(file.getFileName(), file));
    }
}

vector<string> myVideos::getNames() {
    vector<string> videoNames;
    for(auto const& imap: videoFiles)
        videoNames.push_back(imap.first);
    return videoNames;
}

void myVideos::printNames() {
    for (string const &name: getNames())
        cout << name << " ";
}

ofFile myVideos::getFile(string name) {
    return videoFiles.at(name);
}

myVideoPlayer* myVideos::createVideoPlayer(string name) {
    myVideoPlayer* instance = new myVideoPlayer();
    videoPlayers.insert(make_pair(name, instance));
    return instance;
}

void myVideos::update() {
    for (pair<string, myVideoPlayer *> const &p : videoPlayers)
        p.second->update();
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void myVideoPlayer::loadVideo(string path) {
    this->currentFile = myVideos::getFile(path);
    this->load(path);
}

void myVideoPlayer::loadVideo(ofFile file) {
    this->currentFile = file;
    this->load(file.getAbsolutePath());
}

void myVideoPlayer::playVideo() {

}

void myVideoPlayer::updateVideo() {
    if
    (
        this->isLoaded() &&
        this->isInitialized() &&
        this->isPlaying()
    )
        this->update();
}

