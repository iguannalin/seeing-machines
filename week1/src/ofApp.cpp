#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int values[30][40];
    int gridSize = 10;
    ofSetWindowShape(30, 40);
    for (int y = 0; y < 30; y++)  // rows
    {
      for (int x = 0; x < 40; x++)  // columns
      {
        if (values[x][y])
        {
          ofSetColor(255);
        }
        else
        {
          ofSetColor(0);
        }
        ofDrawRectangle(x * gridSize, y * gridSize, gridSize, gridSize);
      }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int values[30][40];
    int gridSize = 10;
    ofSetWindowShape(300, 400);
    for (int y = 0; y < 30; y++)  // rows
    {
      for (int x = 0; x < 40; x++)  // columns
      {
        if (values[x][y])
        {
          ofSetColor(255);
        }
        else
        {
          ofSetColor(0);
        }
        ofDrawRectangle(x * gridSize, y * gridSize, gridSize, gridSize);
      }
    }
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
