#include "myOsc.hpp"

auto myOsc::currentMessage = ofxOscMessage();
auto myOsc::receiver = ofxOscReceiver();
auto myOsc::observers = std::map<std::string, OscObserver>();

void myOsc::setup() {
    ofLog(OF_LOG_NOTICE, "myOsc::setup");
    receiver.setup(0);
    OscObserver testObserver = [](ofxOscMessage& message){
        ofLog(OF_LOG_NOTICE, "a message");
    };
    myOsc::subscribe("test", testObserver);
    myOsc::broadcastMessage(currentMessage);
    myOsc::unsubscribe("test");
}

void myOsc::stop() {
    receiver.stop();
}

void myOsc::update() {
    while (receiver.hasWaitingMessages()) {
        receiver.getNextMessage(currentMessage);
        broadcastMessage(currentMessage);
    }
}

void myOsc::subscribe(std::string name, OscObserver observer) {
    observers[name] = observer;
};

void myOsc::unsubscribe(std::string name) {
    observers.erase(name);
};

void myOsc::broadcastMessage(ofxOscMessage message) {
    for (std::pair<std::string, OscObserver> const& x : observers)
    {
        auto const observer = x.second;
        observer(message);
    }
}