//
//  G_InputField.h
//  eventsExample
//
//  Created by machine on 8/27/10.
//  Copyright 2010 .. All rights reserved.
//
#ifndef _G_INPUTFIELD
#define _G_INPUTFIELD

#pragma once

#include "ofxiPhoneKeyboard.h"
#include "GeometryUtils.h"
#include "G.h"
#include "Globals.h"


class G_InputField:public G{
public:
	G_InputField();
	void setLabel(string label);
	string getValue();
	void setPlaceHolderLabel(string label);

	virtual void setup();
	virtual void draw();
	ofxiPhoneKeyboard * keyboard;
	//virtual void setPosition(float x, float y, float z);
	//virtual void setPosition(float x, float y);
	virtual void setVisible(bool value);
	virtual void orientationChanged(int newOrientation);
	virtual void touchDown(int x, int y, int id);

protected:
	string textString;
	string label;
	string value;
	//ofTrueTypeFont textField;
	
	bool isKeyboardEnabled;
};
#endif



