#ifndef myosc_hpp
#define myosc_hpp

#include "ofxOsc.h"
#include<functional>
using namespace std;

#define PORT 12345

typedef function <void(ofxOscMessage&)> OscObserver;

struct myOsc {
    private:
        static ofxOscMessage currentMessage;
        static map<string, OscObserver> observers;
    public:
        static void setup();
        static void stop();
        static void update();
        static void subscribe(string name, OscObserver observer);
        static void unsubscribe(string name);
        static void broadcastMessage(ofxOscMessage currentMessage);
        static ofxOscReceiver receiver;
};

#endif /* osc_hpp */
