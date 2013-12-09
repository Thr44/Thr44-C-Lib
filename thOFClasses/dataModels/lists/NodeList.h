/*
 *  NodeList.h
 *  
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */


#ifndef _NODELIST
#define _NODELIST

#pragma once
#include "ofMain.h"
#include <stdarg.h>
#include <stdio.h>
#include "Node.h"

//class Node;

class NodeList{
	
	
public:
	int getNumNodes();
	Node* getNodeAt(int position);
	NodeList();
	//Node getNodeByName(string name);
	//Boolean push(int argc, Node*[] argv);
	bool removeNode(Node* node);
	bool addNode(Node* node);
	void sort(bool func(Node *, Node *));
	void sortOnID();
	static bool sortOnIDFunction(Node* a, Node*b);
	

protected:
	
	std::vector<Node*> nodeListVector;
	int numNodes;
};

#endif

