/*
 *  GList.cpp
 *  
 *
 *  Created by machine on 8/6/10.
 *  Copyright 2010 ... All rights reserved.
 *
 */


#include "GList.h"
#include "G.h"


GList::GList(){
	size=0;
}
int GList::getSize(){
	return size;
}
bool GList::add(G* gObject){
	int i;
	for(i=0; i<size; i++){
		if(gListVector[i]==gObject){
			//printf("\nnode %i, %s already exists!", node->id, node->label.data());
			return false;
		}
	}
	gListVector.push_back(gObject);
	size++;
	//printf("\nadded node %s at %i and size is %i", node->label.data(), numNodes, (int)nodeListVector.size());
	return true;
}

bool GList::remove(G* gObject){
	int i;
	for(i=0; i<size; i++){
		//printf("\n\nsearching node to remove at %i:: %s --- %s", i, node->label.data(), nodeListVector[i]->label.data());
		if(gListVector[i]==gObject){
			gListVector.erase(gListVector.begin() +i);
			size--;
			//printf("\nremoved %i node. numnodes: %i, size: ", i, numNodes);
			return true;
		}
	}
	return false;
}

G* GList::getGAt(int position){
	return gListVector[position];
}

//Sorting Methods:
/*

void GList::sort(bool func(Node *, Node *)){
	std::sort(nodeListVector.begin(), nodeListVector.end(), func);
}
void NodeList::sortOnID(){
	sort(NodeList::sortOnIDFunction);
}
bool NodeList::sortOnIDFunction(Node* a, Node*b){
	return a->id < b->id;
	
}


*/