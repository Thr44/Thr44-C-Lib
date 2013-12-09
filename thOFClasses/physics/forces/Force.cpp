/*
 *  Force.cpp
 *  SCPad
 *
 *  Created by machine on 1/31/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "Force.h"

/*
Force::Force(G* node){
	this->node0=node;
	this->node1=NULL;
}
 */
Force::Force(G* node0, G* node1){
	this->node0=node0;
	this->node1=node1;
	printf("init: %s %s", this->node0?"true":"false", this->node1?"true":"false");
}

string Force::toString(){
	return "";
}
string Force::type(){
	return "Force";
}

void Force::calculate(){
	
}
