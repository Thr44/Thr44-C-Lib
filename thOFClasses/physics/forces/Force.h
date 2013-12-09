/*
 *  Force.h
 *  SCPad
 *
 *  Created by machine on 1/31/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */
#ifndef _FORCE
#define _FORCE

#pragma once

#include "ofMain.h"
#include "Object.h"
#include "G.h"

class Force : public Object{
	
public:
	//Force(G* node);
	Force(G* node0, G* node1);
	G* node0;
	G* node1;
	
	virtual string toString();
	virtual string type();
	
	virtual void calculate();
};

#endif