#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //udp setup
    ofxUDPSettings settings;
    settings.receiveOn("192.168.0.15", 11999);
    settings.blocking = false;
    
    ofxUDPManager udpConnection;
    udpConnection.Setup(settings);
    
    //Render Settings
    ofEnableSmoothing();
    ofSetCircleResolution(20);
    ofSetLineWidth(5);
    ofSetBackgroundColor(10,8,18);
    
    //Interaction Defaults
    actRange = 40;
    
    //Kettle Setup
    kettle.setup();
    
    //Slider Setup
    srand((unsigned) time(NULL));
    
    for (int i = 0; i < 2; i++) {
        Slider s;
        float rX = static_cast<float>(rand() % 100) /100 * ofGetWidth();
        float rY = static_cast<float>(rand() % 100) /100 * ofGetHeight();
        s.setup(rX, rY, 0);
        sliders.push_back(s);
    }
    
    //Dials
    for (int i = 0; i < 1; i++) {
        Dial d;
        float rX = static_cast<float>(rand() % 100) /100 * ofGetWidth();
        float rY = static_cast<float>(rand() % 100) /100 * ofGetHeight();
        d.setup(rX, rY, 0);
        dials.push_back(d);
    }
    
    //Font
    margin = 30;
    colWidth = 64;
    gutter = 20;
    big.load("Univers-light-normal.ttf", 16 * 0.75);
    little.load("Univers-light-normal.ttf", 6 * 0.75);
    
    //Load Images
    grainTexture.load("grainTexture.png");
    grainTexture.resize(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    //UDP
    char udpMessage[1000];
    udpConnection.Receive(udpMessage,1000);
    string message = udpMessage;
//    std::cout << message << endl;
    
    //Interactions
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
//                cout << kettle.rotation << endl;
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
    
    drawConstantText();
    
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 255*0.225);
    grainTexture.draw(0,0);
    ofDisableAlphaBlending();
}

void ofApp::drawConstantText() {
    
    float block = (2 * colWidth + gutter);
    
    //Blockers
    ofSetColor(10,8,18);
    ofDrawRectangle(margin,0,margin+block+gutter+block,64);
    ofDrawRectangle(margin,494,margin+block+gutter+block,64);
    
    //Text
    ofSetColor(255);
    text = "SAMPLES";
    float xDisp = margin;
    big.drawString(text, xDisp + block/2 - big.stringWidth(text)/2, 20 + big.stringHeight(text));
    
    text = "EDITED SOUNDS";
    xDisp += block + gutter;
    big.drawString(text, xDisp + block/2 - big.stringWidth(text)/2, 20 + big.stringHeight(text));
    
    //Lines
    ofSetLineWidth(2);
    ofDrawLine(margin,64,margin + block,64);
    ofDrawLine(xDisp,64,xDisp + block,64);
    ofDrawLine(margin,494,margin + block,494);
    ofDrawLine(xDisp,494,xDisp + block,494);
    
    ofDrawLine(0,630,ofGetWidth(),630);
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
