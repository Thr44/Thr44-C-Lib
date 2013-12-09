/*
 *  ObjectList.h
 *  SCPad
 *
 *  Created by machine on 2/7/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */




#ifndef _OBJECTLIST
#define _OBJECTLIST

#pragma once
#include "ofMain.h"
#include <stdarg.h>
#include <stdio.h>
#include "Object.h"


class ObjectList{
	
	
	
public:
	int getNumObjects();
	Object* getObjectAt(int position);
	ObjectList();
	~ObjectList();
	bool removeObject(Object* object);
	void removeObjectAt(int index);
	bool deleteObject(Object* object);
	void deleteObjectAt(int index);
	void addObject(Object* object);
	bool addObjectIfUnique(Object* object);
	int length();
	void sort(bool func(Object *, Object *));
	ObjectList* clone();
	std::vector<Object*> objectVector;
	int numObjects;
	
/*protected:
	std::vector<Object*> objectVector;
	int numObjects;
 */
};

#endif