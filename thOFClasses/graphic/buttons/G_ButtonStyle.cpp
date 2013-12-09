/*
 *  G_ButtonStyle.cpp
 *  eventsExample
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_ButtonStyle.h"

G_ButtonStyle::G_ButtonStyle(){
	fillColor.r=0;
	fillColor.g=255;
	fillColor.b=0;
	fillColor.a=127;
	//
	fillOverColor.r=100;
	fillOverColor.g=255;
	fillOverColor.b=0;
	fillOverColor.a=127;
	//
	lineColor.r=0;
	lineColor.g=255;
	lineColor.b=0;
	lineColor.a=127;
	//
	lineOverColor.r=0;
	lineOverColor.g=255;
	lineOverColor.b=0;
	lineOverColor.a=127;
}
void G_ButtonStyle::setFillOverColor(ofColor color){
	this->fillOverColor=color;
}
ofColor G_ButtonStyle::getFillOverColor(){
	return this->fillOverColor;
}
void G_ButtonStyle::setLineOverColor(ofColor color){
	this->lineOverColor=color;
}
ofColor G_ButtonStyle::getLineOverColor(){
	return this->lineOverColor;
}

G_ButtonStyle* G_ButtonStyle::clone(){
	G_ButtonStyle * clonedStyle=new G_ButtonStyle();
	//
	clonedStyle->fillColor=this->fillColor;
	clonedStyle->lineColor=this->lineColor;
	clonedStyle->fillOverColor=this->fillOverColor;
	clonedStyle->lineOverColor=this->lineOverColor;
	//
	clonedStyle->fontName=this->fontName;
	clonedStyle->fontSize=this->fontSize;
	clonedStyle->fontColor=this->fontColor;
	//
	clonedStyle->cornerRadius=this->cornerRadius;
	//
	return clonedStyle;
}