/*
 *  Network.h
 *  
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 //
 network=new Network();
 //
 Node *node1=new Node(0, "teste");
 Node *node2=new Node(2, "teste2");
 network->addNode(node1);
 network->addNode(node1);
 network->addNode(node2);
 node1->nodeList->addNode(node2);
 node1->nodeList->removeNode(node2);
 network->removeNode(node2);
 network->removeNode(node2);
 
 */

#ifndef _G_TREE
#define _G_TREE

//#pragma once
#include "GList.h"
#include "G_Tree.h"
#include "G.h"


struct GList;
struct G;


class G_Tree{
	
public:
	G_Tree();
	GList *childList;
	
	virtual bool addChild(G *child); 
	
	//removes node and its relations:
	virtual bool removeChild(G *child); 
	
	//FIXME: remove this: 
	virtual bool addRelation(G* node0, G* node1, bool directed); 
	virtual bool addRelation(G* node0, G* node1);
	
	//removes relation but leaves node in network!
	virtual bool removeRelation(G* node0, G* node1);


	
	void printNetwork();
	
protected:
	int getNewNodeID();
	int getNewRelationID();
	int _newNodeID;
	int _newRelationID;
};

#endif
