/*
 *  PhysicsSystem.cpp
 *  SCPad
 *
 *  Created by machine on 1/31/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "PhysicsSystem.h"


PhysicsSystem::PhysicsSystem():Object(){
	this->damp=0.7;
	this->k=0.08;
	this->nRepulsors=0;
	this->nE=0;
	this->nParticles=0;
	this->maxRepulsorCalculations=1000;
	this->verificationRadius=4;
	this->finalVeriticationRadius=1.4;
	this->repulsorsOptimization=false;
	this->preactiveFactor=1.5;
	this->forcesMatrix=new HalfMatrix();
}

string PhysicsSystem::toString(){
	return "";
}
string PhysicsSystem::type(){
	return "PhysicsSystem";
}

int PhysicsSystem::addGNode(Object* gNode){
	int index=forcesMatrix->addElement(gNode);
	return index;
}
bool PhysicsSystem::addForce(Force* force){
	int index0=addGNode(force->node0);
	force->node0->x+=ofRandomf()*0.001;
	force->node0->y+=ofRandomf()*0.001;
	//TODO: solution for forces on nodes alone!!
	//if (force->node1!=NULL) {
		int index1=addGNode(force->node1);
		force->node1->x+=ofRandomf()*0.001;
		force->node1->y+=ofRandomf()*0.001;
	//}
	//G** objs=new G*[2];
	int* indxs=new int[2];
	if (index0<index1) {
		//objs[0]=force->node0;
		//objs[1]=force->node1;
		indxs[0]=index0;
		indxs[1]=index1;
	}else {
		//objs[0]=force->node1;
		//objs[1]=force->node0;
		indxs[0]=index1;
		indxs[1]=index0;
	}
	return forcesMatrix->addElementAt(indxs[1], indxs[0], force);
}
void PhysicsSystem::calculateForces(){
	int i;
	int j;
	//calculate forces:
	
	//printf("\n CALCULATE: has %i elements!", forcesMatrix->numElements);
	G* gNode;
	for(i=0; i<forcesMatrix->numElements; i++){
		gNode = (G*) forcesMatrix->getElementAt(i, i);
		//printf("\ngNode %i %s", gNode==NULL?0:1, gNode==NULL?"":gNode->type().data());
		if(gNode!=NULL){
			gNode->ax=0.0;
			gNode->ay=0.0;
			gNode->az=0.0;
		}
	}
	//trace("forces:", forcesArray.length);
	for(i=0; i<forcesMatrix->numElements; i++)
	{
		for(j=0; j<i; j++){
			Force* force=(Force*) forcesMatrix->getElementAt(i, j);
			if(force!=NULL){
				force->calculate();
			}/*else {
				printf("has no force at %i : %i", i, j);
			}*/

		}
	}
	assignPositions();
}
		/*
		//calculate fillRepulsors:
		var repulsor:Repulsor;
		var node0:Node;
		var node1:Node;
		var d:Number;
		
		//
		if(repulsorsOptimization && repulsorArray.length > 0){
			for(i=nE; i<nE+maxRepulsorCalculations; i++)
			{
				repulsor=repulsorArray[i%repulsorArray.length];
				node0 = repulsor.node0;
				node1 = repulsor.node1;
				d = Math.sqrt(Math.pow(node0.position.x-node1.position.x,2)+Math.pow(node0.position.y-node1.position.y,2)+Math.pow(node0.position.z-node1.position.z, 2));
				if(!repulsor.isPreActive && d<(repulsor.length*PREACTIVE_FACTOR)){
					preActiveRepulsorArray.push(repulsor);
					repulsor.isPreActive=true;
				}
			}
			nE=(nE+maxRepulsorCalculations)%repulsorArray.length;
			nPreActiveRepulsors = preActiveRepulsorArray.length;
			//
			//trace("nPreActiveRepulsors:", nPreActiveRepulsors);
			for(i=0; i<nPreActiveRepulsors; i++)
			{
				var status:int=preActiveRepulsorArray[i].preActiveCalculate()
				if(status==1){
					preActiveRepulsorArray.splice(i,1);
					i--;
					nPreActiveRepulsors--;
				}
			}
		}else{
			for(i=0; i<repulsorArray.length; i++)
			{
				repulsor=repulsorArray[i].calculate();
			}
		}
		
		//////
		for(i=0; i<nNodes; i++){
			node = forcesMatrix[i][i];
			if(node!=null){
				assignPositions(node);
			}
		}
		*/
		

void PhysicsSystem::assignPositions(){
	int i;
	for(i=0; i<forcesMatrix->numElements; i++)
	{
		G* gNode=(G*)(forcesMatrix->getElementAt(i, i));
		
		if (gNode!=NULL) {
			//printf("\nassignPositions BEFORE: %f %f, %f %f %f %f\n", gNode->x, gNode->y, gNode->vx, gNode->vy, gNode->ax, gNode->ay);
			gNode->vx+=gNode->ax;
			gNode->vy+=gNode->ay;
			gNode->vz+=gNode->az;
			gNode->vx*=this->damp;
			gNode->vy*=this->damp;
			gNode->vz*=this->damp;
			gNode->x+=gNode->vx;
			gNode->y+=gNode->vy;
			gNode->z+=gNode->vz;
			//printf("\nassignPositions AFTER: %f %f, %f %f %f %f\n", gNode->x, gNode->y, gNode->vx, gNode->vy, gNode->ax, gNode->ay);
			
		}
		
	}
}

