/*
 *  PhysicsSystem.h
 *  SCPad
 *
 *  Created by machine on 1/31/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */
#ifndef _PHYSICSSYSYEM
#define _PHYSICSSYSYEM

#pragma once

#include "ofMain.h"
#include "HalfMatrix.h"
#include "Object.h"
#include "G.h"
#include "ObjectList.h"
#include "Force.h"

typedef vector<Object*> Vec;
typedef vector<Vec> Mat;

class PhysicsSystem : public Object{
	
public:
	PhysicsSystem();
	float k;
	float damp;
	
	HalfMatrix* forcesMatrix;
	ObjectList* forcesList;
	int nParticles;
	int nForces;
	int nRepulsors;
	ObjectList* repulsorList;
	ObjectList* preActiveRepulsorArray;
	//nPreActiveRepulsors
	float verificationRadius;
	float finalVeriticationRadius;
	
	
	
	float preactiveFactor;
	
	int addGNode(Object* gNode);
	int* requestGNode(G* gNode);
	bool addForce(Force* force);
	
	void calculateForces();
	void assignPositions();
	
	
protected:
	int nE;
	int maxRepulsorCalculations;
	int repulsorIteration;
	int currentE;
	bool repulsorsOptimization;
	
	
	
	virtual string toString();
	virtual string type();
	
	//virtual void calculate();
};

#endif


