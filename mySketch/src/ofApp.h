// ofApp.h
#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp
{
public:
  void setup();
  void update();
  void draw();

  ofVideoGrabber grabber;

  ofxCv::ContourFinder contourFinder;

  ofParameter<ofColor> colorTarget;
  ofParameter<int> colorOffset;

  ofxPanel guiPanel;
};
