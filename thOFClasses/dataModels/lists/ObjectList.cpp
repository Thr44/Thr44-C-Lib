/*
 *  ObjectList.cpp
 *  SCPad
 *
 *  Created by machine on 2/7/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "ObjectList.h"
#include "Object.h"


ObjectList::ObjectList(){
	numObjects=0;
}
int ObjectList::length(){
	return numObjects;
}
void ObjectList::addObject(Object* object){
	objectVector.push_back(object);
	numObjects++;
}
bool ObjectList::addObjectIfUnique(Object* object){
	int i;
	for(i=0; i<numObjects; i++){
		if(objectVector[i]==object){
			//printf("\nnode %i, %s already exists!", node->id, node->label.data());
			return false;
		}
	}
	addObject(object);
	//printf("\nadded node %s at %i and size is %i", node->label.data(), numNodes, (int)nodeListVector.size());
	return true;
}
bool ObjectList::deleteObject(Object* object){
	int i;
	for(i=0; i<numObjects; i++){
		//printf("\n\nsearching node to remove at %i:: %s --- %s", i, node->label.data(), nodeListVector[i]->label.data());
		if(objectVector[i]==object){
			deleteObjectAt(i);
			//printf("\nremoved %i node. numnodes: %i, size: ", i, numNodes);
			return true;
		}
	}
	return false;
}
void ObjectList::deleteObjectAt(int index){
	Object* object = objectVector[index];
	objectVector.erase(objectVector.begin() +index);
	delete object;
	numObjects--;
}

/*
 void ObjectList::sort(void* sortFunc){
	std::sort(objectVector.begin(), objectVector.end(), sortFunc);
}
 */
bool ObjectList::removeObject(Object* object){
	int i;
	for(i=0; i<numObjects; i++){
		//printf("\n\nsearching node to remove at %i:: %s --- %s", i, node->label.data(), nodeListVector[i]->label.data());
		if(objectVector[i]==object){
			removeObjectAt(i);
			//printf("\nremoved %i node. numnodes: %i, size: ", i, numNodes);
			return true;
		} 
	}
	return false;
}
void ObjectList::removeObjectAt(int index){
	objectVector.erase(objectVector.begin() +index);
	numObjects--;
}

Object* ObjectList::getObjectAt(int index){
	return objectVector[index];
}

void ObjectList::sort(bool func(Object *, Object *)){
	std::sort(objectVector.begin(), objectVector.end(), func);
}

ObjectList* ObjectList::clone(){
	ObjectList* clonedList=new ObjectList();
	for(int i=0; i<length(); i++){
		clonedList->addObject(getObjectAt(i));
	}
	return clonedList;
}
