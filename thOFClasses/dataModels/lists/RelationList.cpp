/*
 *  RelationList.cpp
 *  exampleTree
 *
 *  Created by machine on 8/9/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#include "RelationList.h"
#include "Relation.h"

RelationList::RelationList():NodeList(){
	
}

bool RelationList::addRelation(Relation* relation){
	return NodeList::addNode((Node*)relation);
}

bool RelationList::removeRelation(Relation* relation){
	return NodeList::removeNode((Node*)relation);
}
int RelationList::getNumRelations(){
	return NodeList::getNumNodes();
}
Relation* RelationList::findRelation(Node* node0, Node* node1){
	for (int i=0; i<getNumNodes(); i++) {
		Relation* relation = (Relation*)getNodeAt(i);
		if ( (relation->getNode0()==node0 && relation->getNode1()==node1) || (relation->getNode0()==node1 && relation->getNode1()==node0) ) {
			return relation;
		}
	}
	return NULL;
}
RelationList* RelationList::findRelations(Node* node){
	RelationList* filteredRelations=new RelationList();
	for (int i=0; i<getNumNodes(); i++) {
		Relation* relation = (Relation*)getNodeAt(i);
		if ( relation->getNode0()==node || relation->getNode1()==node ) {
			filteredRelations->addRelation(relation);
		}
	}
	return filteredRelations;
}

Relation* RelationList::getRelationAt(int position){
	return (Relation*)NodeList::getNodeAt(position);
}