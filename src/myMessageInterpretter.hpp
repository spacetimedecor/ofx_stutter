#ifndef MYSKETCH_MYMESSAGEINTERPRETTER_HPP
#define MYSKETCH_MYMESSAGEINTERPRETTER_HPP

#pragma once
#include "myOsc.hpp"

typedef std::map<std::string, std::vector<OscObserver>> MessageFunctionMap;

struct myMessageInterpretter {
    public:
        static void interpret(ofxOscMessage message);
        static void setup();
    private:
        static MessageFunctionMap map;
};

#endif //MYSKETCH_MYMESSAGEINTERPRETTER_HPP
