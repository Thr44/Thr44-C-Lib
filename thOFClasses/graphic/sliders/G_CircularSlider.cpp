/*
 *  G_CircularSlider.cpp
 *
 *  Created by machine on 1/31/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */



#include "G_CircularSlider.h"
#include "GeometryUtils.h"
#include "ColorUtils.h"
#include <iostream>
#include <algorithm>
#include "Globals.h"


G_CircularSlider::G_CircularSlider(){
	alignment="CENTER";
	isMovingScrollThumb=false;
	this->width=20;
	this->height=100;
	angle=0;
	this->thumbFillColor=ColorUtils::white();
	this->scrollTrackFillColor=ColorUtils::black();
	//this->cornerRadius=5;
	setup();
}
string G_CircularSlider::toString(){
	return "";
}
string G_CircularSlider::type(){
	return "G_CircularSlider";
}

void G_CircularSlider::setup(){
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

void G_CircularSlider::update(){
	/*
	 #ifdef IPHONE
	 
	 #else
	 if(isMovingScrollThumb){
	 this->dragSlider(mx, my);
	 }
	 #endif
	 */
	
}
void G_CircularSlider::draw(){//ofEventArgs & args){
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
	color = getThumbFillColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	
	GeometryUtils::drawArc(x, y, outerRadius, -ofDegToRad(-90), -ofDegToRad(angle-90), true, true);//(x, y, width, height, this->getCornerRadius());
	GeometryUtils::drawArc(x, y, innerRadius, -ofDegToRad(angle-90), -ofDegToRad(-90), true, true);//(x, y, width, height, this->getCornerRadius());
	
	ofEndShape(true);
	//
	ofDisableAlphaBlending();
	//}
}

/*void G_CircularSlider::setControlNames(vector<string> names){
    this->controlNames=names;
}
*/
void G_CircularSlider::setScrollPosition(float position){
	//printf("\nSET RANGE: %f %f", min, max);
	angle=position*360.0;
	//printf("\nANGLE: %f %f", lowAngle, highAngle);
}
float G_CircularSlider::getScrollPosition(){
	return (angle/360);
}
#ifdef IPHONE
void G_CircularSlider::touchDown(ofTouchEventArgs & touch){
	
	//printf("START DRAG!!");
	prevX=touch.x;
	prevY=touch.y;
	
	isMovingScrollThumb=true;
	
}
void G_CircularSlider::touchUp(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		isMovingScrollThumb=false;
		printf("touch up movig false");
	}
	
}
void G_CircularSlider::touchUpOutside(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		printf("touchUpOutside @ %s", this->type().data());
		isMovingScrollThumb=false;
	}
}
void G_CircularSlider::touchMoved(ofTouchEventArgs & touch){
	printf("touchMoved");
	if(isMovingScrollThumb){
		this->dragSlider(touch.x, touch.y);
	}
	
}


void G_CircularSlider::touchDoubleTap(ofTouchEventArgs & touch){
	
}
#else


/*
 void G_CircularSlider::dispatchMousePressed(int x, int y, int button){
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




void G_CircularSlider::mousePressed(int x, int y, int button){
	prevX=x;
	prevY=y;
	printf("mouse pressed @ %s", this->type().data());
	isMovingScrollThumb=true;
}


void G_CircularSlider::mouseReleased(int x, int y, int button){
	printf("mouse released @ %s", this->type().data());
	isMovingScrollThumb=false;
}
void G_CircularSlider::mouseReleasedOutside(int x, int y, int button){
	printf("mouse releasedOutside @ %s", this->type().data());
	isMovingScrollThumb=false;
}



void G_CircularSlider::mouseDragged(int x, int y, int button, bool isHit){
	if(isMovingScrollThumb){
		this->dragSlider(x, y);
	}
}
#endif

void G_CircularSlider::dragSlider(int x, int y){
	if(isMovingScrollThumb){
		prevX=x;
		angle=ofClamp(angle+((y-prevY)), 0, 360.0);
		prevY=y;
		response=ofNormalize(scrollPosition, 0, this->height-(this->width));
		dispatchOnDrag(response);
	}
}

bool G_CircularSlider::hitTest(int x, int y){
	return GeometryUtils::hitTest(this->x, this->y, radius, x, y);
}

//Styles:



void G_CircularSlider::setThumbFillColor(ofColor color){
	this->thumbFillColor=color;
}
ofColor G_CircularSlider::getThumbFillColor(){
	return this->thumbFillColor;
}
void G_CircularSlider::setThumbLineColor(ofColor color){
	this->thumbLineColor=color;
}
ofColor G_CircularSlider::getThumbLineColor(){
	return this->thumbLineColor;
}

void G_CircularSlider::setScrollTrackFillColor(ofColor color){
	this->scrollTrackFillColor=color;
}
ofColor G_CircularSlider::getScrollTrackFillColor(){
	return this->scrollTrackFillColor;
}
void G_CircularSlider::setScrollTrackLineColor(ofColor color){
	this->scrollTrackLineColor=color;
}
ofColor G_CircularSlider::getScrollTrackLineColor(){
	return this->scrollTrackLineColor;
}
void G_CircularSlider::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_CircularSlider::getCornerRadius(){
	return this->cornerRadius;
}
void G_CircularSlider::setRadius(float value){
	radius=value;
	outerRadius=radius;
	innerRadius=max(10.0, outerRadius-10.0);
	setSize(radius*2, radius*2);
}


/* TODO:
 void G_CircularSlider::setStyle(G_SliderStyle style){
 //this->style=style;
 printf("[!] function setStyle() not defined!");
 }
 G_SliderStyle G_CircularSlider::getStyle(){
 printf("[!] function getStyle() not defined!");
 return * new G_SliderStyle();
 }
 */
