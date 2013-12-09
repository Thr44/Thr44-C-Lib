/*
 *  FontStyle.cpp
 *  eventsExample
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "FontStyle.h"

FontStyle::FontStyle(){
	
}

void FontStyle::setFontName(string fontName){
	this->fontName=fontName;
}
string FontStyle::getFontName(){
	return this->fontName;
}
void FontStyle::setFontSize(int fontSize){
	this->fontSize=fontSize;
}
int FontStyle::getFontSize(){
	return this->fontSize;
}
void FontStyle::setFontColor(ofColor fontColor){
	this->fontColor=fontColor;
}
ofColor FontStyle::getFontColor(){
	return this->fontColor;
}
FontStyle * FontStyle::clone(){
	FontStyle * clonedStyle=new FontStyle();
	clonedStyle->fontName=this->fontName;
	clonedStyle->fontSize=this->fontSize;
	clonedStyle->fontColor=this->fontColor;
	return clonedStyle;
}