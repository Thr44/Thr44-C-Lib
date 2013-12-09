/*
 *  Spring.cpp
 *  SCPad
 *
 *  Created by machine on 7/6/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "Spring.h"


Spring::Spring(G* node0, G* node1, float k, float length):Force(node0, node1){
	this->node0=node0;
	this->node1=node1;
	this->k=k;
	this->length=length;
	
}

string Spring::toString(){
	return "";
}
string Spring::type(){
	return "Spring";
}

void Spring::calculate(){
		float dx=this->node0->x-this->node1->x;
		float dy=this->node0->y-this->node1->y;
		float dz=this->node0->z-this->node1->z;

		float d=sqrt((dx*dx)+(dy*dy)+(dz*dz));
		float force=k*(d-this->length)/d;
		
		this->node0->ax-=force*dx;
		this->node0->ay-=force*dy;
		this->node0->az-=force*dz;
		this->node1->ax+=force*dx;
		this->node1->ay+=force*dy;
		this->node1->az+=force*dz;
		
	//}
}