#include "myOsc.hpp"

auto myOsc::currentMessage = ofxOscMessage();
auto myOsc::receiver = ofxOscReceiver();
auto myOsc::observers = map<string, OscObserver>();

void myOsc::setup() {
    receiver.setup(PORT);
}

void myOsc::stop() {
    receiver.stop();
}

void myOsc::update() {
    while (receiver.hasWaitingMessages()) {
        receiver.getNextMessage(&currentMessage);
        broadcastMessage(currentMessage);
    }
}

void myOsc::subscribe(string name, OscObserver observer) {
    observers[name] = observer;
};

void myOsc::unsubscribe(string name) {
    observers.erase(name);
};

void myOsc::broadcastMessage(ofxOscMessage message) {
    for (pair<string, OscObserver> const& x : myOsc::observers)
    {
        auto const observer = x.second;
        observer(message);
    }
}