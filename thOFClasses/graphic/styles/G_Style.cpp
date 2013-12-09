/*
 *  G_Style.cpp
 *  eventsExample
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_Style.h"

G_Style::G_Style(){
	//TODO: put all G_Styles parallel, without inheritance!!
	//if(&fillColor!=NULL) delete &fillColor;
	fillColor.r=0;
	fillColor.g=255;
	fillColor.b=0;
	fillColor.a=1;
	//
	lineColor.r=0;
	lineColor.g=255;
	lineColor.b=0;
	lineColor.a=1;
	//
	
}

void G_Style::setFillColor(ofColor color){
	this->fillColor=color;
}
ofColor G_Style::getFillColor(){
	return this->fillColor;
}
void G_Style::setLineColor(ofColor color){
		this->lineColor=color;
}
ofColor G_Style::getLineColor(){
	return this->lineColor;
}
void G_Style::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_Style::getCornerRadius(){
	return this->cornerRadius;
}

G_Style* G_Style::clone(){
	G_Style * clonedG_Style=new G_Style();
	clonedG_Style->fillColor=this->fillColor;
	clonedG_Style->lineColor=this->lineColor;
	return clonedG_Style;
}