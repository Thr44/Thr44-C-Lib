/*
 *  GList.h
 *  
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */


#ifndef _GLIST
#define _GLIST

#pragma once
#include "ofMain.h"
#include <stdarg.h>
#include <stdio.h>
#include "G.h"

//class Node;

class GList{
	
	
public:
	int getSize();
	G* getGAt(int position);
	GList();
	//Node getNodeByName(string name);
	//Boolean push(int argc, Node*[] argv);
	bool remove(G* node);
	bool add(G* node);
    /** TODO_:
	void sort(bool func(Node *, Node *));
	void sortOnID();
	static bool sortOnIDFunction(Node* a, Node*b);
	**/
    
protected:
	
	std::vector<G*> gListVector;
	int size;
};

#endif

