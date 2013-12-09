/*
 *  Repulsor.h
 *  particlesExample
 *
 *  Created by machine on 7/8/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#ifndef _REPULSOR
#define _REPULSOR

#pragma once

#include "ofMain.h"
#include "Force.h"

class Repulsor : public Force{
	
public:
	Repulsor(G* node0, G* node1, float k, float length);
	
	G* node1;
	float k;
	float length;
	
	virtual string toString();
	virtual string type();
	
	virtual void calculate();
};

#endif