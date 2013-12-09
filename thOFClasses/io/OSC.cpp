/*
 *  OSC.cpp
 *  SCPad
 *
 *  Created by machine on 9/11/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "OSC.h"
#include "ofEvents.h"

OSC::OSC(){
	printf("added update event @ OSC");
	ofAddListener(ofEvents.update, this, &OSC::update);
}
OSC* OSC::instance = NULL;

OSC* OSC::getInstance(){
	if(instance == NULL){
		instance=new OSC();
		instance->isConnected=false;
	}
	return instance;
}
void OSC::setupSendOsc(string host, int port){
	this->SEND_HOST=host;
	this->SEND_PORT=port;
	sender.setup(SEND_HOST, SEND_PORT);
	isConnected=true;
	printf("connecting to | %s :: %i |", SEND_HOST.data(), SEND_PORT);
}
void OSC::update(ofEventArgs & args){
	//printf("OSC UPDATE!!");
	//dispatch correct event for data:
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		
		/*
		// unrecognized message: display on the bottom of the screen
		string msg_string;
		msg_string = m.getAddress();
		msg_string += ": ";
		for ( int i=0; i<m.getNumArgs(); i++ )
		{
			// get the argument type
			msg_string += m.getArgTypeName( i );
			msg_string += ":";
			// display the argument - make sure we get the right type
			if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
				msg_string += ofToString( m.getArgAsInt32( i ) );
			else if( m.getArgType( i ) == OFXOSC_TYPE_FLOAT )
				msg_string += ofToString( m.getArgAsFloat( i ) );
			else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
				msg_string += m.getArgAsString( i );
			else
				msg_string += "unknown";
		}
		printf("MESSAGE RECEIVED: %s", msg_string.data());
		 */
		dispatchOnData(m);
	}
}
void OSC::setupReceiveOsc(int port){
	this->LISTEN_PORT=port;
	receiver.setup(LISTEN_PORT);
	//printf("connecting LISTEN to | %i |", LISTEN_PORT);
}

void OSC::sendMessage(ofxOscMessage m){
	printf("sending msg");
	if(isConnected){
		sender.sendMessage( m);
	}
}