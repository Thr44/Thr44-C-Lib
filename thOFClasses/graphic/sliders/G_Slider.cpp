/*
 *  G_Slider.cpp
 *  SCPad
 *
 *  Created by machine on 9/20/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_Slider.h"
#include "GeometryUtils.h"
#include "ColorUtils.h"


G_Slider::G_Slider(){
	isMovingScrollThumb=false;
	this->width=20;
	this->height=100;
	this->thumbFillColor=ColorUtils::white();
	this->scrollTrackFillColor=ColorUtils::black();
	this->cornerRadius=5;
    //this->setScrollPosition();
	setup();
	//addListeners();
}
string G_Slider::toString(){
	return "";
}
string G_Slider::type(){
	return "G_Slider";
}

void G_Slider::setup(){
#ifdef IPHONE
	addListener(ThEvent::TOUCH_DOWN, true);
	addListener(ThEvent::TOUCH_UP, true);
	addListener(ThEvent::TOUCH_MOVED, true);
#else
	addListener(ThEvent::MOUSE_PRESSED, true);
	addListener(ThEvent::MOUSE_RELEASED, true);
	addListener(ThEvent::MOUSE_DRAGGED, true);
#endif
}

void G_Slider::draw(){//ofEventArgs & args){
	//if (visible) {
		
		ofColor color;
		
		ofEnableAlphaBlending();
		
		//scrollTrack:
		color = getScrollTrackFillColor();
		ofSetColor(color.r, color.g, color.b, color.a);
		ofFill();
		ofBeginShape();
		GeometryUtils::drawRoundRect(x, y, width, height, this->getCornerRadius());
		ofEndShape(true);
		//thumb:
		color = getThumbFillColor();
		ofSetColor(color.r, color.g, color.b, color.a);
		ofFill();
		ofBeginShape();
		GeometryUtils::drawRoundRect(x, y+scrollPosition, width, width, this->getCornerRadius());
		ofEndShape(true);
		//
		ofDisableAlphaBlending();
		
	//}
}
void G_Slider::setSize(float width, float height){
    float pos = this->scrollPosition/(this->height-this->width);
    
	this->width=width;
	this->height=height;
    this->scrollPosition=pos*(this->height-this->width);
}
void G_Slider::setScrollPosition(float value){
    this->scrollPosition=(1-value)*(this->height-this->width);
}
float G_Slider::getScrollPosition(){
	return 1-ofNormalize(scrollPosition, 0, this->height-(this->width));
}
#ifdef IPHONE
void G_Slider::touchDown(ofTouchEventArgs & touch){
    
	//if(this->hitTest(touch.x, touch.y)){
		if(GeometryUtils::hitTest(this->x, this->y+this->scrollPosition, this->width, this->width, touch.x, touch.y)){
            isMovingScrollThumb=true;
			currentTouchID=touch.id;
            prevY=touch.y;
            posY=touch.y-this->y;
		}
	//}
	
}
void G_Slider::touchUp(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		isMovingScrollThumb=false;
		printf("touch up movig false");
	}
	
}
void G_Slider::touchUpOutside(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		printf("touchUpOutside @ %s", this->type().data());
		isMovingScrollThumb=false;
	}
}

void G_Slider::touchMoved(ofTouchEventArgs & touch){
	printf("touchMoved");
	if(isMovingScrollThumb){// && touch.id==currentTouchID){
        posY=ofClamp(posY+((touch.y-prevY)), 0, this->height-(this->width));
		scrollPosition=posY;//ofClamp(posY, 0, this->height-(this->width));
		response=1-ofNormalize(scrollPosition, 0, this->height-(this->width));
		dispatchOnDrag(response);
        prevY=touch.y;
	}
	
}


void G_Slider::touchDoubleTap(ofTouchEventArgs & touch){
		
}
#else

void G_Slider::mousePressed(int x, int y, int button){
	printf("mouse pressed @ slider");
	isMovingScrollThumb=true;
}


void G_Slider::mouseReleased(int x, int y, int button){
	printf("mouse released @ slider");
	isMovingScrollThumb=false;
}
void G_Slider::mouseReleasedOutside(int x, int y, int button){
	printf("mouse releasedOutside @ slider");
	isMovingScrollThumb=false;
}



void G_Slider::mouseDragged(int x, int y, int button, bool isHit){
	if(isMovingScrollThumb){
		printf("mouse dragged @ slider, %i", isHit);
		scrollPosition=ofClamp(y-this->y, 0, this->height-(this->width));
		response=ofNormalize(scrollPosition, 0, this->height-(this->width));
		dispatchOnDrag(response);
	}
}
#endif




//Styles:



void G_Slider::setThumbFillColor(ofColor color){
	this->thumbFillColor=color;
}
ofColor G_Slider::getThumbFillColor(){
	return this->thumbFillColor;
}
void G_Slider::setThumbLineColor(ofColor color){
	this->thumbLineColor=color;
}
ofColor G_Slider::getThumbLineColor(){
	return this->thumbLineColor;
}

void G_Slider::setScrollTrackFillColor(ofColor color){
	this->scrollTrackFillColor=color;
}
ofColor G_Slider::getScrollTrackFillColor(){
	return this->scrollTrackFillColor;
}
void G_Slider::setScrollTrackLineColor(ofColor color){
	this->scrollTrackLineColor=color;
}
ofColor G_Slider::getScrollTrackLineColor(){
	return this->scrollTrackLineColor;
}
void G_Slider::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_Slider::getCornerRadius(){
	return this->cornerRadius;
}



void G_Slider::setStyle(G_SliderStyle style){
	//this->style=style;
	printf("[!] function setStyle() not defined!");
}
G_SliderStyle G_Slider::getStyle(){
	printf("[!] function getStyle() not defined!");
	return * new G_SliderStyle();
}
