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
  minArea.set("Min Area", 0.01f, 0, 0.5f);
  maxArea.set("Max Area", 0.05f, 0, 0.5f);
  blurAmount.set("Blur Amount", 0, 0, 100);
  erodeIterations.set("Erode Iterations", 0, 0, 10);
  persistence.set("Persistence", 15, 0, 60);
  maxDistance.set("Max Distance", 64, 0, 640);
  showLabels.set("Show Labels", false);
  debugProcess.set("Debug Process", false);

  // Setup the gui.
  guiPanel.setup("Color Tracker", "settings.json");
  guiPanel.add(colorTarget);
  guiPanel.add(colorOffset);
  guiPanel.add(minArea);
  guiPanel.add(maxArea);
  guiPanel.add(blurAmount);
  guiPanel.add(erodeIterations);
  guiPanel.add(persistence);
  guiPanel.add(maxDistance);
  guiPanel.add(showLabels);
  guiPanel.add(debugProcess);
}

void ofApp::update()
{
  grabber.update();
  if (grabber.isFrameNew())
  {
    processImg.setFromPixels(grabber.getPixels());

    // Filter the image.
    if (blurAmount > 0)
    {
      //ofxCv::blur(processImg, blurAmount);
      //ofxCv::GaussianBlur(processImg, blurAmount);
      ofxCv::medianBlur(processImg, blurAmount);
    }
    if (erodeIterations > 0)
    {
      ofxCv::erode(processImg, erodeIterations.get());
    }
    processImg.update();

    // Save the color of the pixel under the mouse.
    colorUnderMouse = processImg.getColor(ofGetMouseX(), ofGetMouseY());

    // Update parameters.
    contourFinder.setTargetColor(colorTarget, ofxCv::TRACK_COLOR_HSV);
    contourFinder.setThreshold(colorOffset);
    contourFinder.setMinAreaNorm(minArea);
    contourFinder.setMaxAreaNorm(maxArea);
    contourFinder.getTracker().setPersistence(persistence);
    contourFinder.getTracker().setMaximumDistance(maxDistance);

    // Find contours.
    contourFinder.findContours(processImg);
  }
}

void ofApp::draw()
{
  ofSetColor(255);

  if (debugProcess)
  {
    // Draw the process image.
    processImg.draw(0, 0, ofGetWidth(), ofGetHeight());
  }
  else
  {
    // Draw the grabber image.
    grabber.draw(0, 0, ofGetWidth(), ofGetHeight());
  }

  // Draw the found contours.
  contourFinder.draw();

  if (showLabels)
  {
    ofxCv::RectTracker& tracker = contourFinder.getTracker();

    ofSetColor(255);
    for (int i = 0; i < contourFinder.size(); i++)
    {
      ofPoint center = ofxCv::toOf(contourFinder.getCenter(i));
      int label = contourFinder.getLabel(i);
      string msg = ofToString(label) + ":" + ofToString(tracker.getAge(label));
      ofDrawBitmapString(msg, center.x, center.y);
      ofVec2f velocity = ofxCv::toOf(contourFinder.getVelocity(i));
      ofDrawLine(center.x, center.y, center.x + velocity.x, center.y + velocity.y);
    }
  }

  // Draw the color under the mouse.
  ofPushStyle();
  ofSetColor(colorUnderMouse);
  ofDrawRectangle(ofGetMouseX() - 25, ofGetMouseY() - 25, 50, 50);
  ofNoFill();
  ofSetColor(colorUnderMouse.getInverted());
  ofDrawRectangle(ofGetMouseX() - 25, ofGetMouseY() - 25, 50, 50);
  ofPopStyle();

  // Draw the gui.
  guiPanel.draw();
}

void ofApp::mousePressed(int x, int y, int button)
{
  if (!guiPanel.getShape().inside(x, y))
  {
    // Track the color under the mouse.
    colorTarget = colorUnderMouse;
  }
}
