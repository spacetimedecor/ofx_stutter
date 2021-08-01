#include "ofxOsc.h"
#include<functional>

#ifndef myosc_hpp
#define myosc_hpp

#define PORT 12345

typedef std::function <void(ofxOscMessage&)> OscObserver;

struct myOsc {
    private:
        static ofxOscMessage currentMessage;
        static std::map<std::string, OscObserver> observers;
    public:
        static void setup();
        static void stop();
        static void update();
        static void subscribe(std::string name, OscObserver observer);
        static void unsubscribe(std::string name);
        static void broadcastMessage(ofxOscMessage currentMessage);
        static ofxOscReceiver receiver;
};

#endif /* osc_hpp */
