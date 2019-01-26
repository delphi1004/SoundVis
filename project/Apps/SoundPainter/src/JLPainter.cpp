//
//  JLPainter.cpp
//  SoundPainter
//
//  Created by jlsy on 26/01/2019.
//

#include "JLPainter.h"


// private method area ////////////////////////////////////////////////////////////////

// public method area ////////////////////////////////////////////////////////////////

JLPainter::JLPainter(int width,int height)
{
    sketchWidth = width;
    sketchHeight = height;
}

JLPainter::~JLPainter()
{
    ;
}

void JLPainter::setDefaultData()
{
    ;
}

void JLPainter::initDefaultData()
{
    ;
}

void JLPainter::setSoundFFT(float *fft, int size)
{
    soundFFT = fft;
    dataSize = size;
}

float *JLPainter::getSoundFFT()
{
    return soundFFT;
}

int JLPainter::getDataSize()
{
    return dataSize;
}

void JLPainter::stop()
{
    ;
}

void JLPainter::update()
{
    ;
}

void JLPainter::draw()
{
    ;
}
