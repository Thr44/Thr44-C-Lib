/*
 *  G_Slider.h
 *  SCPad
 *
 *  Created by machine on 9/20/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

/*
 *  G_Button.h
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G_SLIDER
#define _G_SLIDER

#pragma once
#include "ofMain.h"
#include "G.h"
#include "G_SliderStyle.h"
#include "Settings.h"



// event stuff -------------------------------------
#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

using Poco::BasicEvent;
using Poco::Delegate;

class G_Slider : public G{ //style missing
	
public:
	G_Slider();
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
	virtual void draw();
	
    virtual void setSize(float width, float height);
    
	virtual void setStyle(G_SliderStyle style);
	virtual G_SliderStyle getStyle();
	// poco event stuff ---------
	BasicEvent<float> onDrag;
	
	void dispatchOnDrag (float response) {
		onDrag.notify(this, response);
		
	}
	// --------------------------
	virtual void setScrollPosition(float value);
    float getScrollPosition();
	
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
	
protected:
	ofColor thumbFillColor;
	ofColor thumbLineColor;
	ofColor scrollTrackFillColor;
	ofColor scrollTrackLineColor;
	
	float scrollPosition;
	bool isMovingScrollThumb;
	int currentTouchID;
	float response;
	int cornerRadius;
    
    //internal processes:
	int prevY;
    int posY;
	
	
};


#endif