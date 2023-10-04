#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
	cam.setup(640, 480);
    
    gui.setup();
    gui.add(resetBackground.set("Reset Background", false));
    gui.add(learningTime.set("Learning Time", 30, 0, 30));
    gui.add(thresholdValue.set("Threshold Value", 10, 0, 255));
}

void ofApp::update() {
	cam.update();
    ofSetFrameRate(60);
    if(resetBackground) {
        background.reset();
        resetBackground = false;
    }
	if(cam.isFrameNew()) {
        background.setLearningTime(learningTime);
        background.setThresholdValue(thresholdValue);
		background.update(cam, thresholded);
        
        thresholded.update();
	}
}

void ofApp::draw() {
    // Cache the image dimensions in variables for easy access.
    int imgWidth = thresholded.getWidth();
    int imgHeight = thresholded.getHeight();
    ofPixels thresholdedPixels = thresholded.getPixels();
    ofColor grabColor = thresholdedPixels.getColor(mouseX, mouseY);
    
    for (int y = 0; y < imgWidth; y+=5)
    {
        for (int x = 0; x < imgHeight; x+=5)
        {
            ofColor grabColor = thresholdedPixels.getColor(x, y);
            float brightness = grabColor.getBrightness();
            if (brightness < 200) // dark
            {
                ofDrawBitmapString("@", x, y);
            }
            else
            {
                ofDrawBitmapString("-", x, y);
            }
        }
    }
}
