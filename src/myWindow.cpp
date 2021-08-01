#include "ofMain.h"
#include "myWindow.hpp"

void myWindow::setup(){
    ofLog(OF_LOG_NOTICE, "myWindow::setup");
    ofSetWindowShape(500, 500);
    ofSetWindowPosition(10, 10);
}
