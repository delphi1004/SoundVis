//
//  JLEllipsePainter.cpp
//  SoundPainter
//
//  Created by jlsy on 27/01/2019.
//

#include "JLEllipsedPainter.h"

// private method area ////////////////////////////////////////////////////////////////



// public method area ////////////////////////////////////////////////////////////////

JLEllipsedPainter::JLEllipsedPainter(int width,int height): JLPainter(width,height)
{
    ;
}

JLEllipsedPainter::~JLEllipsedPainter()
{
    ;
}

void JLEllipsedPainter::initDefaultData()
{
    float angle;
    
    soundFFT = getSoundFFT();
    dataSize = getDataSize();
    
    curPos.x = (sketchWidth/2);
    curPos.y = (sketchHeight/2);
    
    orgAnchorPos = new ofVec2f[dataSize];
    curAnchorPos = new ofVec2f[dataSize];
    
    angle = ofDegToRad(360/float(dataSize));
    
    for (int i=0; i<dataSize; i++)
    {
        ofLog() <<orgAnchorPos[i];
    }
    
    for (int i=0; i<dataSize; i++)
    {
        orgAnchorPos[i].x = cos(angle*i) * RADIOUS;
        orgAnchorPos[i].y = sin(angle*i) * RADIOUS;
    }
}

void JLEllipsedPainter::update()
{
    ;
}

void JLEllipsedPainter::drawElipse()
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
    
    ofSetColor(0,0,0,50);
    
    sum *= 50;
    
    ofNoFill();
    
    ofSetLineWidth(0.1);
    
    ofDrawEllipse(sketchWidth/2,sketchHeight/2,sum,sum);
}

void JLEllipsedPainter::drawCurve()
{
    int posX,posY;
    float curSound;
    
    ofNoFill();
    
    ofSetLineWidth(0.1);
    
    ofSetColor(0,0,0,10);
    
    for (int i=0; i<dataSize; i++)
    {
        curSound = getSoundFFT()[i];
        
        ofDrawEllipse(curPos.x + orgAnchorPos[i].x, curPos.y + orgAnchorPos[i].y, 10, 10);
        
        curAnchorPos[i].x = (curPos.x + (orgAnchorPos[i].x+ofRandom(-curSound,curSound)));
        curAnchorPos[i].y = (curPos.y + (orgAnchorPos[i].y+ofRandom(-curSound,curSound)));
    }
    
    
    painter.begin();
    
    //painter.clear();
    
    painter.curveTo(curAnchorPos[dataSize-1].x,curAnchorPos[dataSize-1].y);
    
    for (int i=0; i<dataSize; i++)
    {
        painter.curveTo(curAnchorPos[i].x,curAnchorPos[i].y);
    }
    
    painter.curveTo(curAnchorPos[0].x,curAnchorPos[0].y);
    painter.curveTo(curAnchorPos[1].x,curAnchorPos[1].y);
    
    painter.close();
    
    painter.draw();
}

