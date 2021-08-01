#include "ofxOsc.h"
#include<functional>

#ifndef myosc_hpp
#define myosc_hpp

#define PORT 12345

using OscObserver = std::function <void(ofxOscMessage&)>;

struct myOsc {
    private:
        static ofxOscMessage currentMessage;
        static std::map<std::string, OscObserver> observers;
        static void broadcastMessage(ofxOscMessage currentMessage);
    public:
        static void setup();
        static void stop();
        static void update();
        static void subscribe(std::string name, OscObserver observer);
        static void unsubscribe(std::string name);
        static ofxOscReceiver receiver;
};

#endif /* osc_hpp */
