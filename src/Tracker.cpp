//
//  Tracker.cpp
//  JojiMusicProduction
//
//  Created by Daniel Zhu on 11/7/22.
//

#include "Tracker.hpp"
Tracker::Tracker(){
}

void Tracker::setup() {
    x = 0;
    y = 0;
    rotation = 0;
    size = 30;
    mobile = false;
    kInteract = false;
}

void Tracker::update() {
    std::cout << rotation << endl;
}

void Tracker::updateOrientation(float nx, float ny, float nr) {
    if (mobile) {
        x = nx;
        y = ny;
        rotation += nr;
    }
}

void Tracker::toggleMobile() {
    mobile = !mobile;
}

void Tracker::toggleKInteract() {
    kInteract = !kInteract;
}

void Tracker::rotateGradually() {
    rotation += PI/16;
}

void Tracker::draw() {
    //Body
    ofSetColor(255);
    if (kInteract) {
        ofSetColor(200);
    }
    ofDrawCircle(x, y, size);
    
    float rx = x + cos(rotation) * (size + 10);
    float ry = y + sin(rotation) * (size + 10);
    ofSetColor(0);
    ofDrawLine(x,y,rx,ry);
}
