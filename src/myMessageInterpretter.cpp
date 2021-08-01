#include "myMessageInterpretter.hpp"

MessageFunctionMap myMessageInterpretter::map {
    {
        "/Test",
        {
            [](ofxOscMessage &message) {
                auto test = 1;
            },
            [](ofxOscMessage &message) {
                auto test = 1;
            },
        }
    },
    {
        "/Note1",
        {
            [](ofxOscMessage &message) {
                auto test = 1;
                std::cout << test << std::endl;
                std::cout << message << std::endl;
            },
            [](ofxOscMessage &message) {
                auto test = 2;
                std::cout << test << std::endl;
                std::cout << message << std::endl;
            },
        }
    },
};

void myMessageInterpretter::interpret(ofxOscMessage message) {

    auto messageAddress = message.getAddress();
    if (!map.count(messageAddress)) return;

    for (OscObserver const &observer: map.at(messageAddress)) observer(message);
}

void myMessageInterpretter::setup() {
    myOsc::subscribe("message_interpreter", [](ofxOscMessage &message){
        myMessageInterpretter::interpret(message);
    });
}