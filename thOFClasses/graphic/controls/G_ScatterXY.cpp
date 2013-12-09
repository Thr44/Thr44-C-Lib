/*
 *  G_ScatterXY.cpp
 *  SCPad
 *
 *  Created by machine on 2/24/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "G_ScatterXY.h"

#include "GeometryUtils.h"
#include "ColorUtils.h"
#include <iostream>
#include <algorithm>
#include "Globals.h"


G_ScatterXY::G_ScatterXY(){
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
string G_ScatterXY::toString(){
	return "";
}
string G_ScatterXY::type(){
	return "G_ScatterXY";
}

void G_ScatterXY::setup(){
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

void G_ScatterXY::update(){
	/*
	 #ifdef IPHONE
	 
	 #else
	 if(isMovingScrollThumb){
	 this->dragSlider(mx, my);
	 }
	 #endif
	 */
	
}
void G_ScatterXY::draw(){//ofEventArgs & args){
	//if (visible) {
	
	ofColor color;
	
	ofEnableAlphaBlending();
	
	//scrollTrack:
	color = getScrollTrackFillColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	GeometryUtils::drawRoundRect(x, y, width, height, this->getCornerRadius());
	//ofRect(x-(width*0.5), y-(height*0.5), width, height);
	ofEndShape(true);
	//thumb:
	color = getControlFillColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	//FIXME: position is wrong:
	//printf("/n x %f w %f currX %f posX %f posY %f /n", this->x, this->width, currX, this->x+(currX*width), this->y+(currY*height));
	ofRect(x+(currX*width)-2, y+(currY*height)-2, 4, 4);
	
	ofEndShape(true);
	//
	ofDisableAlphaBlending();
	
	//}
}

void G_ScatterXY::setControlPosition(int x, int y, float pressure){
	currX=ofNormalize( ((float)x-this->x)/this->width, 0, 1);
	currY=ofNormalize( ((float)y-this->y)/this->height, 0, 1);
	response=ofVec3f(currX, currY, pressure);
	dispatchOnDrag(response);
}
#ifdef IPHONE
void G_ScatterXY::touchDown(ofTouchEventArgs & touch){
	
	printf("START DRAG!!");
	
	printf("mouse pressed @ %s", this->type().data());
	isMovingControl=true;
	dispatchOnPress(1);
	setControlPosition(touch.x, touch.y, touch.pressure);
	/*if(this->hitTest(touch)){
	 if(GeometryUtils::hitTest(this->x, this->y+this->scrollPosition, this->width, this->width, touch)){
	 isMovingScrollThumb=true;
	 currentTouchID=touch.id;
	 }
	 }
	 */
	
}
void G_ScatterXY::touchUp(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		dispatchOnRelease(0);
		isMovingControl=false;
		printf("touch up moving false");
	}
	
}
void G_ScatterXY::touchUpOutside(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		dispatchOnRelease(0);
		printf("touchUpOutside @ %s", this->type().data());
		isMovingControl=false;
	}
}

void G_ScatterXY::touchMoved(ofTouchEventArgs & touch){
	printf("touchMoved");
	if(isMovingControl){
		printf("touchMoved x: %f this->x: %f width: %f /n", (float) touch.x, this->x, this->width);
		setControlPosition(touch.x, touch.y, touch.pressure);
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


void G_ScatterXY::touchDoubleTap(ofTouchEventArgs & touch){
	
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




void G_ScatterXY::mousePressed(int x, int y, int button){
	
	printf("mouse pressed @ %s", this->type().data());
	isMovingScrollThumb=true;
	setControlPosition(x, y);
}


void G_ScatterXY::mouseReleased(int x, int y, int button){
	printf("mouse released @ %s", this->type().data());
	isMovingScrollThumb=false;
}
void G_ScatterXY::mouseReleasedOutside(int x, int y, int button){
	printf("mouse releasedOutside @ %s", this->type().data());
	isMovingScrollThumb=false;
}


void G_ScatterXY::mouseDragged(int x, int y, int button, bool isHit){
	if(isMovingScrollThumb){
		setControlPosition(x, y, 10);
		//this->dragSlider(x, y);
	}
}
#endif
/*
void G_ScatterXY::dragSlider(int x, int y){
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
bool G_ScatterXY::hitTest(int x, int y){
	return GeometryUtils::hitTest(this->x, this->y, this->width, this->height, x, y);
}

//Styles:



void G_ScatterXY::setControlFillColor(ofColor color){
	this->controlFillColor=color;
}
ofColor G_ScatterXY::getControlFillColor(){
	return this->controlFillColor;
}
void G_ScatterXY::setControlLineColor(ofColor color){
	this->controlLineColor=color;
}
ofColor G_ScatterXY::getControlLineColor(){
	return this->controlLineColor;
}

void G_ScatterXY::setScrollTrackFillColor(ofColor color){
	this->scrollTrackFillColor=color;
}
ofColor G_ScatterXY::getScrollTrackFillColor(){
	return this->scrollTrackFillColor;
}
void G_ScatterXY::setScrollTrackLineColor(ofColor color){
	this->scrollTrackLineColor=color;
}
ofColor G_ScatterXY::getScrollTrackLineColor(){
	return this->scrollTrackLineColor;
}
void G_ScatterXY::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_ScatterXY::getCornerRadius(){
	return this->cornerRadius;
}
/*void G_ScatterXY::setSize(float width, float height){
	this->width=width;
	this->height=height;
}
*/

/* TODO:
 void G_ScatterXY::setStyle(G_SliderStyle style){
 //this->style=style;
 printf("[!] function setStyle() not defined!");
 }
 G_SliderStyle G_ScatterXY::getStyle(){
 printf("[!] function getStyle() not defined!");
 return * new G_SliderStyle();
 }
 */
