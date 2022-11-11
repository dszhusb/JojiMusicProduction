//
//  Slider.hpp
//  JojiMusicProduction
//
//  Created by Daniel Zhu on 11/7/22.
//

#ifndef Slider_hpp
#define Slider_hpp

#include <stdio.h>
#include "ofMain.h"

class Slider {
public:
    
    void setup(float sx, float sy, float sr);
    void update();
    void draw();
    void updatePercentage(float p);
    vector<float> getSliderCoords();
    vector<float> calcDisp();
    float calcSliderMov(float mouseX, float mouseY, float per);
    float constrain(float p);
    float noNan(float p);
    
    float x;
    float y;
    float rotation;
    float length;
    float percentage;
    
    Slider();
private:
};
#endif /* Slider_hpp */
