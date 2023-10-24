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

  void mousePressed(int x, int y, int button);

  ofVideoGrabber grabber;
  ofImage processImg;

  ofxCv::ContourFinder contourFinder;

  ofParameter<ofColor> colorTarget;
  ofParameter<int> colorOffset;
  
  ofColor colorUnderMouse;

  ofParameter<float> minArea;
  ofParameter<float> maxArea;

  ofParameter<int> blurAmount;
  ofParameter<int> erodeIterations;

  ofParameter<int> persistence;
  ofParameter<float> maxDistance;

  ofParameter<bool> showLabels;
  ofParameter<bool> debugProcess;

  ofxPanel guiPanel;
};
