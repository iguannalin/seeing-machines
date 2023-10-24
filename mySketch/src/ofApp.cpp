// ofApp.cpp
#include "ofApp.h"

void ofApp::setup()
{
  ofSetWindowShape(640, 480);

  // Setup the grabber.
  grabber.setup(640, 480);

  // Setup the contour finder and parameters.
  contourFinder.setUseTargetColor(true);

  colorTarget.set("Color Target", ofColor(255, 0, 0));
  colorOffset.set("Color Offset", 10, 0, 255);

  // Setup the gui.
  guiPanel.setup("Color Tracker", "settings.json");
  guiPanel.add(colorTarget);
  guiPanel.add(colorOffset);
}

void ofApp::update()
{
  grabber.update();
  if (grabber.isFrameNew())
  {
    // Update parameters.
    contourFinder.setTargetColor(colorTarget);
    contourFinder.setThreshold(colorOffset);

    // Find contours.
    contourFinder.findContours(grabber);
  }
}

void ofApp::draw()
{
  ofSetColor(255);

  // Draw the grabber image.
  grabber.draw(0, 0, ofGetWidth(), ofGetHeight());

  // Draw the found contours.
  contourFinder.draw();

  // Draw the gui.
  guiPanel.draw();
}
