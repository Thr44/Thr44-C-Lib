/*
 *  G_Canvas.cpp
 *  exampleTree
 *
 *  Created by machine on 11/11/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G_Canvas.h"

G_Canvas::G_Canvas():G(){
	tree=new G_Tree();
	tree->addChild(this);
	//
	/*
	this->addListener(ThEvent::MOUSE_RELEASED, true);
	this->addListener(ThEvent::MOUSE_PRESSED, true);
	this->addListener(ThEvent::MOUSE_DRAGGED, false);
	 */
	
}
string G_Canvas::toString(){
	return "";
}
string G_Canvas::type(){
	return "G_Canvas";
}
