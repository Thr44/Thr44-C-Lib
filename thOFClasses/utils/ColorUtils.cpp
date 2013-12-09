/*
 *  ColorUtils.cpp
 *  exampleTree
 *
 *  Created by machine on 10/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "ColorUtils.h"
#include "NumberUtils.h"
ofColor ColorUtils::randomColor(){
    return ColorUtils::randomColor(255);
}
ofColor ColorUtils::randomColor(float alpha){
	ofColor color=ofColor(round(ofRandom(0, 255)), round(ofRandom(0, 255)), round(ofRandom(0, 255)), alpha);
	return color;
}
ofColor ColorUtils::RGB(float red, float green, float blue){
	return RGB(red, green, blue, 255);
}
ofColor ColorUtils::RGB(float red, float green, float blue, float alpha){
	ofColor color=ofColor(red, green, blue, alpha);
	return color;
}
ofColor ColorUtils::HSV(float hue, float saturation, float value){
	return HSV(hue, saturation, value, 255);
}
ofColor ColorUtils::HSV(float hue, float saturation, float value, float alpha){
    /*
	int i;
	float f;
	float p;
	float q;
	float t;
	ofColor color;
	color.a=alpha;
	if( saturation == 0 ) {
		color.r = color.g = color.b = value;
		return color;
	}
	hue /= 60;
	i = floor(hue);
	f = hue - i;
	p = value*( 1 - saturation );
	q = value*( 1 - saturation * f );
	t = value*( 1 - saturation * ( 1 - f ));
	switch( i ) {
		case 0:
			color.r = value;
			color.g = t;
			color.b = p;
			break;
		case 1:
			color.r = q;
			color.g = value;
			color.b = p;
			break;
		case 2:
			color.r = p;
			color.g = value;
			color.b = t;
			break;
		case 3:
			color.r = p;
			color.g = q;
			color.b = value;
			break;
		case 4:
			color.r = t;
			color.g = p;
			color.b = value;
			break;
		default:
			color.r = value;
			color.g = p;
			color.b = q;
			break;
	}
	return color;
     */
    ofColor color;
    color.setHsb(hue, saturation, value, alpha);
    return color;
}
ofColor ColorUtils::getInterpolatedColor(ofColor &color0, ofColor &color1, float value){
	ofColor color;
	color.r=NumberUtils::getInterpolatedValue(color0.r, color1.r, value);
	color.g=NumberUtils::getInterpolatedValue(color0.g, color1.g, value);
	color.b=NumberUtils::getInterpolatedValue(color0.b, color1.b, value);
	color.a=NumberUtils::getInterpolatedValue(color0.a, color1.a, value);
	return color;
}
ofColor ColorUtils::black(){
	return RGB(0, 0, 0);
}
ofColor ColorUtils::white(){
	return RGB(255, 255, 255);
}


