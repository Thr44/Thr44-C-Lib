/*
 *  OSC.h
 *  SCPad
 *
 *  Created by machine on 9/11/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

// event stuff -------------------------------------
#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"

using Poco::BasicEvent;
using Poco::Delegate;

class OSC{
public:
	static OSC* getInstance();
	void setupSendOsc(string host, int port);
	void setupReceiveOsc(int port);
	void sendMessage(ofxOscMessage m);
	void update(ofEventArgs & args);
	bool isConnected;
	~OSC();
	// poco event stuff ---------
	BasicEvent<ofxOscMessage> onData;
	
	void dispatchOnData (ofxOscMessage response) {
		onData.notify(this, response);
		
	}
	// --------------------------
	
protected:
	OSC(); //constructor
	string SEND_HOST;
	int SEND_PORT;
	int LISTEN_PORT;

	ofxOscSender sender;
	ofxOscReceiver receiver;
	//
	
private:
	static OSC* instance;
};