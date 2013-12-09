/*
 *  NodeList.cpp
 *  
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */


#include "NodeList.h"
#include "Node.h"


NodeList::NodeList(){
	numNodes=0;
}
int NodeList::getNumNodes(){
	return numNodes;
}
bool NodeList::addNode(Node* node){
	int i;
	for(i=0; i<numNodes; i++){
		if(nodeListVector[i]==node){
			//printf("\nnode %i, %s already exists!", node->id, node->label.data());
			return false;
		}
	}
	nodeListVector.push_back(node);
	numNodes++;
	//printf("\nadded node %s at %i and size is %i", node->label.data(), numNodes, (int)nodeListVector.size());
	return true;
}

bool NodeList::removeNode(Node* node){
	int i;
	for(i=0; i<numNodes; i++){
		//printf("\n\nsearching node to remove at %i:: %s --- %s", i, node->label.data(), nodeListVector[i]->label.data());
		if(nodeListVector[i]==node){
			nodeListVector.erase(nodeListVector.begin() +i);
			numNodes--;
			//printf("\nremoved %i node. numnodes: %i, size: ", i, numNodes);
			return true;
		}
	}
	return false;
}

Node* NodeList::getNodeAt(int position){
	return nodeListVector[position];
}

//Sorting Methods:

	
void NodeList::sort(bool func(Node *, Node *)){
	std::sort(nodeListVector.begin(), nodeListVector.end(), func);
}
void NodeList::sortOnID(){
	sort(NodeList::sortOnIDFunction);
}
bool NodeList::sortOnIDFunction(Node* a, Node*b){
	return a->id < b->id;
	
}
