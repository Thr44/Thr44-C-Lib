/*
 *  Style.h
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G_STYLE
#define _G_STYLE

#pragma once
#import "Object.h"

class G_Style : public Object {
	
public:
	G_Style();
	virtual void setFillColor(ofColor color);
	virtual ofColor getFillColor();
	virtual void setLineColor(ofColor color);
	virtual ofColor getLineColor();
	virtual void setCornerRadius(int cornerRadius);
	int getCornerRadius();
	virtual G_Style* clone();
protected:
	ofColor fillColor;
	ofColor lineColor;
	int cornerRadius;
	
};

#endif
