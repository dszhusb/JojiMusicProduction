//
//  Slider.cpp
//  JojiMusicProduction
//
//  Created by Daniel Zhu on 11/7/22.
//

#include "Slider.hpp"
Slider::Slider() {
}

void Slider::setup(float sx, float sy, float sr) {
    x = sx;
    y = sy;
    rotation = 0;
    percentage = 50;
    length = 128;
}

void Slider::update() {
    
}

void Slider::draw() {
    vector<float> disps = calcDisp();
    
    ofPushMatrix();
    ofTranslate(x,y);
    
    ofSetColor(255);
    ofDrawRectRounded(-disps[0],-disps[1]-32,length,64,32);
    ofSetColor(10,8,18);
    ofDrawRectRounded(-disps[0] + 1,-disps[1]-31,length-2,62,32);
    
    ofSetColor(255);
    ofDrawCircle(disps[2]+32,disps[3],32);
    ofSetColor(10,8,18);
    ofDrawCircle(disps[2]+32,disps[3],31);
                    
    ofPopMatrix();
}

void Slider::updatePercentage(float p) {
    percentage = p;
}

vector<float> Slider::getSliderCoords() {
    vector<float> disps = calcDisp();
    return {disps[2], disps[3]};
}

vector<float> Slider::calcDisp() {
    float dx = cos(rotation) * (length/2);
    float dy = sin(rotation) * (length/2);
    float mx = (percentage - 50)/100 * dx * 2;
    float my = (percentage - 50)/100 * dy * 2;
    
    return {dx, dy, mx, my};
}

float Slider::calcSliderMov(float mouseX, float mouseY, float per) {
    vector<float> disps = calcDisp();
    float nx = x - disps[0];
    float ny = y - disps[1];
    float dist = sqrt(pow(nx - mouseX, 2) + pow(ny - mouseY, 2));
    float theta2 = atan(noNan(ny - mouseY)/noNan(nx - mouseX));
//    cout << theta2 << endl;
    float dTheta = theta2 - (rotation * PI) / 180;
    float result = (dist * cos(dTheta)) / 2;
    return constrain(result);
}

float Slider::constrain(float p) {
    if (p < 0) {
        return 0;
    } else if (p > 100) {
        return 100;
    }
    return p;
}

float Slider::noNan(float p) {
    if (p == 0) {
        return 0.1;
    }
    return p;
}
