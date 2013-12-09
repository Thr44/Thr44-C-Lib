/*
 *  GeometryUtils.h
 *
 *  Created by machine on 8/26/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _GEOMETRYUTILS
#define _GEOMETRYUTILS

#pragma once
#include "ofMain.h"
#include "G.h"
#include "Settings.h"

class GeometryUtils {
public:
	static void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY);
	//???: think about moving it to GStyle
	static void drawRoundRect(float x, float y, float width, float height, float cornerRadius);
	static void drawArc(float x,float y, float radius, float lowAngle, float highAngle, bool closed, bool filled);
	//TODO: move to G
	#ifdef IPHONE
	//static bool hitTest(G * object, ofTouchEventArgs & touch);
	static bool hitTest(float x, float y, float w, float h, ofTouchEventArgs & touch);
	static bool hitTest(float x, float y, float radius, ofTouchEventArgs & touch);
	#else
	//static bool hitTest(G * object, ofMouseEventArgs & mouse);
	static bool hitTest(float x, float y, float w, float h, ofMouseEventArgs & mouse);
	static bool hitTest(float x, float y, float radius, ofMouseEventArgs & mouse);
	#endif
	static bool hitTest(float x, float y, float w, float h, float hitX, float hitY);
	static bool hitTest(float x, float y, float radius, float hitX, float hitY);
	
};

#endif