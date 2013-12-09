/*
 *  G_SelectButton.cpp
 *  SCPad
 *
 *  Created by machine on 2/8/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "G_SelectButton.h"
#include "GeometryUtils.h"

/*
#include "GeometryUtils.h"
#include "NodeList.h"
 */
//#include "ThFont.h"


G_SelectButton::G_SelectButton():G_Button(){
	active=false;
	//setup();
}
G_SelectButton::~G_SelectButton(){
	
}
string G_SelectButton::toString(){
	return "";
}
string G_SelectButton::type(){
	return "G_SelectButton";
}
bool G_SelectButton::isActive(){
	return this->active;
}
void G_SelectButton::draw(){//ofEventArgs & args){
	
	ofColor color;
	
	ofEnableAlphaBlending();
	if (isActive()) {
		color = getFillOverColor();
	}else {
		color = getFillColor();
	}
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	GeometryUtils::drawRoundRect(x, y, width, height, this->getCornerRadius());
	ofEndShape(true);
	ofDisableAlphaBlending();
	float textWidth=font->stringWidth(this->label);
	float textX=this->x+((this->width-textWidth)*0.5);
	float textY=this->y+(floor(this->height*0.5));
	color = getFontColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	font->drawString(this->label, textX, textY);
	
}


//Events:
#ifdef IPHONE
void G_SelectButton::touchUp(ofTouchEventArgs & touch){
	printf("touch up");
	//dispatchTouchUp(x, y, id);
}
void G_SelectButton::touchDown(ofTouchEventArgs & touch){
	printf("touch down");
	active=!active;
	dispatchOnClick(touch.id);
	//dispatchTouchDown(x, y, id);
	
}
#else

void G_SelectButton::mouseReleased(int x, int y, int button){
	printf("mouse released in button");
	//response=button;
	active=!active;
	dispatchOnClick(button);
}

void G_SelectButton::mousePressed(int x, int y, int button){
	printf("mouse pressed in button");
}

#endif



