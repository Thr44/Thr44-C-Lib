/*
 *  G_Canvas.h
 *
 *  Created by machine on 11/11/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G_CANVAS
#define _G_CANVAS

#include "G_Tree.h"
#include "G.h"

class G_Canvas : public G{

public:
	G_Canvas();
	G_Tree* tree;
	
	virtual string toString();
	virtual string type();
	
};

#endif