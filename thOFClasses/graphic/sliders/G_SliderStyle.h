/*
 *  G_SliderStyle.h
 *  SCPad
 *
 *  Created by machine on 9/20/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G_SLIDERSTYLE
#define _G_SLIDERSTYLE

#pragma once
#import "G_Style.h"
#import "ofMain.h"



class G_SliderStyle : public G_Style {
	
public:
	G_SliderStyle();
	virtual void setThumbFillColor(ofColor color);
	virtual ofColor getThumbFillColor();
	virtual void setThumbLineColor(ofColor color);
	virtual ofColor getThumbLineColor();
	virtual void setScrollTrackFillColor(ofColor color);
	virtual ofColor getScrollTrackFillColor();
	virtual void setScrollTrackLineColor(ofColor color);
	virtual ofColor getScrollTrackLineColor();
	virtual G_SliderStyle* clone();
	
	
protected:
	ofColor thumbFillColor;
	ofColor thumbLineColor;
	ofColor scrollTrackFillColor;
	ofColor scrollTrackLineColor;
	int cornerRadius;
};

#endif
