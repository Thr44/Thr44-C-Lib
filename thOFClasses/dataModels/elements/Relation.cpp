/*
 *  Relation.cpp
 *  exampleTree
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#include "Relation.h"
//#include "Node.h"


Relation::Relation(Node* node0, Node* node1, bool directed):Node(){
	//this->id=id;
	this->_node0=node0;
	this->_node1=node1;
	this->directed=directed;
}
Node* Relation::getNode0(){
	return _node0;
}
Node* Relation::getNode1(){
	return _node1;
}