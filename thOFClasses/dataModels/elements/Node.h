/*
 *  Node.h
 *  
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#ifndef _NODE
#define _NODE

//#pragma once
#include "Object.h"

//#include "NodeList.h"
#include "ofMain.h"
//#include "ofxVectorMath.h"
//#include "Network.h"


class NodeList;
class RelationList;
class Network;

/**
 * A Node
 **/
class Node:public Object{
	
public:
	
	/**
	 A Node´
	 \sa Network
	 **/
	Node();
	
	NodeList *nodeList;
	RelationList *relationList;
	int id;
	/**
	  Set the node's label
	  \param label the label to be assigned to ndoe
	 **/
	virtual void setLabel(string label);
	virtual string getLabel();
	virtual string toString();
	virtual string type();
	Network* getNetwork();
	void setNetwork(Network* network);
	
	/**
	 adds node to network and creates relation
	 \param node node to be added
	 \return returns a boolean whether it added the node to the network
	 **/
	bool addNode(Node* node);
	bool addNode(Node* node, bool directed);
	
	/**
	 removes relation to this node
	 \param node related node to remove relation
	 \return returns a boolean whether it added the node to the network
	 **/
	bool removeNode(Node* node);
	bool isLeaf();
	bool isRoot();
	int getLevel();
	void setAsLeaf(bool isLeaf);
	void setAsRoot(bool isRoot);
	void setLevel(int level);
	void setParent(Node* node);
	Node* getParent();
	
	
	//TreeProperties* getTreeProperties();
	void printNode();
	
	//tridimensional:
	ofVec4f position;
	
	//physics:
	ofVec3f velocity;
	ofVec3f acceleration;
	
	
protected:
	string label;
	Network* _network;
	bool _isLeaf;
	bool _isRoot;
	int _level;
	Node* _parent;
	
	//extensions:
	//TreeProperties* _treeProperties;
	
	
	
};

#endif

