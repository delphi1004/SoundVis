#include "ofApp.h"


// private method area ////////////////////////////////////////////////////////////////

void ofApp::initDefaultData()
{
    maxBand = 128;
    
    mySketch.allocate(sketchWidth,sketchHeight);
    
    mySketch.begin();
    
    ofClear(0,0,0,255);
    
    ofSetColor(255, 255, 255);
    
    ofDrawRectangle(0, 0, sketchWidth, sketchHeight);
    
    mySketch.end();
    
    myPainter = new JLGlitchedPainter(sketchWidth,sketchHeight);
    //myPainter = new JLEllipsedPainter(sketchWidth,sketchHeight);

    mySound.setup(maxBand);
    
    mySound.play();
    
    myPainter->setSoundFFT(mySound.getFFT(),maxBand);
    myPainter->initDefaultData();
}

void ofApp::captureScreen()
{
    ofImage image;
    ofPixels pixels;
    
    pixels.allocate(sketchWidth,sketchHeight, 4);
        
    mySketch.readToPixels(pixels);
    
    ofSaveImage(pixels, "ShapeOfMyHeart-"+ofGetTimestampString()+".jpg", OF_IMAGE_QUALITY_BEST);
}



// public method area ////////////////////////////////////////////////////////////////



//--------------------------------------------------------------

void ofApp::setup()
{
    //sketchWidth = 3508;
    //sketchHeight= 4961;
    
    sketchWidth = 768;
    sketchHeight= 1024;
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
   // ofSetWindowShape(sketchWidth,sketchHeight);
    
    ofSetBackgroundColor(255,255,255,255);
    
    ofSetColor(255,255,255,255);
    
    //ofSetBackgroundAuto(false);
    
    ofSetLineWidth(0.1);
    
    ofSetCircleResolution(50);
    
    ofSetFrameRate(2);
    
    initDefaultData();
}

//--------------------------------------------------------------

void ofApp::update()
{
    for (int i=0;i<1;i++)
    {
        mySound.update();
        myPainter->update();
        
        mySketch.begin();
        
        myPainter->drawBox();
        
        mySketch.end();
    }
    
    if (shouldSave == true)
    {
        captureScreen();
        
        shouldSave = false;
        
        ofLog() << "Data saved!";
        
        ofExit();
    }
}

//--------------------------------------------------------------

void ofApp::draw()
{
    //mySketch.draw(0,0);
    
    mySketch.draw(0,0);
    
    //myPainter->drawCurve();
}


// event method area ////////////////////////////////////////////////////////////////


//--------------------------------------------------------------

void ofApp::keyPressed(int key)
{
    ;
}

//--------------------------------------------------------------

void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------

void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    shouldSave = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
