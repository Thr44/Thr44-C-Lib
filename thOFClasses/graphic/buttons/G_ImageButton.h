/*
 *  G_Button.h
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G_IMAGEBUTTON
#define _G_IMAGEBUTTON

#pragma once
#include "ofMain.h"
#include "G.h"
#include "Settings.h"
//#include "ReleaseResponder.h"
#include "GeometryUtils.h"

// event stuff -------------------------------------
#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

using Poco::BasicEvent;
using Poco::Delegate;

//

class G_ImageButton : public G{

private:
    //ReleaseResponder* responder;
public:
	G_ImageButton();
	virtual string toString();
	virtual string type();
	virtual void setImage(string imageValue);
	
	//virtual void addListeners();
	//virtual void removeListeners();
	///virtual void setSize(float width, float height);
	
	virtual void setup();//ofEventArgs & args);
	///virtual void update();
	virtual void draw();//ofEventArgs & args);
	//void setActionOnReleased(ReleaseResponder* aResponder);
	
	//Events:
	
	
#ifdef IPHONE
	virtual void touchUp(ofTouchEventArgs & touch);//(int x, int y, int button);
	virtual void touchDown(ofTouchEventArgs & touch);//(int x, int y, int button);
#else
	virtual void mouseReleased(int x, int y, int button); //(ofMouseEventArgs & mouse);//
	virtual void mousePressed(int x, int y, int button); //ofMouseEventArgs & mouse);//
#endif
	
	// poco event stuff ---------
	BasicEvent<int> onClick;
	
	void dispatchOnClick (int response) {
		onClick.notify(this, response);
		
	}
	// --------------------------
	
	
#ifdef IPHONE
	//virtual void touchUp(ofTouchEventArgs & touch);//(int x, int y, int button);
	//virtual void touchDown(ofTouchEventArgs & touch);//(int x, int y, int button);
#else
	///virtual void mouseReleased(int x, int y, int button); //(ofMouseEventArgs & mouse);//(int x, int y, int button);
	///virtual void mousePressed(int x, int y, int button); //(ofMouseEventArgs & mouse);//(int x, int y, int button);
#endif

protected:
	ofImage img;
	
};


#endif