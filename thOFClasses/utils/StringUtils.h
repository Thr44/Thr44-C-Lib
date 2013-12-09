/*
 *  StringUtils.h
 *  SCPad
 *
 *  Created by machine on 2/4/11.
 *  Copyright 2011 .. All rights reserved.
 *
 */

#ifndef _STRINGUTILS
#define _STRINGUTILS

#pragma once
#include "ofMain.h"
#include "ofUtils.h"

class StringUtils {
public:
	vector <string> split(const string & source, const string & delimiters);
	//string join(vector <string> stringElements, const string & delimiter);
};
#endif