/*
 *  Relation.h
 *  exampleTree
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */
#ifndef _RELATION
#define _RELATION

//#pragma once
//#include "ofMain.h"
#include "Node.h"
//struct Node;
//struct Node;


class Relation:public Node{
	
public:
	Relation(Node* node0, Node* node1, bool directed);
	Node* getNode0();
	Node* getNode1();
	bool directed;
	
protected:
	Node* _node0;
	Node* _node1;
};

#endif
