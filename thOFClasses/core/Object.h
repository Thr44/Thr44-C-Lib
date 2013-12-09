/*
 *  Object.h
 *  eventsExample
 *
 *  Created by machine on 8/14/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _OBJECT
#define _OBJECT

#pragma once //FIXME: remover pragmas!
#include "ofMain.h" //FIXME: deveria tirar e colocar onde é necessario!!!!

class Object {
private:
	
public:
	Object();
	~Object();
	virtual string toString();
	virtual string type();
	static int someNumber;
	static string sortType;
};

#endif