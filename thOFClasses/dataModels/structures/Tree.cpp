/*
 *  Tree.cpp
 *  exampleTree
 *
 *  Created by machine on 8/9/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#include "Tree.h"

Tree::Tree():Network(){

}

bool Tree::addNode(Node *node){
	//printf("\naddNode @Tree");
	bool added=Network::addNode(node);
	if(added){
		node->setAsLeaf(true);
		node->setAsRoot(true);
		node->setLevel(0);
	}
	return added;
}

bool Tree::removeNode(Node *node){
	RelationList* filteredRelations=relationList->findRelations(node);
	for(int i=0; i<filteredRelations->getNumRelations(); i++){
		removeRelation(filteredRelations->getRelationAt(i));
	}
	node->setNetwork(NULL);
	return nodeList->removeNode(node);
}

bool Tree::addRelation(Node* node0, Node* node1, bool directed){
	Relation* relation=new Relation(node0, node1, true);
	bool added = addRelation(relation);
	if(!added){
		//TODO:delete relation;
	}
	return added;
}
bool Tree::addRelation(Node* node0, Node* node1){
	return addRelation(node0, node1, true);
}
bool Tree::addRelation(Relation *relation){
	relation->id=getNewRelationID();
	bool added = relationList->addRelation(relation);
	relation->getNode0()->nodeList->addNode(relation->getNode1());
	relation->getNode0()->setAsLeaf(false);
	//relation->getNode0()->relationList->addRelation(relation);
	//FIXME: validade if parent was null!!!
	relation->getNode1()->setParent(relation->getNode0());
	relation->getNode1()->setAsRoot(false);
	relation->getNode1()->setLevel(relation->getNode0()->getLevel()+1);
	//relation->getNode1()->relationList->addRelation(relation);
	return added;
}

bool Tree::removeRelation(Relation *relation){
	bool removed=relationList->removeRelation(relation);
	relation->getNode0()->nodeList->removeNode(relation->getNode1());
	if (relation->getNode0()->nodeList->getNumNodes()==0) {
		relation->getNode0()->setAsLeaf(true);
	}
	//relation->getNode0()->relationList->removeNode(relation);
	relation->getNode1()->setParent(NULL);
	//relation->getNode1()->relationList->removeNode(relation);
	return removed;	
}
bool Tree::removeRelation(Node* node0, Node* node1){
	Relation* relation=relationList->findRelation(node0, node1);
	if (relation==NULL) {
		return false;
	}
	return removeRelation(relation);
}

void Tree::printTree(Node* node){
	string depthString="   ";
	string space="";
	for (int j=0; j<node->getLevel(); j++) {
		space+=depthString;
	}
	printf("\n%s|_____>, %i - %s, level: %i", space.data(), node->id, node->getLabel().data(), node->getLevel());
	for(int i=0; i<node->nodeList->getNumNodes(); i++){
		printTree(node->nodeList->getNodeAt(i));
	}
}