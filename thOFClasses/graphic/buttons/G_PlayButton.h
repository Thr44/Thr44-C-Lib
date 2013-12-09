/*
 *  G_Button.h
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G_PLAYBUTTON
#define _G_PLAYBUTTON

#pragma once
#include "ofMain.h"
#include "G_SelectButton.h"
#include "Settings.h"
//#include "ReleaseResponder.h"
#include "GeometryUtils.h"

// event stuff -------------------------------------
#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

using Poco::BasicEvent;
using Poco::Delegate;

//

class G_PlayButton : public G_SelectButton{
    
private:
    //ReleaseResponder* responder;
public:
	G_PlayButton();
	virtual string toString();
	virtual string type();
		
	virtual void setup();//ofEventArgs & args);
	///virtual void update();
	virtual void draw();//ofEventArgs & args);
	
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

	
	
};


#endif