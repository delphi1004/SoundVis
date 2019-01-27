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
    
    //dataInterval = 13 * 15; // for draw();
    
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
        
        ofSetColor(targetColor+50,30);
        
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

void JLGlitchedPainter::drawBox()
{
    ofColor targetColor;
    float soundData;
    float clampedData;
    
    for (int i=0;i<dataSize;i++)
    {
        soundData = getSoundFFT()[i];
        
        clampedData = ofClamp(soundData,-10,5);
        
        targetColor = ofColor::fromHsb(soundData+150,255,255);
        
        ofSetColor(targetColor,clampedData+ (i));
        
        //ofDrawRectangle(curPos.x, curPos.y, dataInterval, soundData);
        
        //ofDrawRectangle(curPos.x, curPos.y, dataInterval,-soundData);
        
        ofDrawEllipse(curPos.x, curPos.y, soundData, soundData);
        
        curPos.x += (dataInterval+5);
        
        //ofLog() << soundData;
    }
    
    curPos.x = 0;
    
    curPos.y += 20;
    
    if (curPos.y > sketchHeight)
    {
        curPos.y = 0;
    }
    
}

void JLGlitchedPainter::drawElipse()
{
    ofColor targetColor;
    float soundData;
    float clampedData;
    float sum;
    
    sum = 0;
    
    for (int i=0;i<dataSize;i++)
    {
        sum += getSoundFFT()[i];
    }
    
    sum /= dataSize;
    
    targetColor = ofColor::fromHsb(sum+150,255,255);
    
    ofSetColor(targetColor,1);
    
    sum *= 50;
    
    ofNoFill();
    
    ofSetLineWidth(0.1);
    
    ofDrawEllipse(sketchWidth/2,sketchHeight/2,sum,sum);
    
}


// event method area ////////////////////////////////////////////////////////////////
