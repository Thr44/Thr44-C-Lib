/*
 *  GeometryUtils.cpp
 *  eventsExample
 *
 *  Created by machine on 8/26/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "GeometryUtils.h"
#include <math.h>

void GeometryUtils::drawRoundRect(float x, float y, float width, float height, float cornerRadius){
	ofVertex(x+cornerRadius, y);
	ofVertex(x+width-cornerRadius, y);
	GeometryUtils::quadraticBezierVertex(x+width, y, x+width, y+cornerRadius, x+width-cornerRadius, y);
	ofVertex(x+width, y+height-cornerRadius);
	GeometryUtils::quadraticBezierVertex(x+width, y+height, x+width-cornerRadius, y+height, x+width, y+height-cornerRadius);
	ofVertex(x+cornerRadius, y+height);
	GeometryUtils::quadraticBezierVertex(x, y+height, x, y+height-cornerRadius, x+cornerRadius, y+height);
	ofVertex(x, y+cornerRadius);
	GeometryUtils::quadraticBezierVertex(x, y, x+cornerRadius, y, x, y+cornerRadius);
}

//FIXME: method not tested!!
void GeometryUtils::drawArc(float x,float y, float radius, float lowAngle, float highAngle, bool closed, bool filled){
	float n1=floorf(ofRadToDeg(abs(highAngle-lowAngle) * 0.05)) * 2.0;
	int n2=ceil(n1);
	int numCirclePts = max(n2, 4);
	//printf("points: %f %f %i", lowAngle, highAngle, numCirclePts);
	float circlePtsScaled[numCirclePts * 2];
	
	float angle;
	float angleRange;
	float angleAdder;
	if(highAngle>lowAngle){
		angleRange=highAngle-lowAngle;
		angle=lowAngle;
		angleAdder=(angleRange / ((float)numCirclePts-1));
	}else{
		angleRange=highAngle-lowAngle;//(M_TWO_PI - lowAngle + highAngle);
		angle=lowAngle;
		angleAdder=(angleRange / ((float)numCirclePts-1));
	}
	
	int k = 0;
	
	for (int i = 0; i < numCirclePts; i++){
		circlePtsScaled[k] = x + cos(angle) * radius;
		circlePtsScaled[k+1] = y - sin(angle) * radius;
		angle += angleAdder;
		k+=2;
	}
	
	// we draw the circle points ourself (vs. glDrawArrays) because it allows us to draw the center point, and have the triangles fan around it
	k = 0;
	
	for (int i = 0; i < numCirclePts; i++){
		ofVertex(circlePtsScaled[k], circlePtsScaled[k+1]);
		//glVertex2f(circlePtsScaled[k], circlePtsScaled[k+1]);
		k+=2;
	}
	
}
	


#ifdef IPHONE
/*
bool GeometryUtils::hitTest(G * object, ofTouchEventArgs & touch){
	if(touch.x > object->x && touch.x < (object->x+object->width) && touch.y > object->y && touch.y < (object->y+object->height)){
		return true;
	}
	return false;
}
 */
bool GeometryUtils::hitTest(float x, float y, float w, float h, ofTouchEventArgs & touch){
	return hitTest(x, y, w, h, touch.x, touch.y);
}
bool GeometryUtils::hitTest(float x, float y, float radius, ofTouchEventArgs & touch){
	return hitTest(x, y, radius, touch.x, touch.y);
}
#else
/*
bool GeometryUtils::hitTest(G * object, ofMouseEventArgs & mouse){
	if(mouse.x > object->x && mouse.x < (object->x+object->width) && mouse.y > object->y && mouse.y < (object->y+object->height)){
		return true;
	}
	return false;
}
 */
bool GeometryUtils::hitTest(float x, float y, float w, float h,  ofMouseEventArgs & mouse){
	return hitTest(x, y, w, h, mouse.x, mouse.y);
}
bool GeometryUtils::hitTest(float x, float y, float radius, ofMouseEventArgs & mouse){
	return hitTest(x, y, radius, mouse.x, mouse.y);
}
#endif

bool GeometryUtils::hitTest(float x, float y, float w, float h,  float hitX, float hitY){
	if(hitX > x && hitX < (x+w) && hitY > y && hitY < (y+h)){
		return true;
	}
	return false;
}
bool GeometryUtils::hitTest(float x, float y, float radius,  float hitX, float hitY){
	if(ofDist(x, y, hitX, hitY)<radius){
		return true;
	}
	return false;
}


void GeometryUtils::quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY) {
	float cp1x = prevX + 2.0/3.0*(cpx - prevX);
	float cp1y = prevY + 2.0/3.0*(cpy - prevY);
	float cp2x = cp1x + (x - prevX)/3.0;
	float cp2y = cp1y + (y - prevY)/3.0;
	
	// finally call cubic Bezier curve function
	ofBezierVertex(cp1x, cp1y, cp2x, cp2y, x, y);
};
