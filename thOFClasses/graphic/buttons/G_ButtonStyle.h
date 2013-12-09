/*
 *  G_ButtonStyle.h
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G_BUTTONSTYLE
#define _G_BUTTONSTYLE

#include "G_Style.h"
#include "FontStyle.h"

class G_ButtonStyle : public G_Style, public FontStyle{
	
public:
	G_ButtonStyle();
	virtual void setFillOverColor(ofColor color);
	virtual ofColor getFillOverColor();
	virtual void setLineOverColor(ofColor color);
	virtual ofColor getLineOverColor();
	virtual G_ButtonStyle* clone();

protected:
	ofColor fillOverColor;
	ofColor lineOverColor;
	
	

	
};

#endif