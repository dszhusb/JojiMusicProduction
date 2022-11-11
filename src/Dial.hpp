//
//  Dial.hpp
//  JojiMusicProduction
//
//  Created by Daniel Zhu on 11/8/22.
//

#ifndef Dial_hpp
#define Dial_hpp

#include <stdio.h>
#include "ofMain.h"

class Dial {
public:
    
    void setup(float sx, float sy, float sr);
    void update();
    void draw();
    void updatePercentage(float p);
    vector<float> getLocation();
    
    float x;
    float y;
    float rotation;
    float percentage;
    float size;
    
    Dial();
private:
};
#endif /* Dial_hpp */
