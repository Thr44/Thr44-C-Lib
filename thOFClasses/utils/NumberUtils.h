/*
 *  NumberUtils.h
 *  SCPad
 *
 *  Created by machine on 7/20/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */


#ifndef _NUMBERUTILS
#define _NUMBERUTILS

#pragma once
//#include "ofMain.h"

class NumberUtils {
public:
	/**
	 * return a value between min and max
	 * 0 -> min
	 * 1 -> max
	 * \param min
	 * \param max
	 * \param value between 0 and 1 (to obtain values between min and max)
	 * \return the interpolated value
	 * 
	 */
	static float getInterpolatedValue(float val0, float val1, float value);
		
};

#endif