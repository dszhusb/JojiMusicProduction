#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Render Settings
    ofEnableSmoothing();
    ofSetCircleResolution(20);
    ofSetLineWidth(5);
    ofSetBackgroundColor(0);
    
    //Interaction Defaults
    actRange = 40;
    
    //Kettle Setup
    kettle.setup();
    
    srand((unsigned) time(NULL));
    
    //Slider Setup
    for (int i = 0; i < 2; i++) {
        Slider s;
        float rX = static_cast<float>(rand() % 100) /100 * ofGetWidth();
        float rY = static_cast<float>(rand() % 100) /100 * ofGetHeight();
        s.setup(rX, rY, 0);
        sliders.push_back(s);
    }
    
    //Dials
    for (int i = 0; i < 2; i++) {
        Dial d;
        float rX = static_cast<float>(rand() % 100) /100 * ofGetWidth();
        float rY = static_cast<float>(rand() % 100) /100 * ofGetHeight();
        d.setup(rX, rY, 0);
        dials.push_back(d);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    kettle.update();
    
    for(int i=0; i<sliders.size(); i++) {
        sliders[i].update();
    }
    
    for(int i=0; i<dials.size(); i++) {
        dials[i].update();
    }
    
    trackerInteractions();
}

void ofApp::trackerInteractions() {
    if (kettle.kInteract) {
        for (int i=0; i<sliders.size(); i++) {
            vector<float> target = sliders[i].calcDisp();
            if (inRange(target[2] + sliders[i].x, target[3] + sliders[i].y)) {
                float per = sliders[i].calcSliderMov(mouseX, mouseY, sliders[i].percentage);
                sliders[i].updatePercentage(per);
            }
        }
        
        for (int i=0; i<dials.size(); i++) {
            vector<float> target = dials[i].getLocation();
            if (inRange(target[0], target[1])) {
                cout << kettle.rotation << endl;
                dials[i].updatePercentage(kettle.rotation);
            }
        }
    }
}

bool ofApp::inRange(float tx, float ty) {
    bool in = false;
    float dist = sqrt(pow(tx-kettle.x, 2) + pow(ty-kettle.y, 2));
    if (dist < actRange) {
        in = true;
    }
    return in;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<sliders.size(); i++) {
        sliders[i].draw();
    }
    for(int i=0; i<dials.size(); i++) {
        dials[i].draw();
    }
    
    kettle.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'e') {
        kettle.toggleKInteract();
    } else if (key == 'r') {
        kettle.rotateGradually();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    kettle.updateOrientation(x,y,0);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    kettle.toggleMobile();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
