//
//  JLGlitchedPainter.cpp
//  SoundPainter
//
//  Created by jlsy on 26/01/2019.
//

#include "JLGlitchedPainter.h"


// private method area ////////////////////////////////////////////////////////////////



// public method area ////////////////////////////////////////////////////////////////

JLGlitchedPainter::JLGlitchedPainter(int width,int height): JLPainter(width,height)
{
    ;
}

JLGlitchedPainter::~JLGlitchedPainter()
{
    ;
}

void JLGlitchedPainter::initDefaultData()
{
    soundFFT = getSoundFFT();
    dataSize = getDataSize();
    
    dataInterval = (ofGetScreenWidth() / (dataSize));
    
    dataInterval = 13 * 15;
    
    dataHeight = (dataInterval * 0.6);
    
    curPos.set(0,0);
}

void JLGlitchedPainter::update()
{
    ;
}

void JLGlitchedPainter::draw()
{
    ofColor targetColor;
    float soundData;
    
    for (int i=0;i<dataSize;i++)
    {
        soundData = getSoundFFT()[i];
        
        targetColor = ofColor::fromHsb(soundData,255,255);
        
        //ofDrawRectangle(curPos.x, curPos.y, dataInterval+soundData, dataHeight);
        
        ofSetColor(targetColor+50,100);
        
        ofDrawLine(curPos.x, curPos.y,curPos.x+(dataInterval+soundData),curPos.y);
        
        curPos.x += (dataInterval+soundData);
        
        //ofLog() << soundData;
    }
    
    curPos.x = 0;
    
    curPos.y += 1;//(dataHeight-1);
    
    if (curPos.y > sketchHeight)
    {
        curPos.y = 0;
    }
}


// event method area ////////////////////////////////////////////////////////////////
