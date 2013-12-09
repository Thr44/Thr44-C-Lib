/*
 *  Tree.h
 *  exampleTree
 *
 *  Created by machine on 8/9/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#ifndef _TREE
#define _TREE

#pragma once
#include "Network.h"


class Tree:public Network{
	
	
public:
	
	Tree();
	virtual bool addNode(Node *node); 
	
	//removes node and its relations:
	virtual bool removeNode(Node *node);
	
	//FIXME: remove this: 
	virtual bool addRelation(Node* node0, Node* node1, bool directed); 
	virtual bool addRelation(Node* node0, Node* node1);
	virtual bool addRelation(Relation* relation);
	
	//removes relation but leaves node in network!
	virtual bool removeRelation(Relation *relation);
	virtual bool removeRelation(Node* node0, Node* node1);

	void printTree(Node* node);
};

#endif