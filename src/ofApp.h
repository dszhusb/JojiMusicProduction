#pragma once

#include "Tracker.hpp"
#include "Slider.hpp"
#include "Dial.hpp"
#include "ofMain.h"
#include "ofxRemoteUIServer.h"
#include "ofxMotive.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxMotive motive;
    void newDataReceived(MotiveEventArgs& args);
    
    void trackerInteractions();
    bool inRange(float tx, float ty);
    float actRange;
    
    Tracker kettle;
    bool kInteract;
    
    vector <Slider> sliders;
    vector <Dial> dials;
};
