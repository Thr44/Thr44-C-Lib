/*
 *  Network.cpp
 *  exampleTree
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#include "Network.h"

Network::Network(){
	//printf("\nnew network");
	_newNodeID=0;
	_newRelationID=0;
	nodeList=new NodeList();
	relationList=new RelationList();
}
bool Network::addNode(Node *node){
	printf("\naddNode @Network");
	node->setNetwork(this);
	node->id=getNewNodeID();
	return nodeList->addNode(node);
	
}
bool Network::removeNode(Node *node){
	RelationList* filteredRelations=relationList->findRelations(node);
	for(int i=0; i<filteredRelations->getNumRelations(); i++){
		removeRelation(filteredRelations->getRelationAt(i));
	}
	node->setNetwork(NULL);
	return nodeList->removeNode(node);
}
int Network::getNewNodeID(){
	int id=_newNodeID;
	_newNodeID++;
	//printf("\ncreating ID: %i\n", id);
	return id;
}
int Network::getNewRelationID(){
	int id=_newRelationID;
	_newRelationID++;
	return id;
}
bool Network::addRelation(Node* node0, Node* node1, bool directed){
	printf("\n.1");
	Relation* relation=new Relation(node0, node1, directed);
	printf("\n.2");
	bool added = addRelation(relation);
	if(!added){
		//TODO:delete relation;
	}
	return added;
}
bool Network::addRelation(Node* node0, Node* node1){
	return addRelation(node0, node1, false);
}
bool Network::addRelation(Relation *relation){
	relation->id=getNewRelationID();
	bool added = relationList->addRelation(relation);
	relation->getNode0()->nodeList->addNode(relation->getNode1());
	relation->getNode0()->relationList->addRelation(relation);
	relation->getNode1()->nodeList->addNode(relation->getNode0());
	relation->getNode1()->relationList->addRelation(relation);
	return added;
}

bool Network::removeRelation(Relation *relation){
	bool removed=relationList->removeRelation(relation);
	relation->getNode0()->nodeList->removeNode(relation->getNode1());
	relation->getNode0()->relationList->removeRelation(relation);
	relation->getNode1()->nodeList->removeNode(relation->getNode0());
	relation->getNode1()->relationList->removeRelation(relation);
	return removed;	
}
bool Network::removeRelation(Node* node0, Node* node1){
	Relation* relation=relationList->findRelation(node0, node1);
	if (relation==NULL) {
		return false;
	}
	return removeRelation(relation);
}

void Network::printNetwork(){
	int i;
	printf("\n\n=======properties====");
	printf("\nnNodes			%i", nodeList->getNumNodes());
	printf("\nnRelations		%i , asortativity= %i / %f = %f", relationList->getNumRelations(), relationList->getNumRelations(), (nodeList->getNumNodes()*(nodeList->getNumNodes()-1.0)/2.0), (2.0*relationList->getNumRelations()/(nodeList->getNumNodes()*(nodeList->getNumNodes()-1.0))) );
	
	
	 printf("=======relations=====");
	 for (i=0; i<relationList->getNumRelations(); i++) {
		 printf("%s - %s", relationList->getRelationAt(i)->getNode0()->getLabel().data(), relationList->getRelationAt(i)->getNode1()->getLabel().data());
	 }
	
	 printf("\n\n=======nodoSs==========");
	for (i=0; i<nodeList->getNumNodes(); i++) {
		nodeList->getNodeAt(i)->printNode();//nodeArray[i].traceNode();
	}
}