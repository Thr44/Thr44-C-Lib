/*
 *  ThEvent.h
 *  exampleTree
 *
 *  Created by machine on 10/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _THEVENT
#define _THEVENT

#include "ofMain.h" //FIXME: deveria tirar e colocar onde é necessario!!!!

//typedef void (*functionType)();

class ThEvent {
public:
	ThEvent(int eventType, bool stopPropagation);
	//functionType onDispatchFunc;
	bool stopPropagation;
	int eventType;
	virtual string toString();
	virtual string type();

	
#ifdef IPHONE
	
	static const int TOUCH_DOWN=0;
	static const int TOUCH_MOVED=1;
	static const int TOUCH_UP=2;
	static const int TOUCH_DOUBLE_TAP=3;
	static const int ORIENTATION_CHANGED=4;
	
#else

	static const int KEY_PRESSED=0;
	static const int KEY_RELEASED=1;
	static const int MOUSE_MOVED=2;
	static const int MOUSE_DRAGGED=3;
	static const int MOUSE_PRESSED=4;
	static const int MOUSE_RELEASED=5;
	static const int WINDOW_RESIZED=6;
	
#endif
};

#endif