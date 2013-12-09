/*
 *  G_SelectButton.h
 *  SCPad
 *
 *  Created by machine on 2/8/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */



#ifndef _G_SELECTBUTTON
#define _G_SELECTBUTTON

#pragma once
#include "G_Button.h"
/*
#include "ofMain.h"
#include "G.h"
#include "Settings.h"
#include "G_ButtonStyle.h"

// event stuff -------------------------------------
#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

using Poco::BasicEvent;
using Poco::Delegate;

//class ThFont;
*/
class G_SelectButton : public G_Button{
	
public:
	
	G_SelectButton();
	~G_SelectButton();
	virtual string toString();
	virtual string type();
	virtual bool isActive();
	//virtual void setSize(float width, float height);
	//virtual void setLabel(string value);
	//virtual string getLabel();
	
	//virtual void setup();//ofEventArgs & args);
	//virtual void update();
	virtual void draw();//ofEventArgs & args);
	
	
	//Events:
	
	// poco event stuff ---------
	//BasicEvent<int> onClick;
	
	void dispatchOnClick (int response) {
		onClick.notify(this, response);
		
	}
	 
	// --------------------------
	
	
#ifdef IPHONE
	virtual void touchUp(ofTouchEventArgs & touch);//(int x, int y, int button);
	virtual void touchDown(ofTouchEventArgs & touch);//(int x, int y, int button);
#else
	virtual void mouseReleased(int x, int y, int button); //(ofMouseEventArgs & mouse);//
	virtual void mousePressed(int x, int y, int button); //ofMouseEventArgs & mouse);//
#endif
	
	/*
	//Styles:
	virtual void setStyle(G_ButtonStyle* style);
	virtual G_ButtonStyle* getStyle();
	*/
	/*
	 virtual void setFontName(string fontName);
	 virtual string getFontName();
	 virtual void setFontSize(int fontSize);
	 virtual int getFontSize();
	 */
	/*
	virtual void setFont(ofTrueTypeFont* font);
	virtual ofTrueTypeFont* getFont();
	virtual void setFontColor(ofColor fontColor);
	virtual ofColor getFontColor();
	
	virtual void setFillColor(ofColor color);
	virtual ofColor getFillColor();
	virtual void setLineColor(ofColor color);
	virtual ofColor getLineColor();
	virtual void setCornerRadius(int cornerRadius);
	int getCornerRadius();
	
	*/
    bool active;
protected:
	
	/*
	ofTrueTypeFont* font;
	
	//Styles:
	//string fontName;
	//int fontSize;
	//ofTrueTypeFont font;
	ofColor fontColor;
	ofColor fillColor;
	ofColor lineColor;
	int cornerRadius;
	string label;
	 */
	
};


#endif