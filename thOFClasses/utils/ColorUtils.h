/*
 *  ColorUtils.h
 *  exampleTree
 *
 *  Created by machine on 10/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _COLORUTILS
#define _COLORUTILS

#pragma once
#include "ofMain.h"

class ColorUtils {
public:
	/**
	 generate a random color
	 \return a random color
	 * 
	 */
	static ofColor randomColor();
    static ofColor randomColor(float alpha);
	/**
	 generate an RGB color 
	 \return  an RGB color 
	 */
	static ofColor RGB(float red, float green, float blue);
	/**
	 generate an RGBA color 
	 \return  an RGBA color 
	 */
	static ofColor RGB(float red, float green, float blue, float alpha);
	/**
	 generate an HSV color
	 \param hue [0 - 360] 
	 \param saturation [0 - 1]
	 \param value [0 - 1] value / luminance
	 \return an HSV color
	 * 
	 */
	static ofColor HSV(float hue, float saturation, float value);
	/**
	 generate an HSVA color
	 \param hue [0 - 360] 
	 \param saturation [0 - 1]
	 \param value [0 - 1] value / luminance
	 \param alpha [0-255] alpha value
	 \return an HSVA color
	 * 
	 */
	static ofColor HSV(float hue, float saturation, float value, float alpha);
	static ofColor getInterpolatedColor(ofColor &color0, ofColor &color1, float value);
	static ofColor black();
	static ofColor white();
	
};

#endif