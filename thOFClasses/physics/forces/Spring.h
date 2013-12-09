/*
 *  Spring.h
 *  SCPad
 *
 *  Created by machine on 7/6/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#ifndef _SPRING
#define _SPRING

#pragma once

#include "ofMain.h"
#include "Force.h"

class Spring : public Force{
	
public:
	Spring(G* node0, G* node1, float k, float length);
	
	G* node1;
	float k;
	float length;
	
	virtual string toString();
	virtual string type();
	
	virtual void calculate();
};

#endif