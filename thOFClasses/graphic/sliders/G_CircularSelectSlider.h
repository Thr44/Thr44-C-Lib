/*
 *  G_CircularSelectSlider.h
 *  SCPad
 *
 *  Created by machine on 6/8/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */



#ifndef _G_CircularSelectSlider
#define _G_CircularSelectSlider

#pragma once
#include "ofMain.h"
#include "G.h"
//#include "G_SliderStyle.h"
#include "Settings.h"


// event stuff -------------------------------------
#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

using Poco::BasicEvent;
using Poco::Delegate;

class G_CircularSelectSlider : public G{ //style missing
	
public:
	G_CircularSelectSlider();
	virtual string toString();
	virtual string type();
	/*
	 virtual void setPosition(int x, int y);
	 virtual void setPosition(int x, int y, int z);
	 */
	//virtual void setStyle(G_ButtonStyle style);
	//virtual G_ButtonStyle getStyle();
	//virtual void addListeners();
	//virtual void removeListeners();
	//virtual void setSize(float width, float height);
	
	virtual void setup();
	virtual void update();
	virtual void draw();
	
	float radius;
	float outerRadius;
	float innerRadius;
	float angle;
	
	
	//TODO: virtual void setStyle(G_SliderStyle style);
	//TODO: virtual G_SliderStyle getStyle();
	// poco event stuff ---------
	BasicEvent<int*> onPress;
	
	void dispatchOnPress (int* response) {
		onPress.notify(this, response);
	}
	// --------------------------
	
	
#ifdef IPHONE
	virtual void touchUp(ofTouchEventArgs & touch);
	virtual void touchUpOutside(ofTouchEventArgs & touch);
	virtual void touchDown(ofTouchEventArgs & touch);
	virtual void touchMoved(ofTouchEventArgs & touch);
	virtual void touchDoubleTap(ofTouchEventArgs & touch);
#else
	virtual void mousePressed(int x, int y, int button);
	//virtual void dispatchMousePressed(int x, int y, int button); //FIXME
	virtual void mouseReleased(int x, int y, int button);
	virtual void mouseReleasedOutside(int x, int y, int button);
	virtual void mouseDragged(int x, int y, int button, bool isHit);
#endif
	
	virtual bool hitTest(int x, int y);
	
	void setRadius(float value);
	void setNumElements(int numElements);
	string getActiveElements();
	//STYLES:
	
	virtual void setThumbFillColor(ofColor color);
	virtual ofColor getThumbFillColor();
	virtual void setThumbLineColor(ofColor color);
	virtual ofColor getThumbLineColor();
	virtual void setScrollTrackFillColor(ofColor color);
	virtual ofColor getScrollTrackFillColor();
	virtual void setScrollTrackLineColor(ofColor color);
	virtual ofColor getScrollTrackLineColor();
	virtual void setCornerRadius(int cornerRadius);
	int getCornerRadius();
	//void setControlPosition(int x, int y);
	int numElements;
	
protected:
	ofColor thumbFillColor;
	ofColor thumbLineColor;
	ofColor scrollTrackFillColor;
	ofColor scrollTrackLineColor;
	
	float scrollPosition;
	bool isMovingScrollThumb;
	int* response;
	int cornerRadius;
	
	int* elementsState;
	
	
	//internal processes:
	int prevX;
	int prevY;
	void dragSlider(int x, int y);
	
	
	
};


#endif