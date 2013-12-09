/*
 *  G_CircularRangeSlider.cpp
 *  exampleTree
 *
 *  Created by machine on 1/31/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */



#include "G_CircularRangeSlider.h"
#include "GeometryUtils.h"
#include "ColorUtils.h"
#include <iostream>
#include <algorithm>
#include "Globals.h"


G_CircularRangeSlider::G_CircularRangeSlider(){
	alignment="CENTER";
	isMovingScrollThumb=false;
	this->width=20;
	this->height=100;
	lowAngle=0;
	highAngle=360;
	this->thumbFillColor=ColorUtils::white();
	this->scrollTrackFillColor=ColorUtils::black();
	//this->cornerRadius=5;
	setup();
}
string G_CircularRangeSlider::toString(){
	return "";
}
string G_CircularRangeSlider::type(){
	return "G_CircularRangeSlider";
}

void G_CircularRangeSlider::setup(){
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

void G_CircularRangeSlider::update(){
	/*
#ifdef IPHONE
	
#else
	if(isMovingScrollThumb){
		this->dragSlider(mx, my);
	}
#endif
*/
 
}
void G_CircularRangeSlider::draw(){//ofEventArgs & args){
	//if (visible) {
	
	ofColor color;
	
	//ofEnableAlphaBlending();
		
	//scrollTrack:
	color = getScrollTrackFillColor();
	ofSetColor(0, 0, 0);//color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	ofCircle(x, y, radius);
	ofEndShape(true);
	//thumb:
	color = getThumbFillColor();
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	
	GeometryUtils::drawArc(x, y, outerRadius, -ofDegToRad(lowAngle-90), -ofDegToRad(highAngle-90), true, true);//(x, y, width, height, this->getCornerRadius());
	GeometryUtils::drawArc(x, y, innerRadius, -ofDegToRad(highAngle-90), -ofDegToRad(lowAngle-90), true, true);//(x, y, width, height, this->getCornerRadius());
	
	ofEndShape(true);
	//
	//ofDisableAlphaBlending();
	//}
}

/*void G_CircularRangeSlider::setControlNames(vector<string> names){
    this->controlNames=names;
}
 */
/*
 vector<string> G_ScatterXY::getControlNames(){
 
 }
 */

void G_CircularRangeSlider::setRange(float min, float max){
	//printf("\nSET RANGE: %f %f", min, max);
	lowAngle=min*360.0;
	highAngle=max*360.0;
	//printf("\nANGLE: %f %f", lowAngle, highAngle);
}
ofVec2f* G_CircularRangeSlider::getRange(){
	return new ofVec2f(lowAngle/360, highAngle/360);
}
#ifdef IPHONE
void G_CircularRangeSlider::touchDown(ofTouchEventArgs & touch){
	
	//printf("START DRAG!!");
	prevX=touch.x;
	prevY=touch.y;
	//printf("mouse pressed @ %s", this->type().data());
	isMovingScrollThumb=true;
	/*if(this->hitTest(touch)){
		if(GeometryUtils::hitTest(this->x, this->y+this->scrollPosition, this->width, this->width, touch)){
			isMovingScrollThumb=true;
			currentTouchID=touch.id;
		}
	}
	 */
	
}
void G_CircularRangeSlider::touchUp(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		isMovingScrollThumb=false;
		printf("touch up movig false");
	}
	
}
void G_CircularRangeSlider::touchUpOutside(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		printf("touchUpOutside @ %s", this->type().data());
		isMovingScrollThumb=false;
	}
}
void G_CircularRangeSlider::touchMoved(ofTouchEventArgs & touch){
	printf("touchMoved");
	if(isMovingScrollThumb){
		this->dragSlider(touch.x, touch.y);
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


void G_CircularRangeSlider::touchDoubleTap(ofTouchEventArgs & touch){
	
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




void G_CircularRangeSlider::mousePressed(int x, int y, int button){
	prevX=x;
	prevY=y;
	printf("mouse pressed @ %s", this->type().data());
	isMovingScrollThumb=true;
}


void G_CircularRangeSlider::mouseReleased(int x, int y, int button){
	printf("mouse released @ %s", this->type().data());
	isMovingScrollThumb=false;
}
void G_CircularRangeSlider::mouseReleasedOutside(int x, int y, int button){
	printf("mouse releasedOutside @ %s", this->type().data());
	isMovingScrollThumb=false;
}



void G_CircularRangeSlider::mouseDragged(int x, int y, int button, bool isHit){
	if(isMovingScrollThumb){
		this->dragSlider(x, y);
	}
}
#endif

void G_CircularRangeSlider::dragSlider(int x, int y){
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

bool G_CircularRangeSlider::hitTest(int x, int y){
	return GeometryUtils::hitTest(this->x, this->y, radius, x, y);
}

//Styles:



void G_CircularRangeSlider::setThumbFillColor(ofColor color){
	this->thumbFillColor=color;
}
ofColor G_CircularRangeSlider::getThumbFillColor(){
	return this->thumbFillColor;
}
void G_CircularRangeSlider::setThumbLineColor(ofColor color){
	this->thumbLineColor=color;
}
ofColor G_CircularRangeSlider::getThumbLineColor(){
	return this->thumbLineColor;
}

void G_CircularRangeSlider::setScrollTrackFillColor(ofColor color){
	this->scrollTrackFillColor=color;
}
ofColor G_CircularRangeSlider::getScrollTrackFillColor(){
	return this->scrollTrackFillColor;
}
void G_CircularRangeSlider::setScrollTrackLineColor(ofColor color){
	this->scrollTrackLineColor=color;
}
ofColor G_CircularRangeSlider::getScrollTrackLineColor(){
	return this->scrollTrackLineColor;
}
void G_CircularRangeSlider::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_CircularRangeSlider::getCornerRadius(){
	return this->cornerRadius;
}
void G_CircularRangeSlider::setRadius(float value){
	radius=value;
	outerRadius=radius;
	innerRadius=max(10.0, outerRadius-10.0);
	setSize(radius*2, radius*2);
}


/* TODO:
void G_CircularRangeSlider::setStyle(G_SliderStyle style){
	//this->style=style;
	printf("[!] function setStyle() not defined!");
}
G_SliderStyle G_CircularRangeSlider::getStyle(){
	printf("[!] function getStyle() not defined!");
	return * new G_SliderStyle();
}
 */
