/*
 *  G_TRee.cpp
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */

#include "G_Tree.h"

G_Tree::G_Tree(){
	//printf("\nnew network");
	_newNodeID=0;
	childList=new GList();
	//relationList=new RelationList();
}
bool G_Tree::addChild(G *node){
	//printf("\naddNode @Tree");
    node->setGTree(this);
	node->gID=getNewNodeID();
	bool added=childList->add(node);

    /*
	if(added){
		node->setAsLeaf(true);
		node->setAsRoot(true);
		node->setLevel(0);
	}
     */
	return added;
}

bool G_Tree::removeChild(G *node){
	/*RelationList* filteredRelations=relationList->findRelations(node);
	for(int i=0; i<filteredRelations->getNumRelations(); i++){
		removeRelation(filteredRelations->getRelationAt(i));
	}
     */
    node->setGTree(NULL);
	return childList->remove(node);
}

bool G_Tree::addRelation(G* node0, G* node1, bool directed){
    node1->setGTree(this);
	node0->childList->add(node1);
    
	//relation->getNode0()->setAsLeaf(false);
	//relation->getNode0()->relationList->addRelation(relation);
	//FIXME: validade if parent was null!!!
        //relation->getNode1()->setParent(relation->getNode0());
        //relation->getNode1()->setAsRoot(false);
        //relation->getNode1()->setLevel(relation->getNode0()->getLevel()+1);
	//relation->getNode1()->relationList->addRelation(relation);
	return true;//added;
}
bool G_Tree::addRelation(G* node0, G* node1){
	return addRelation(node0, node1, true);
}



bool G_Tree::removeRelation(G* node0, G* node1){
	node0->childList->remove(node1);
    /*
	if (relation->getNode0()->nodeList->getNumNodes()==0) {
		relation->getNode0()->setAsLeaf(true);
	}
     */
	//relation->getNode0()->relationList->removeNode(relation);
        //relation->getNode1()->setParent(NULL);
	//relation->getNode1()->relationList->removeNode(relation);
	return true;	

}
int G_Tree::getNewNodeID(){
	int id=_newNodeID;
	_newNodeID++;
	//printf("\ncreating ID: %i\n", id);
	return id;
}



void G_Tree::printNetwork(){
	int i;
	printf("\n\n=======properties====");
	printf("\nnGs			%i", childList->getSize());
		
    printf("\n\n=======Gs==========");
	for (i=0; i<childList->getSize(); i++) {
		childList->getGAt(i)->printG();//nodeArray[i].traceNode();
	}
}