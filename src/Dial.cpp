//
//  Dial.cpp
//  JojiMusicProduction
//
//  Created by Daniel Zhu on 11/8/22.
//

#include "Dial.hpp"
Dial::Dial() {
}

void Dial::setup(float sx, float sy, float sr) {
    x = sx;
    y = sy;
    rotation = 0;
    percentage = PI;
    size = 32;
}

void Dial::update() {
    
}

vector<float> Dial::getLocation() {
    return {x, y};
}

void Dial::draw() {
    
    ofPushMatrix();
    ofTranslate(x,y);
    //Circle Bound
    ofSetColor(255,255,255);
    ofDrawCircle(0,0,size);
    ofSetColor(10,8,18);
    ofDrawCircle(0,0,size - 1);
    
    //Indicator
    ofRotateZDeg(percentage * 180 / PI);
    ofSetColor(255,255,255);
    ofDrawRectangle(0,20,1,20);
    ofPopMatrix();
}

void Dial::updatePercentage(float p) {
    percentage = fmod( p, 2 * PI);
}
