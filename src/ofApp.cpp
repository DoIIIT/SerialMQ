#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // serialConnection = ofYJArduinoSerial();
    serialConnection.connect(); 

    for (int i = 0; i < 3; i++) {
        char numstr[6];
        sprintf(numstr, "cmd%d", i);
        cmdList.push_back(numstr);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    serialConnection.getMsgs(); 

    
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'p') {
        static int counter = 0;
        if (serialConnection.getCounter("cmd1") != counter) {
            counter = serialConnection.getCounter("cmd1");
            for (std::vector<std::string>::iterator it = cmdList.begin(); it != cmdList.end(); it++) {
                std::string cmd = *it;
                std::cout << cmd << ":" << serialConnection.getValue(cmd) << std::endl;
            }
        }
    }

    if (key == 's') {
        serialConnection.sendMsg("led LOW\n");
    }

    if (key == 'd') {
        serialConnection.sendMsg("led HIGH\n");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
