//
//  JLEllipsePainter.hpp
//  SoundPainter
//
//  Created by jlsy on 27/01/2019.
//

#ifndef JLEllipsePainter_hpp
#define JLEllipsePainter_hpp

#include <stdio.h>
#include "ofMain.h"
#include "JLPainter.h"

#define ANCHOR_COUNT 30
#define RADIOUS 300

class JLEllipsedPainter : public JLPainter
{
    
    // private property area //////////////////////////////////////////////////////////////
    
private:
    
    float *soundFFT;
    int dataSize;

    ofVec2f *orgAnchorPos;
    ofVec2f *curAnchorPos;
    ofVec2f curPos;
    ofPolyline painter;
    
    // public property area ///////////////////////////////////////////////////////////////
    
    // private method area ////////////////////////////////////////////////////////////////
    
private:
    
    
    
    
    // public method area ////////////////////////////////////////////////////////////////
    
public:
    
    JLEllipsedPainter(int width,int height);
    ~JLEllipsedPainter();
    
    void initDefaultData();
    void update();
    void drawElipse();
    void drawCurve();
    
};


#endif /* JLEllipsePainter_hpp */
