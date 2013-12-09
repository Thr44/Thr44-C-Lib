/*
 *  G_Button.cpp
 *  eventsExample
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_Button.h"
#include "GeometryUtils.h"
#include "NodeList.h"
//#include "ThFont.h"


G_Button::G_Button(){
	setup();
}
G_Button::~G_Button(){

}
string G_Button::toString(){
	return "";
}
string G_Button::type(){
	return "G_Button";
}
 
void G_Button::setSize(float width, float height){
	this->width=width;
	this->height=height;
}
void G_Button::setLabel(string labelValue){
	this->label=labelValue;
}
string G_Button::getLabel(){
	return this->label;
}
void G_Button::setup(){//ofEventArgs & args){
	this->setStyle(new G_ButtonStyle());
	printf("called setup @%s", this->type().data());
	//textField.loadFont("verdana.ttf", 11);
	//printf("pressed and released added");
#ifdef IPHONE
	addListener(ThEvent::TOUCH_DOWN, true);
	addListener(ThEvent::TOUCH_UP, true);
#else
	addListener(ThEvent::MOUSE_PRESSED, true);
	addListener(ThEvent::MOUSE_RELEASED, true);
#endif
}
void G_Button::update(){
	
}
void G_Button::draw(){//ofEventArgs & args){

		ofColor color;
	
		ofEnableAlphaBlending();
	
		color = getFillColor();
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
		font->drawString(this->label, floor(textX), floor(textY));

}


//Events:
#ifdef IPHONE
void G_Button::touchUp(ofTouchEventArgs & touch){
	printf("touch up at G_Button");
	dispatchOnRelease(touch.id);
	//dispatchTouchUp(x, y, id);
}
void G_Button::touchDown(ofTouchEventArgs & touch){
	printf("touch down");
    
	dispatchOnClick(touch.id);
	//dispatchTouchDown(x, y, id);
	
}
#else

void G_Button::mouseReleased(int x, int y, int button){
	printf("mouse released in button");
	//response=button;
	dispatchOnClick(button);
}

void G_Button::mousePressed(int x, int y, int button){
	printf("mouse pressed in button");
}

#endif



//Styles:
void G_Button::setFillColor(ofColor color){
	this->fillColor=color;
}
ofColor G_Button::getFillColor(){
	return this->fillColor;
}
void G_Button::setFillOverColor(ofColor color){
	this->fillOverColor=color;
}
ofColor G_Button::getFillOverColor(){
	return this->fillOverColor;
}
void G_Button::setLineColor(ofColor color){
	this->lineColor=color;
}
ofColor G_Button::getLineColor(){
	return this->lineColor;
}
void G_Button::setLineOverColor(ofColor color){
	this->lineOverColor=color;
}
ofColor G_Button::getLineOverColor(){
	return this->lineOverColor;
}
void G_Button::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_Button::getCornerRadius(){
	return this->cornerRadius;
}

void G_Button::setStyle(G_ButtonStyle* style){
	this->setFillColor(style->getFillColor());
	this->setLineColor(style->getLineColor());
	this->setFillOverColor(style->getFillOverColor());
	this->setLineOverColor(style->getLineOverColor());
	//
	//this->setFontName(style->getFontName());
	//this->setFontSize(style->getFontSize());
	this->setFontColor(style->getFontColor());
	//
	this->setCornerRadius(style->getCornerRadius());
}
G_ButtonStyle* G_Button::getStyle(){
	G_ButtonStyle * style=new G_ButtonStyle();
	//
	style->setFillColor(getFillColor());
	style->setLineColor(getLineColor());
	style->setFillOverColor(getFillOverColor());
	style->setLineOverColor(getLineOverColor());
	//
	//style->setFontName(getFontName());
	//style->setFontSize(getFontSize());
	style->setFontColor(getFontColor());
	//
	style->setCornerRadius(this->getCornerRadius());
	//
	return style;
}
/*
void G_Button::setFontName(string fontName){
	this->fontName=fontName;
}
string G_Button::getFontName(){
	return this->fontName;
}
void G_Button::setFontSize(int fontSize){
	this->fontSize=fontSize;
}
int G_Button::getFontSize(){
	return this->fontSize;
}
 */
void G_Button::setFont(ofTrueTypeFont* font){
	this->font=font;
}
ofTrueTypeFont* G_Button::getFont(){
	return this->font;
}
void G_Button::setFontColor(ofColor fontColor){
	this->fontColor=fontColor;
}
ofColor G_Button::getFontColor(){
	return this->fontColor;
}


