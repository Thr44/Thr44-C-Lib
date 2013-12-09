/*
 *  FontStyle.h
 *  eventsExample
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _FONTSTYLE
#define _FONTSTYLE

#pragma once
#import "ofMain.h"
#import "Object.h"

class FontStyle : public Object {
	
public:
	FontStyle();
	virtual void setFontName(string fontName);
	virtual string getFontName();
	virtual void setFontSize(int fontSize);
	virtual int getFontSize();
	virtual void setFontColor(ofColor fontColor);
	virtual ofColor getFontColor();
	virtual FontStyle * clone();
	
protected:
	string fontName;
	int fontSize;
	ofColor fontColor;
	
	
};

#endif
