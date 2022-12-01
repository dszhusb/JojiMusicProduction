#pragma once

#include "Tracker.hpp"
#include "Slider.hpp"
#include "Dial.hpp"
#include "ofxNetwork.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{
    
public:
    //Standard Functions
    void setup();
    void update();
    void draw();
    
    //Default Functions
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
    
    //Tracker Functions
    void trackerInteractions();
    bool inRange(float tx, float ty);
    float actRange;
    
    //Text Functions
    int margin;
    int gutter;
    int colWidth;
    string text;
    void drawConstantText();
    
    //Tracker Functions
    Tracker kettle;
    bool kInteract;
    
    //UDP Functions
    ofxUDPManager udpConnection;
    
    //Sound
    ofSoundStream soundStream;
    
    //Variables
    vector <Slider> sliders;
    vector <Dial> dials;
    
    //Font
    ofTrueTypeFont big;
    ofTrueTypeFont little;
    
    //Images
    ofImage grainTexture;
};
