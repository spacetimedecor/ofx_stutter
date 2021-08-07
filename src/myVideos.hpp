#ifndef MYSKETCH_MYVIDEOS_HPP
#define MYSKETCH_MYVIDEOS_HPP
//#pragma once
#include <map>
#include "ofFileUtils.h"
#include "ofLog.h"
#include "ofUtils.h"
#include "ofVideoPlayer.h"
using namespace std;

class myVideoPlayer: public ofVideoPlayer {
    private: ofFile currentFile;
    public:
        void loadVideo(string path);
        void loadVideo(ofFile file);
        void updateVideo();
        void playVideo();
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class myVideos {
    private:
        static ofDirectory videoDirectory;
        static map<string, ofFile> videoFiles;
        static map<string, myVideoPlayer*> videoPlayers;
        static void initialiseDirectory();
        static void initialiseVideoMap();
    public:
        static void setup();
        static vector<string> getNames();
        static void printNames();
        static ofFile getFile(string name);
        static myVideoPlayer * createVideoPlayer(string name);
        static void update();
};
#endif //MYSKETCH_MYVIDEOS_HPP
