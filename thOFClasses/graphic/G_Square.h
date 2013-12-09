/*
 *  G_Square.h
 *  particlesExample
 *
 *  Created by machine on 7/7/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#ifndef _G_SQUARE
#define _G_SQUARE

#include "G.h"

class G_Square : public G{
	
public:
	G_Square();
	
	virtual string toString();
	virtual string type();
	virtual void draw();
	virtual void setFillColor(ofColor color);
	virtual ofColor getFillColor();
	virtual int getCornerRadius();
	virtual void setCornerRadius(int value);
	
protected:
	ofColor fillColor;
	int cornerRadius;
};

#endif