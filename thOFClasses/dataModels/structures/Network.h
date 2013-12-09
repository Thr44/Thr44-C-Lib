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

#ifndef _NETWORK
#define _NETWORK

//#pragma once
#include "RelationList.h"
#include "NodeList.h"
#include "Relation.h"
#include "Node.h"


struct RelationList;
struct NodeList;
struct Node;
struct Relation;


class Network{
	
public:
	Network();
	NodeList *nodeList;
	RelationList *relationList;
	
	virtual bool addNode(Node *node);
	
	//removes node and its relations:
	virtual bool removeNode(Node *node);
	
	virtual bool addRelation(Node* node0, Node* node1, bool directed);
	virtual bool addRelation(Node* node0, Node* node1);
	virtual bool addRelation(Relation* relation);
	
	//removes relation but leaves node in network!
	virtual bool removeRelation(Relation *relation);
	virtual bool removeRelation(Node* node0, Node* node1);
	
	void printNetwork();
	
protected:
	int getNewNodeID();
	int getNewRelationID();
	int _newNodeID;
	int _newRelationID;
};

#endif
