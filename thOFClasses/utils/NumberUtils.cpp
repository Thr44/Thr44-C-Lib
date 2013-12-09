/*
 *  NumberUtils.cpp
 *  SCPad
 *
 *  Created by machine on 7/20/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "NumberUtils.h"


float NumberUtils::getInterpolatedValue(float min, float max, float value){
	if(value<0 && value >1) throw 0;
	return value*(max-min) + min;
}