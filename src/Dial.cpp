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
    percentage = 50;
    size = 50;
}

void Dial::update() {
    
}

vector<float> Dial::getLocation() {
    return {x, y};
}

void Dial::draw() {
    ofSetColor(200, 200, 0);
    ofDrawCircle(x, y, size);
    ofSetColor(0,0,0);
    ofDrawCircle(x + size/3 * 2 * cos(percentage), y + size/3 * 2 * sin(percentage), 10);
}

void Dial::updatePercentage(float p) {
    percentage = p;
}
