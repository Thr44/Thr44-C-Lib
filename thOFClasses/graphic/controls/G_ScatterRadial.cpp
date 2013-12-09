/*
 *  G_ScatterRadial.cpp
 *  SCPad
 *
 *  Created by machine on 5/7/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "G_ScatterRadial.h"

#include "GeometryUtils.h"
#include "ColorUtils.h"
#include <iostream>
#include <algorithm>
#include "Globals.h"


G_ScatterRadial::G_ScatterRadial(){
	alignment="CENTER";
	isMovingControl=false;
	this->width=100;
	this->height=100;
	currX=0.5;
	currY=0.5;
	this->controlFillColor=ColorUtils::white();
	this->scrollTrackFillColor=ColorUtils::black();
	this->cornerRadius=5;
	setup();
}
string G_ScatterRadial::toString(){
	return "";
}
string G_ScatterRadial::type(){
	return "G_ScatterRadial";
}

void G_ScatterRadial::setup(){
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

void G_ScatterRadial::update(){
	/*
	 #ifdef IPHONE
	 
	 #else
	 if(isMovingScrollThumb){
	 this->dragSlider(mx, my);
	 }
	 #endif
	 */
	
}
void G_ScatterRadial::draw(){//ofEventArgs & args){
	//if (visible) {
	
	ofColor color;
	
	ofEnableAlphaBlending();
	
	//scrollTrack:
	color = getScrollTrackFillColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	ofCircle(x, y, radius);
	ofEndShape(true);
	//thumb:
	color = getControlFillColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	//ofFill();
	ofSetLineWidth(2);
	ofBeginShape();
	//FIXME: position is wrong:
	//printf("/n x %f w %f currX %f posX %f posY %f /n", this->x, this->width, currX, this->x+(currX*width), this->y+(currY*height));
	//ofRect(x+(currX*width)-2, y+(currY*height)-2, 4, 4);
	ofCircle(x+(currX), y+(currY), 4);
	ofEndShape(true);
	//
	ofDisableAlphaBlending();
	
	//}
}

void G_ScatterRadial::setControlPosition(int x, int y){
	
	response=ofVec2f((x-this->x)/radius, (y-this->y)/radius);
	response=response.limited(1);
	
	currX=response.x*radius;
	currY=response.y*radius;
	
	dispatchOnDrag(response);
}
#ifdef IPHONE
void G_ScatterRadial::touchDown(ofTouchEventArgs & touch){
	
	printf("START DRAG!!");
	
	printf("mouse pressed @ %s", this->type().data());
	isMovingControl=true;
	dispatchOnPress(1);
	setControlPosition(touch.x, touch.y);
	/*if(this->hitTest(touch)){
	 if(GeometryUtils::hitTest(this->x, this->y+this->scrollPosition, this->width, this->width, touch)){
	 isMovingScrollThumb=true;
	 currentTouchID=touch.id;
	 }
	 }
	 */
	
}
void G_ScatterRadial::touchUp(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		
		isMovingControl=false;
        dispatchOnRelease(0);
		printf("touch up moving false");
	}
	
}
void G_ScatterRadial::touchUpOutside(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		
		printf("touchUpOutside @ %s", this->type().data());
		isMovingControl=false;
        dispatchOnRelease(0);
	}
}

void G_ScatterRadial::touchMoved(ofTouchEventArgs & touch){
	printf("touchMoved");
	if(isMovingControl){
		printf("touchMoved x: %f this->x: %f width: %f /n", (float) touch.x, this->x, this->width);
		setControlPosition(touch.x, touch.y);
		//this->dragSlider(x, y);
	}
	/*
	 printf("touchMoved");
	 if(isMovingScrollThumb && touch.id==currentTouchID){
	 scrollPosition=ofClamp(touch.y-this->y, 0, this->height-(this->width));
	 response=ofNormalize(scrollPosition, 0, this->height-(this->width));
	 dispatchOnDrag(response);
	 }
	 */
	
}


void G_ScatterRadial::touchDoubleTap(ofTouchEventArgs & touch){
	
}
#else


/*
 void G_CircularRangeSlider::dispatchMousePressed(int x, int y, int button){
 //bool stopEvent=false;
 for(int i=0; i<eventsVector.size(); i++){
 ThEvent* event = eventsVector[i];
 if(event->eventType==ThEvent::MOUSE_PRESSED){
 bool isHit=GeometryUtils::hitTest(this->x, this->y+scrollPosition, this->radius, x, y);
 if(isHit) mousePressed(x, y, button);
 if(isHit && event->stopPropagation){
 //stopEvent=true;
 return;
 }
 }
 }
 for(int j=nodeList->getNumNodes()-1; j>=0; j--){
 G* n = (G*)nodeList->getNodeAt(j);
 n->dispatchMousePressed(x, y, button);
 }
 }
 */




void G_ScatterRadial::mousePressed(int x, int y, int button){
	
	printf("mouse pressed @ %s", this->type().data());
	isMovingScrollThumb=true;
	setControlPosition(x, y);
}


void G_ScatterRadial::mouseReleased(int x, int y, int button){
	printf("mouse released @ %s", this->type().data());
	isMovingScrollThumb=false;
}
void G_ScatterRadial::mouseReleasedOutside(int x, int y, int button){
	printf("mouse releasedOutside @ %s", this->type().data());
	isMovingScrollThumb=false;
}


void G_ScatterRadial::mouseDragged(int x, int y, int button, bool isHit){
	if(isMovingScrollThumb){
		setControlPosition(x, y);
		//this->dragSlider(x, y);
	}
}
#endif
/*
 void G_ScatterRadial::dragSlider(int x, int y){
 if(isMovingScrollThumb){
 //printf("dragging!!!");
 float range=(highAngle-lowAngle+((x-prevX)));
 prevX=x;
 range=fmin(fmax(range, 0), 360);
 lowAngle=ofClamp(lowAngle+((y-prevY)), 0, 360.0-range);
 prevY=y;
 highAngle=lowAngle+range;
 response=ofNormalize(scrollPosition, 0, this->height-(this->width));
 dispatchOnDrag(response);
 }
 }
 */
bool G_ScatterRadial::hitTest(int x, int y){
	return GeometryUtils::hitTest(this->x, this->y, radius, x, y);
}

//Styles:



void G_ScatterRadial::setControlFillColor(ofColor color){
	this->controlFillColor=color;
}
ofColor G_ScatterRadial::getControlFillColor(){
	return this->controlFillColor;
}
void G_ScatterRadial::setControlLineColor(ofColor color){
	this->controlLineColor=color;
}
ofColor G_ScatterRadial::getControlLineColor(){
	return this->controlLineColor;
}

void G_ScatterRadial::setScrollTrackFillColor(ofColor color){
	this->scrollTrackFillColor=color;
}
ofColor G_ScatterRadial::getScrollTrackFillColor(){
	return this->scrollTrackFillColor;
}
void G_ScatterRadial::setScrollTrackLineColor(ofColor color){
	this->scrollTrackLineColor=color;
}
ofColor G_ScatterRadial::getScrollTrackLineColor(){
	return this->scrollTrackLineColor;
}
void G_ScatterRadial::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_ScatterRadial::getCornerRadius(){
	return this->cornerRadius;
}
void G_ScatterRadial::setRadius(float value){
	radius=value;
	setSize(radius*2, radius*2);
}
/*void G_ScatterRadial::setSize(float width, float height){
 this->width=width;
 this->height=height;
 }
 */

/* TODO:
 void G_ScatterRadial::setStyle(G_SliderStyle style){
 //this->style=style;
 printf("[!] function setStyle() not defined!");
 }
 G_SliderStyle G_ScatterRadial::getStyle(){
 printf("[!] function getStyle() not defined!");
 return * new G_SliderStyle();
 }
 */
