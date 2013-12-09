/*
 *  G_CircularSelectSlider.cpp
 *  SCPad
 *
 *  Created by machine on 6/8/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "G_CircularSelectSlider.h"
#include "GeometryUtils.h"
#include "ColorUtils.h"
#include <iostream>
#include <algorithm>
#include "Globals.h"


G_CircularSelectSlider::G_CircularSelectSlider(){
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
string G_CircularSelectSlider::toString(){
	return "";
}
string G_CircularSelectSlider::type(){
	return "G_CircularSelectSlider";
}

void G_CircularSelectSlider::setup(){
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

void G_CircularSelectSlider::update(){
	/*
	 #ifdef IPHONE
	 
	 #else
	 if(isMovingScrollThumb){
	 this->dragSlider(mx, my);
	 }
	 #endif
	 */
	
}
void G_CircularSelectSlider::draw(){//ofEventArgs & args){
	//if (visible) {
	
	ofColor color;
	
	ofEnableAlphaBlending();
    //scrollTrack:
	color = getScrollTrackFillColor();
    //printf("\n getScrollTrackFillColor ????: %f %f %f %f", color.r, color.g, color.b, color.a);
    ofColor c=ofColor(0, 0, 0);
	ofSetColor(c);//(color.r, color.g, color.b, color.a);
	ofFill();
	ofBeginShape();
	ofCircle(x, y, radius);
	ofEndShape(true);
	//thumb:
	color = getThumbFillColor();
    //printf("\n getThumbFillColor ????: %f %f %f %f", color.r, color.g, color.b, color.a);
	int i;
	float prevPos=-90;
	float sectorAngle=360.0/numElements;
	//printf("sectors: %i %f", numElements, sectorAngle);
	for (i=0; i<numElements; i++) {
		if (elementsState[i]==1) {
			
			ofSetColor(getThumbFillColor());
			ofFill();
			
		}else{
			//int alpha=color.a;
			ofSetColor(getThumbFillColor(), 70);
			ofFill();
		}
		ofBeginShape();
		//printf("\nobj, %i", i);
		GeometryUtils::drawArc(x, y, outerRadius, -ofDegToRad(prevPos), -ofDegToRad(prevPos-sectorAngle+4), true, true);//(x, y, width, height, this->getCornerRadius());
		GeometryUtils::drawArc(x, y, innerRadius, -ofDegToRad(prevPos-sectorAngle+4), -ofDegToRad(prevPos), true, true);//(x, y, width, height, this->getCornerRadius());
		ofEndShape(true);
		prevPos=prevPos-sectorAngle;
		
			
	}
	
	
	//
	ofDisableAlphaBlending();
	//}
}
void G_CircularSelectSlider::setNumElements(int numElements){
	printf("numElements: %i", numElements );
	this->numElements=numElements;
	this->elementsState=new int[numElements];
	int i;
	for (i=0; i<numElements; i++) {
		this->elementsState[i]=0;
	}
}
/*
void G_CircularSelectSlider::setSliderPosition(float position){
	//printf("\nSET RANGE: %f %f", min, max);
	angle=position*360.0;
	//printf("\nANGLE: %f %f", lowAngle, highAngle);
}
 */
string G_CircularSelectSlider::getActiveElements(){
	return "0,1,2";
}
#ifdef IPHONE
void G_CircularSelectSlider::touchDown(ofTouchEventArgs & touch){
	float currX=touch.x-this->x;
	float currY=touch.y-this->y;
	ofVec2f vec=ofVec2f(currX, currY);
	float ang=fmod(360+vec.angle(ofVec2f(0, -1)),360);
	
	int pos=floor(ang/360*numElements);
	printf("\nangle: %f pos: %i\n", ang, pos);
	if(elementsState[pos]==1){
		elementsState[pos]=0;
	}else{
		elementsState[pos]=1;
	}
	
	dispatchOnPress(elementsState);
	
}

void G_CircularSelectSlider::touchUp(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		isMovingScrollThumb=false;
		printf("touch up movig false");
	}
	
}
void G_CircularSelectSlider::touchUpOutside(ofTouchEventArgs & touch){
	if(currentTouchID==touch.id){
		printf("touchUpOutside @ %s", this->type().data());
		isMovingScrollThumb=false;
	}
}
void G_CircularSelectSlider::touchMoved(ofTouchEventArgs & touch){
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


void G_CircularSelectSlider::touchDoubleTap(ofTouchEventArgs & touch){
	
}
#else


/*
 void G_CircularSelectSlider::dispatchMousePressed(int x, int y, int button){
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




void G_CircularSelectSlider::mousePressed(int x, int y, int button){
	prevX=x;
	prevY=y;
	printf("mouse pressed @ %s", this->type().data());
	isMovingScrollThumb=true;
}


void G_CircularSelectSlider::mouseReleased(int x, int y, int button){
	printf("mouse released @ %s", this->type().data());
	isMovingScrollThumb=false;
}
void G_CircularSelectSlider::mouseReleasedOutside(int x, int y, int button){
	printf("mouse releasedOutside @ %s", this->type().data());
	isMovingScrollThumb=false;
}



void G_CircularSelectSlider::mouseDragged(int x, int y, int button, bool isHit){
	if(isMovingScrollThumb){
		this->dragSlider(x, y);
	}
}
#endif

void G_CircularSelectSlider::dragSlider(int x, int y){
	/*
	if(isMovingScrollThumb){
		//printf("dragging!!!");
		//float range=(-lowAngle+((x-prevX)));
		prevX=x;
		//range=fmin(fmax(range, 0), 360);
		angle=ofClamp(angle+((y-prevY)), 0, 360.0);
		prevY=y;
		response=ofNormalize(scrollPosition, 0, this->height-(this->width));
		dispatchOnDrag(response);
	}
	 */
}

bool G_CircularSelectSlider::hitTest(int x, int y){
	return GeometryUtils::hitTest(this->x, this->y, radius, x, y);
}

//Styles:



void G_CircularSelectSlider::setThumbFillColor(ofColor color){
	this->thumbFillColor=color;
}
ofColor G_CircularSelectSlider::getThumbFillColor(){
	return this->thumbFillColor;
}
void G_CircularSelectSlider::setThumbLineColor(ofColor color){
	this->thumbLineColor=color;
}
ofColor G_CircularSelectSlider::getThumbLineColor(){
	return this->thumbLineColor;
}

void G_CircularSelectSlider::setScrollTrackFillColor(ofColor color){
	this->scrollTrackFillColor=color;
}
ofColor G_CircularSelectSlider::getScrollTrackFillColor(){
	return this->scrollTrackFillColor;
}
void G_CircularSelectSlider::setScrollTrackLineColor(ofColor color){
	this->scrollTrackLineColor=color;
}
ofColor G_CircularSelectSlider::getScrollTrackLineColor(){
	return this->scrollTrackLineColor;
}
void G_CircularSelectSlider::setCornerRadius(int cornerRadius){
	this->cornerRadius=cornerRadius;
}
int G_CircularSelectSlider::getCornerRadius(){
	return this->cornerRadius;
}
void G_CircularSelectSlider::setRadius(float value){
	radius=value;
	outerRadius=radius;
	innerRadius=max(10.0, outerRadius-10.0);
	setSize(radius*2, radius*2);
}


/* TODO:
 void G_CircularSelectSlider::setStyle(G_SliderStyle style){
 //this->style=style;
 printf("[!] function setStyle() not defined!");
 }
 G_SliderStyle G_CircularSelectSlider::getStyle(){
 printf("[!] function getStyle() not defined!");
 return * new G_SliderStyle();
 }
 */
