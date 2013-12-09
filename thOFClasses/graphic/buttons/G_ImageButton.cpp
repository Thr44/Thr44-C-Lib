/*
 *  G_ImageButton.cpp
 *  eventsExample
 *
 *  Created by machine on 8/28/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_ImageButton.h"


G_ImageButton::G_ImageButton():G(){
	//addListeners();
	//responder=NULL;
	//setup();
}
void G_ImageButton::setup(){//ofEventArgs & args){
	printf("setup was called @G_ImageButton");
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
string G_ImageButton::toString(){
	return "";
}
string G_ImageButton::type(){
	return "G_ImageButton";
}

void G_ImageButton::setImage(string imageValue){
	bool loaded=img.loadImage(imageValue);
	if(loaded){
		width=img.width;
		height=img.height;
	}else{
		printf("didn't load image %s", imageValue.data());
	}
}
/*void G_SimpleButton::setPosition(float x, float y){
 
 }
 void G_SimpleButton::setPosition(float x, float y, float z){
 
 }
 */

/*
void G_ImageButton::addListeners(){
}
 */


	/*
	G::addListeners();//DUVIDA nao deveria chamar a super na mesma?
#ifdef IPHONE
	ofAddListener(ofEvents.touchUp, this, &G_ImageButton::touchUp);
#else
	ofAddListener(ofEvents.mouseReleased, this, &G_ImageButton::mouseReleased);
#endif
}
void G_ImageButton::removeListeners(){
	G::removeListeners();//DUVIDA=
#ifdef IPHONE
	ofRemoveListener(ofEvents.touchUp, this, &G_ImageButton::touchUp);
#else
	ofRemoveListener(ofEvents.mouseReleased, this, &G_ImageButton::mouseReleased);
#endif
}
*/



/*super contains all this:
void G_ImageButton::setSize(float width, float height){
	this->width=width;
	this->height=height;
}

void G_ImageButton::setup(ofEventArgs & args){
	addListener(ThEvent::MOUSE_PRESSED, true);
	addListener(ThEvent::MOUSE_RELEASED, true);
}
*/

void G_ImageButton::draw(){//ofEventArgs & args){
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	img.draw(this->x, this->y, this->width, this->height);
	ofDisableAlphaBlending();
}

//Events:
#ifdef IPHONE
void G_ImageButton::touchUp(ofTouchEventArgs & touch){
	printf("touch up");
	//dispatchTouchUp(x, y, id);
}
void G_ImageButton::touchDown(ofTouchEventArgs & touch){
	printf("touch down");
	dispatchOnClick(touch.id);
	//dispatchTouchDown(x, y, id);
	
}
#else

void G_ImageButton::mouseReleased(int x, int y, int button){
	printf("mouse released in button");
	//response=button;
	dispatchOnClick(button);
}

void G_ImageButton::mousePressed(int x, int y, int button){
	printf("mouse pressed in button");
}

#endif

/*
void G_ImageButton::setActionOnReleased(ReleaseResponder* aResponder ) { 
	responder = aResponder;
};
 */
	
/* already defined:
#ifdef IPHONE
void G_ImageButton::touchUp(ofTouchEventArgs & touch){
	if(visible && hitTest(touch)){
		
		printf("touch up");
		if(responder)
			responder->OnRelease();
	}
};

void G_ImageButton::touchDown(ofTouchEventArgs & touch){
	printf("touch down");
	
}
#else
void G_ImageButton::mouseReleased(ofMouseEventArgs & mouse){
	printf("mouse released");
	dispatchOnClick(button);
}

void G_ImageButton::mousePressed(ofMouseEventArgs & mouse){
	printf("mouse pressed");
}
#endif

 */




