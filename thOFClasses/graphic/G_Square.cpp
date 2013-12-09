/*
 *  G_Square.cpp
 *  particlesExample
 *
 *  Created by machine on 7/7/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "G_Square.h"
#include "GeometryUtils.h"


G_Square::G_Square():G(){
	setVisible(true);
	this->cornerRadius=0;
}
string G_Square::toString(){
	return "";
}
string G_Square::type(){
	return "G_Square";
}

void G_Square::draw(){
	ofColor color;
	
	ofEnableAlphaBlending();
	
	//scrollTrack:
	color = getFillColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	GeometryUtils::drawRoundRect(this->x, this->y, this->width, this->height, this->getCornerRadius());
	ofEndShape(true);
	//
	ofDisableAlphaBlending();
	
}
void G_Square::setFillColor(ofColor color){
	this->fillColor=color;
}
ofColor G_Square::getFillColor(){
	return this->fillColor;
}
void G_Square::setCornerRadius(int value){
	this->cornerRadius=value;
}
int G_Square::getCornerRadius(){
	return this->cornerRadius;
}