/*
 *  HalfMatrix.cpp
 *  SCPad
 *
 *  Created by machine on 7/6/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "HalfMatrix.h"

HalfMatrix::HalfMatrix()
{
	this->numElements=0;
	this->size=0;
}

HalfMatrix::~HalfMatrix(){
	
}
int* HalfMatrix::requestElement(Object* object){
	
	int* response=new int[2];
	int i;
	int index=this->size;
	for(i=this->numElements-1; i>=0; i--){
		if(matrix[i][i]==NULL){
			index=i;
		}else if (object==matrix[i][i]) {
			response[0]=0;
			response[1]=i;
			return response;
		}
	}
	//if(this->matrix[index][index]==NULL){
		//forcesMatrix[i]=[];
	//}
	response[0]=1;
	response[1]=index;
	return response;
}
int HalfMatrix::addElement(Object* object){
	int* request=requestElement(object);
	int index=request[1];
	int i;
	if (request[0]==1) {
		if (size<=index) {
			Vec vec(index+1);
			for(i=0; i<=index; i++) {
				vec[i]=NULL;
			}
			matrix.push_back(vec);
		}
		matrix[index][index]=object;
		//printf("\nadded to matrix %i %s", index, object->type().data());
		this->numElements++;
		this->size++;
		//printf("\n size:%i numElements:%i", this->size, this->numElements);
	}
	/*
	printf("\nMATRIX:\n");
	int j;
	for(i=0; i<numElements; i++){
		printf("\nindex: %i ", i);
		for (j=0; j<=i; j++) {
			printf("\n          %i %s", j, matrix[i][j]==NULL?"NULL":matrix[i][j]->type().data());
		}
	}
	printf("\n.\n");
	*/
	return index;
}
bool HalfMatrix::addElementAt(int i, int j, Object* object){
	//printf("\naddElementAt %i %i %s", i, j, object->type().data());
	matrix[i][j]=object;
	//printf("\n::addElementAt %i %i %s", i, j, matrix[i][j]->type().data());
	return true;
}
Object* HalfMatrix::getElementAt(int i, int j){
	//printf("\n::getElement %i %i %s", i, j, matrix[i][j]?matrix[i][j]->type().data():"no data?");
	return matrix[i][j];
}
	
	/*
	var nodeRequest:Array=requestNode(node); //verify if node was already added
	var nodePhysics:Node=nodeRequest[0];
	var index:int=nodeRequest[1];
	if(nodePhysics==null){
		if(forcesMatrix[index]==null){
			forcesMatrix[index]=[]
			}
			if(nodePhysics is PhysicsForce){
				throw new Error("")
			}
			forcesMatrix[index][index]=node;
			if(index+1>nNodes){
				nNodes++;
			}
			//traceForcesMatrix()
		}
		//trace(node, "++++>>", index);
		return [node, index];
	}
	 */
