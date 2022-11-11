//
//  Tracker.hpp
//  JojiMusicProduction
//
//  Created by Daniel Zhu on 11/7/22.
//

#ifndef Tracker_hpp
#define Tracker_hpp

#include <stdio.h>
#include "ofMain.h"

class Tracker {
public:
    
    void setup();
    void update();
    void draw();
    void updateOrientation(float nx, float ny, float nr);
    void toggleMobile();
    void toggleKInteract();
    void rotateGradually();
    
    float x;
    float y;
    bool mobile;
    bool kInteract;
    float rotation;
    float size;
    
    Tracker();
private:
};

#endif /* Tracker_hpp */
