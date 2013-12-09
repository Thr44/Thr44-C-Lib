/*
 *  StringUtils.cpp
 *  SCPad
 *
 *  Created by machine on 2/4/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#include "StringUtils.h"


vector < string > StringUtils::split(const string & source, const string & delimiters){
	return ofSplitString(source, delimiters);
}

