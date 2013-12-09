/*
 *  ThEvent.cpp
 *  exampleTree
 *
 *  Created by machine on 10/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "ThEvent.h"


ThEvent::ThEvent(int eventType, bool stopPropagation){
	this->eventType=eventType;
	//this->onDispatchFunc=func;
	this->stopPropagation=stopPropagation;
}
string ThEvent::toString(){
	//string value ""
	return "";
}

string ThEvent::type(){
	return "ThEvent";
}