#pragma once

#include "ofMain.h"
#include "JLSound.h"
#include "JLGlitchedPainter.h"
#include "JLEllipsedPainter.h"

// private property area ////////////////////////////////////////////////////////////////

// public property area ////////////////////////////////////////////////////////////////

// private method area ////////////////////////////////////////////////////////////////

// public method area ////////////////////////////////////////////////////////////////


// event method area ////////////////////////////////////////////////////////////////

class ofApp : public ofBaseApp
{
    // private property area ////////////////////////////////////////////////////////////////
    
    JLSound mySound;
    JLPainter *myPainter;
    
    int maxBand;
    bool shouldSave;
    
    ofFbo mySketch;
    
    int sketchWidth;
    int sketchHeight;
    
    
    // public property area ////////////////////////////////////////////////////////////////
    
    
    
    
    // private method area ////////////////////////////////////////////////////////////////
    
private:
    
    void initDefaultData();
    void captureScreen();
    
    // public method area ////////////////////////////////////////////////////////////////
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
