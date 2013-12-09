/*
 *  G_SliderStyle.cpp
 *  SCPad
 *
 *  Created by machine on 9/20/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_SliderStyle.h"

G_SliderStyle::G_SliderStyle(){
	thumbFillColor.r=0;
	thumbFillColor.g=255;
	thumbFillColor.b=0;
	thumbFillColor.a=127;
	//
	thumbLineColor.r=0;
	thumbLineColor.g=255;
	thumbLineColor.b=0;
	thumbLineColor.a=127;
	//
	scrollTrackFillColor.r=100;
	scrollTrackFillColor.g=100;
	scrollTrackFillColor.b=100;
	scrollTrackFillColor.a=255;
	//
	scrollTrackLineColor.r=100;
	scrollTrackLineColor.g=100;
	scrollTrackLineColor.b=100;
	scrollTrackLineColor.a=255;
	//
}

void G_SliderStyle::setThumbFillColor(ofColor color){
	this->thumbFillColor=color;
}
ofColor G_SliderStyle::getThumbFillColor(){
	return this->thumbFillColor;
}
void G_SliderStyle::setThumbLineColor(ofColor color){
	this->thumbLineColor=color;
}
ofColor G_SliderStyle::getThumbLineColor(){
	return this->thumbLineColor;
}

void G_SliderStyle::setScrollTrackFillColor(ofColor color){
	this->scrollTrackFillColor=color;
}
ofColor G_SliderStyle::getScrollTrackFillColor(){
	return this->scrollTrackFillColor;
}
void G_SliderStyle::setScrollTrackLineColor(ofColor color){
	this->scrollTrackLineColor=color;
}
ofColor G_SliderStyle::getScrollTrackLineColor(){
	return this->scrollTrackLineColor;
}



G_SliderStyle* G_SliderStyle::clone(){
	G_SliderStyle * clonedStyle=new G_SliderStyle();
	//
	clonedStyle->thumbFillColor=this->thumbFillColor;
	clonedStyle->thumbLineColor=this->thumbLineColor;
	//
	clonedStyle->scrollTrackFillColor=this->scrollTrackFillColor;
	clonedStyle->scrollTrackLineColor=this->scrollTrackLineColor;
	//
	clonedStyle->cornerRadius=this->cornerRadius;
	//
	return clonedStyle;
}