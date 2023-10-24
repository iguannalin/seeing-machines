// ofApp.cpp
#include "ofApp.h"

void ofApp::setup()
{
  grabber.setup(1280, 720);
  resultImg.allocate(1280, 720, OF_IMAGE_COLOR);
}

void ofApp::update()
{
  grabber.update();

  // Use a reference to the ofPixels in both the grabber and the image.
  ofPixels& grabberPix = grabber.getPixels();
  ofPixels& resultPix = resultImg .getPixels();
  for (int y = 0; y < grabberPix.getHeight(); y++)
  {
    for (int x = 0; x < grabberPix.getWidth(); x++)
    {
      ofColor pixColor = grabberPix.getColor(x, y);
//        int gray = (pixColor.r + pixColor.g + pixColor.b)/3;
        unsigned char gray = 0.21 * pixColor.r + 0.71 * pixColor.g + 0.07 * pixColor.b;
      resultPix.setColor(x, y, gray);
    }
  }

  // Update the internal texture (GPU) with the new pixel data.
  resultImg.update();
}

void ofApp::draw()
{
  resultImg.draw(0, 0, ofGetWidth(), ofGetHeight());
}
