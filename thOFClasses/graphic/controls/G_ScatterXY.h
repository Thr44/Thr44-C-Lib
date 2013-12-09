/*
 *  G_ScatterXY.h
 *  SCPad
 *
 *  Created by machine on 2/24/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */


#ifndef _G_ScatterXY
#define _G_ScatterXY

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

class G_ScatterXY : public G{ //style missing
	
public:
	G_ScatterXY();
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
	
	
	//TODO: virtual void setStyle(G_SliderStyle style);
	//TODO: virtual G_SliderStyle getStyle();
	// poco event stuff ---------
	BasicEvent<ofVec3f> onDrag;
	BasicEvent<int> onPress;
    BasicEvent<int> onRelease;
	
	void dispatchOnDrag (ofVec3f response) {
		onDrag.notify(this, response);
	}
	void dispatchOnPress (int response) {
		onPress.notify(this, response);
	}
    void dispatchOnRelease (int response) {
		onRelease.notify(this, response);
	}
    
    //vector<string> controlNames;
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
    bool isMovingScrollThumb;
#endif
	
	virtual bool hitTest(int x, int y);
	
	//void setRadius(float value);
	//void setRange(float min, float max);
	//STYLES:
	
	virtual void setControlFillColor(ofColor color);
	virtual ofColor getControlFillColor();
	virtual void setControlLineColor(ofColor color);
	virtual ofColor getControlLineColor();
	virtual void setScrollTrackFillColor(ofColor color);
	virtual ofColor getScrollTrackFillColor();
	virtual void setScrollTrackLineColor(ofColor color);
	virtual ofColor getScrollTrackLineColor();
	virtual void setCornerRadius(int cornerRadius);
	int getCornerRadius();
    
   // void setControlNames(vector<string> names);
   // vector<string> getControlNames();
	
	
protected:
	ofColor controlFillColor;
	ofColor controlLineColor;
	ofColor scrollTrackFillColor;
	ofColor scrollTrackLineColor;
	
	float scrollPosition;
	bool isMovingControl;
	ofVec2f response;
	int cornerRadius;
	
	float currX;
	float currY;
	
	//internal processes:
	//int prevX;
	//int prevY;
	void dragControl(int x, int y);
	void setControlPosition(int x, int y, float pressure);
    
	
	
};


#endif
