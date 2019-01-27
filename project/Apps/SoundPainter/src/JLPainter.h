//
//  JLPainter.hpp
//  SoundPainter
//
//  Created by jlsy on 26/01/2019.
//

#ifndef JLPainter_hpp
#define JLPainter_hpp

#include <stdio.h>


// private property area ////////////////////////////////////////////////////////////////

// public property area ////////////////////////////////////////////////////////////////

// private method area ////////////////////////////////////////////////////////////////

// public method area ////////////////////////////////////////////////////////////////


// event method area ////////////////////////////////////////////////////////////////




class JLPainter
{
    
    // private property area /////////////////////////////////////////////////////////////
    
private:
    
    float *soundFFT;
    int dataSize;
    
    
    // public property area //////////////////////////////////////////////////////////////
public:
    
    int sketchWidth;
    int sketchHeight;
    
    // private method area ///////////////////////////////////////////////////////////////
    
    // public method area ////////////////////////////////////////////////////////////////
    
public:
    
    JLPainter(int width,int height);
    ~JLPainter();
    
    float *getSoundFFT();
    int getDataSize();
    
    void setSoundFFT(float *fft, int size);

    virtual void initDefaultData();
    virtual void setDefaultData();
    virtual void update();
    virtual void draw();
    virtual void drawBox();
    virtual void drawElipse();
    virtual void drawCurve();
    virtual void stop();
    
};

#endif /* JLPainter_hpp */
