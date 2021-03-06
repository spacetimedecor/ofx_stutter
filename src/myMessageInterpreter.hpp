#ifndef MYSKETCH_MYMESSAGEINTERPRETER_HPP
#define MYSKETCH_MYMESSAGEINTERPRETER_HPP

#pragma once
#include "myOsc.hpp"
using namespace std;

typedef map<string, vector<OscObserver>> MessageFunctionMap;

struct myMessageInterpreter {
    public:
        static void interpret(ofxOscMessage message);
        static void setup();
    private:
        static MessageFunctionMap map;
};

#endif //MYSKETCH_MYMESSAGEINTERPRETER_HPP
