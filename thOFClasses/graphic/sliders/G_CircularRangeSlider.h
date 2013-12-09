/*
 *  G_CircularRangeSlider.h
 *  exampleTree
 *
 *  Created by machine on 1/31/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#ifndef _G_CircularRangeSlider
#define _G_CircularRangeSlider

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

class G_CircularRangeSlider : public G{ //style missing
	
public:
	G_CircularRangeSlider();
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
	float highAngle;
	float lowAngle;
	
		
	//TODO: virtual void setStyle(G_SliderStyle style);
	//TODO: virtual G_SliderStyle getStyle();
	// poco event stuff ---------
	BasicEvent<float> onDrag;
	
	void dispatchOnDrag (float response) {
		onDrag.notify(this, response);
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
	void setRange(float min, float max);
	ofVec2f* getRange();
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
    
    vector<string> controlNames;
    
    //void setControlNames(vector<string> names);
    //vector<string> getControlNames();
	 
	
protected:
	ofColor thumbFillColor;
	ofColor thumbLineColor;
	ofColor scrollTrackFillColor;
	ofColor scrollTrackLineColor;
	
	float scrollPosition;
	bool isMovingScrollThumb;
	float response;
	int cornerRadius;
	
	//internal processes:
	int prevX;
	int prevY;
	void dragSlider(int x, int y);
	
	
	
};


#endif