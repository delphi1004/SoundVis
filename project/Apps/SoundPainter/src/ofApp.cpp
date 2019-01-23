#include "ofApp.h"


// private method area ////////////////////////////////////////////////////////////////

void ofApp::initDefaultData()
{
    maxBand = 128;
    
    mySound.setup(maxBand);
    
    mySound.play();
}





// public method area ////////////////////////////////////////////////////////////////




//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
    
    ofSetBackgroundColor(30,30,30);
    
    ofSetColor(255, 255, 255,10);
    
    ofSetBackgroundAuto(false);
    
    ofSetLineWidth(0.1);
    
    ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    
    initDefaultData();
}

//--------------------------------------------------------------
void ofApp::update()
{
    mySound.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    float x1,y1,x2,y2;
    
    x1 = ofRandom(ofGetScreenWidth());
    y1 = ofRandom(ofGetScreenHeight());
    
    x2 = ofRandom(ofGetScreenWidth()/2);
    y2 = ofRandom(ofGetScreenHeight()/2);
    
    ofDrawLine(x1, y1, x2, y2);
}


// event method area ////////////////////////////////////////////////////////////////


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    ofEndSaveScreenAsPDF();
    
    ofLog() << "Data saved!";
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
