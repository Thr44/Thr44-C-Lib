/*
 *  Node.cpp
 *  exampleTree
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#include "Node.h"
#include "NodeList.h"
#include "Network.h"

Node::Node(){
	//this->id=id;
	//this->label=label;
	//_treeProperties=NULL;
	nodeList=new NodeList();
	_level=0;
	_isRoot=true;
	_isLeaf=true;
	
}
string Node::toString(){
	return "";
}
string Node::type(){
	return "Node";
}
void Node::setLabel(string labelValue){
	this->label=labelValue;
}
string Node::getLabel(){
	return label;
}

Network* Node::getNetwork(){
	return _network;
}
void Node::setNetwork(Network* network){
	this->_network=network;
	printf("\nadded _network to %s %i\n", this->type().data(), this->_network?true:false);
}

///////tree properties:

bool Node::isLeaf(){
	return _isLeaf;
}
bool Node::isRoot(){
	return _isRoot;
}
int Node::getLevel(){
	return _level;
}
void Node::setAsLeaf(bool isLeaf){
	_isLeaf=isLeaf;
}
void Node::setAsRoot(bool isRoot){
	_isRoot=isRoot;	
}
void Node::setLevel(int level){
	_level=level;
}
void Node::setParent(Node* node){
	_parent=node;
}
Node* Node::getParent(){
	return _parent;
}

///////

bool Node::addNode(Node* node, bool directed){
	printf("\n->adding node %s to %s network: %i\n", node->type().data(), this->type().data(), this->_network?true:false);
	printf("------> %i", _network->nodeList->getNumNodes());
	_network->addNode(node);
	printf("relation:");
	return _network->addRelation(this, node, directed);
}
bool Node::addNode(Node* node){
	return addNode(node, false);
}


bool Node::removeNode(Node* node){
	return _network->removeRelation(this, node);
}





/*TreeProperties* Node::getTreeProperties(){
	if(_treeProperties==NULL){
		_treeProperties=new TreeProperties(this);
	}
	return _treeProperties;
}
 */

void Node::printNode(){
	int i;
	printf("\n\n-node-------------------");
	printf("\n------------------------");
	printf("\nname:      %s", label.data());
	 
	 printf("\nid:      %i", id);
	 printf("\nrelations:       %i", nodeList->getNumNodes());
	 for (i=0; i<nodeList->getNumNodes(); i++) {
	 printf("\n     %i, %s     %s", nodeList->getNodeAt(i)->id, nodeList->getNodeAt(i)->label.data(),nodeList->getNodeAt(i)->type().data());
	 }
	printf("\n------------------------\n");
	/*if(_treeProperties!=NULL){
		printf("\ntreeProperties----------");
		if(!getTreeProperties()->isRoot()) printf("\nparent:, %s", getTreeProperties()->getParent()->label.data());
		printf("\nchildren:");
		for (i=0; i<getTreeProperties()->childList->getNumNodes(); i++) {
			printf("\n     %s ", getTreeProperties()->childList->getNodeAt(i)->label.data());
		}
		printf("\n------------------------\n");
	}
	 */
}
 

