//
//  JLGlitchedPainter.hpp
//  SoundPainter
//
//  Created by jlsy on 26/01/2019.
//

#ifndef JLGlitchedPainter_hpp
#define JLGlitchedPainter_hpp

#include <stdio.h>
#include "ofMain.h"
#include "JLPainter.h"


class JLGlitchedPainter : public JLPainter
{

// private property area //////////////////////////////////////////////////////////////

private:
    
    float *soundFFT;
    float dataInterval;
    int dataSize;
    int dataHeight;
    
    ofVec2f curPos;
    
// public property area ///////////////////////////////////////////////////////////////

// private method area ////////////////////////////////////////////////////////////////

private:
    
    
    
    
// public method area ////////////////////////////////////////////////////////////////
    
public:
    
    JLGlitchedPainter(int width,int height);
    ~JLGlitchedPainter();
    
    void initDefaultData();
    void update();
    void draw();
    
};





#endif /* JLGlitchedPainter_hpp */
