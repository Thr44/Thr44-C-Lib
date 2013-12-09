/*
 *  HalfMatrix.h
 *  SCPad
 *
 *  Created by machine on 7/6/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */
#ifndef _HALFMATRIX
#define _HALFMATRIX

#pragma once
#include "ofMain.h"
#include <stdarg.h>
#include <stdio.h>
#include "Object.h"

typedef vector<Object*> Vec;
typedef vector<Vec> Mat;

class HalfMatrix{
	
	
public:
	HalfMatrix();
	
	int* requestElement(Object* element);
	int addElement(Object* element);
	bool addElementAt(int i, int j, Object* object);
	Object* getElementAt(int i, int j);
	//void setNumElements();,
	//int getNumElements();
	//Node* getNodeAt(int position);
	
	//Node getNodeByName(string name);
	//Boolean push(int argc, Node*[] argv);
	//bool removeNode(Node* node);
	~HalfMatrix();
	int numElements;
	
protected:
	
	Mat matrix;
	int size;
};

#endif
