/*
 *  RelationList.h
 *  exampleTree
 *
 *  Created by machine on 8/9/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#ifndef _RELATIONLIST
#define _RELATIONLIST

#pragma once

#include "NodeList.h"

struct Relation;
struct Node;
class RelationList : protected NodeList{
	

public:
	
	RelationList();
	//Node getNodeByName(string name);
	
	bool removeRelation(Relation* relation);
	bool addRelation(Relation* relation);
	int getNumRelations();
	 
	Relation* getRelationAt(int position);
	Relation* findRelation(Node* node0, Node* node1);
	RelationList* findRelations(Node* node);
	
};

#endif