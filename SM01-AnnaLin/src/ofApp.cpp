#include "ofApp.h"
ofImage image;
bool paused = false;
int clicks = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    // allocate some memory for an image
    image.allocate(100, 100, OF_IMAGE_GRAYSCALE);
    ofSetWindowShape(300, 300);
    for (int y = 0; y < image.getHeight(); ++y)
    {
        for (int x = 0; x < image.getWidth(); ++x)
        {
            // init with 50% live cells, 50% dead cells
            if (ofRandomuf() > 0.5)
            {
                image.setColor(x, y, ofColor::black);
            }
            else
            {
                image.setColor(x, y, ofColor::white);
            }
        }
    }
    // update the ofTexture in image with its ofPixels
    image.update();
}

//--------------------------------------------------------------
// every frame iterates upon the previous frame/generation of cells
// meaning when checking for neighbors always check the neighbor's state from the previous frame and not the latest updated state
int ofApp::getLiveNeighbors(int x, int y) {
    int n = 0;
    ofColor alive = ofColor::white;
    if (x-1 && y-1 && image.getColor(x-1,y-1) == alive) // top-left
    {
        ++n;
    }
    if (x && y-1 && image.getColor(x,y-1) == alive) // top-center
    {
        ++n;
    }
    if (x+1 && y-1 && image.getColor(x+1,y-1) == alive) // top-right
    {
        ++n;
    }
    if (x-1 && y && image.getColor(x-1,y) == alive) // middle-left
    {
        ++n;
    }
    if (x+1 && y && image.getColor(x+1,y) == alive) // middle-right
    {
        ++n;
    }
    if (x-1 && y+1 && image.getColor(x-1,y+1) == alive) // bottom-left
    {
        ++n;
    }
    if (x && y+1 && image.getColor(x,y+1) == alive) // bottom-center
    {
        ++n;
    }
    if (x+1 && y+1 && image.getColor(x+1,y+1) == alive) // bottom-right
    {
        ++n;
    }
//    cout << x << ", " << y << "\t";
//    cout << "has " << n << " live neighbors" << endl;
    return n;
}
//Isolation: a live ⬜ cell with less than 2 live neighbors will die 😥.
//Overcrowding: a live ⬜ cell with 4 or more neighbors will die 😵.
//Reproduction: a dead ⬛ cell with exactly 3 live neighbors will live 🐣.
void ofApp::update(){
    if (paused) return;
    ofPixels latest = image.getPixels();
    for (int y = 0; y < image.getHeight(); y++)
    {
      for (int x = 0; x < image.getWidth(); x++)
      {
          ofColor color = image.getColor(x, y);
          if (color == ofColor::white) // live cell
          {
              int alive = getLiveNeighbors(x, y);
              if (alive < 2)
              {
                  latest.setColor(x, y, ofColor::black);
              } else if (alive >= 4) {
                  latest.setColor(x, y, ofColor::black);
              }
          } else // dead cell
          {
              if (getLiveNeighbors(x, y) == 3)
              {
                  latest.setColor(x, y, ofColor::white);
              }
        }
      }
    }
    image.setFromPixels(latest);
}

//--------------------------------------------------------------
void ofApp::draw(){
    // upscale image for easy viewing
    image.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    image.draw(0, 0, 300, 300);
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
    if (paused)
    {
        clicks++;
    }
    if (clicks >= 2) // double-click
    {
        clicks = 0;
        setup();
    }
    paused = !paused;
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
