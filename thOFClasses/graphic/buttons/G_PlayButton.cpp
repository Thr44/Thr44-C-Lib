/*
 *  G_PlayButton.cpp
 *  eventsExample
 *
 *  Created by machine on 8/28/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_PlayButton.h"


G_PlayButton::G_PlayButton():G_SelectButton(){
	//addListeners();
	//responder=NULL;
	//setup();
}
void G_PlayButton::setup(){//ofEventArgs & args){
	printf("setup was called @G_PlayButton");
	//textField.loadFont("verdana.ttf", 11);
	//printf("pressed and released added");
#ifdef IPHONE
	printf("added Listeners");
	addListener(ThEvent::TOUCH_DOWN, true);
	addListener(ThEvent::TOUCH_UP, true);
#else
	addListener(ThEvent::MOUSE_PRESSED, true);
	addListener(ThEvent::MOUSE_RELEASED, true);
#endif
}
string G_PlayButton::toString(){
	return "";
}
string G_PlayButton::type(){
	return "G_PlayButton";
}



void G_PlayButton::draw(){//ofEventArgs & args){
	ofSetColor(255, 255, 255);
	ofColor color;
	
    ofEnableAlphaBlending();
	
    if (isActive()) {
		color = getFillOverColor();
        
        ofSetColor(color.r, color.g, color.b, color.a);
        ofFill();
        
        ofBeginShape();
        
        int size=min(width, height)*0.8;
        ofRect(x, y, size, size);
        
        ofEndShape(true);
	}else {
		color = getFillColor();
        
        ofSetColor(color.r, color.g, color.b, color.a);
        ofFill();
        
        ofBeginShape();
        
        int size=min(width, height);
        ofVertex(x, y);
        ofVertex(x, y+size);
        ofVertex(x+size, y+(size*0.5));
        ofVertex(x, y);
        
        ofEndShape(true);
	}
	
    ofDisableAlphaBlending();
}

//Events:
#ifdef IPHONE
void G_PlayButton::touchUp(ofTouchEventArgs & touch){
	printf("touch up");
	//dispatchTouchUp(x, y, id);
}
void G_PlayButton::touchDown(ofTouchEventArgs & touch){
	printf("\ntouch down pressure:%f \n w / h:%f %f\n\n", touch.pressure, touch.width, touch.height);
    active=!active;
	dispatchOnClick(active);
	//dispatchTouchDown(x, y, id);
	
}
#else

void G_PlayButton::mouseReleased(int x, int y, int button){
	printf("mouse released in button");
	active=!active;
	dispatchOnClick(button);
}

void G_PlayButton::mousePressed(int x, int y, int button){
    
	printf("mouse pressed in button");
}

#endif




