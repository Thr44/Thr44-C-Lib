/*
 *  G.cpp
 *  eventsExample
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#include "G.h"
#include "GList.h"
#include "G_Tree.h"

//#include "ofxVec2f.h"

G::G(){
    childList=new GList();
	isDown=false;
	alignment="TOP_LEFT";
	this->x=0;
	this->y=0;
	this->z=0;
	this->vx=0;
	this->vy=0;
	this->vz=0;
	this->ax=0;
	this->ay=0;
	this->az=0;
	
	//addListener(ThEvent::MOUSE_PRESSED, true);
	//addListener(ThEvent::MOUSE_RELEASED, true);
	this->setVisible(true);
	//addListeners();
}
/*G::~G(){
	
}*/
string G::toString(){
	return "";
}
string G::type(){
	return "G";
}
void G::setLabel(string labelValue){
	this->label=labelValue;
}
string G::getLabel(){
	return label;
}
void G::setControlNames(vector<string> names){
    this->controlNames=names;
}
/*
 vector<string> G_ScatterXY::getControlNames(){
 
 }
 */

G_Tree* G::getGTree(){
	return _gTree;
}
void G::setGTree(G_Tree* gTree){
	this->_gTree=gTree;
	printf("\nadded _network to %s %i\n", this->type().data(), this->_gTree?true:false);
}
void G::printG(){
	int i;
	printf("\n\n-G-------------------");
	printf("\n------------------------");
    
    printf("\nid:      %i", gID);
   
    for (i=0; i<childList->getSize(); i++) {
        printf("\n     %i, %s     %s", childList->getGAt(i)->gID, childList->getGAt(i)->type().data(), childList->getGAt(i)->getLabel().data());
    }
	printf("\n------------------------\n");
	/*if(_treeProperties!=NULL){
     printf("\ntreeProperties----------");
     if(!getTreeProperties()->isRoot()) printf("\nparent:, %s", getTreeProperties()->getParent()->label.data());
     printf("\nchildren:");
     for (i=0; i<getTreeProperties()->childList->getNumNodes(); i++) {
     printf("\n     %s ", getTreeProperties()->childList->getNodeAt(i)->label.data());
     }
     printf("\n------------------------\n");
     }
	 */
}
bool G::addChild(G* gObject){
	printf("\n->adding node %s to %s network: %i\n", gObject->type().data(), this->type().data(), this->_gTree?true:false);
	//printf("------> %i", _gTree->childList->getSize());
	
	//printf("relation:");
	//return _network->addRelation(this, node, directed);
    return _gTree->addRelation(this, gObject);
}



bool G::removeChild(G* gObject){
	return _gTree->removeRelation(this, gObject);
}


bool G::isVisible(){
	return _visible;
}
void G::setVisible(bool visible){
	_visible=visible;
}
void G::updateIfVisible(){
	if(isVisible()){
		update();
		for(int j=childList->getSize()-1; j>=0; j--){
			G* n = childList->getGAt(j);
			n->updateIfVisible();
		}
	}
}
void G::drawIfVisible(){
	if(isVisible()){
		draw();
		for(int j=childList->getSize()-1; j>=0; j--){
			G* n = childList->getGAt(j);
			n->drawIfVisible();
		}
	}
}

#ifdef IPHONE //----------------------------------------------------------------------------------------------------------------------------//

bool G::hitTest(ofTouchEventArgs & touch){
	return hitTest(touch.x, touch.y);
	/*
	if(touch.x > this->x && touch.x < (this->x+this->width) && touch.y > this->y && touch.y < (this->y+this->height)){
		return true;
	}
	return false;
	 */
}

void G::dispatchTouchDown(ofTouchEventArgs & touch){
	//printf("dispatchTouchDown");
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::TOUCH_DOWN){
			bool isHit=hitTest(touch.x, touch.y);
			if(isHit && isVisible()){
				currentTouchID=touch.id;
				printf("touchDown, %s %s %i", this->type().data(),this->getLabel().data(),  currentTouchID);
				isDown=true;
				touchDown(touch);
			}
			if(isHit && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
	}
	for(int j=childList->getSize()-1; j>=0; j--){
        G* n = childList->getGAt(j);
		n->dispatchTouchDown(touch);
	}
}

void G::dispatchTouchUp(ofTouchEventArgs & touch){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::TOUCH_UP){
			bool isHit=hitTest(touch.x, touch.y);
			if(isHit && touch.id==currentTouchID ){
				touchUp(touch);
				isDown=false;
			}
			else if(isDown && touch.id==currentTouchID && isVisible()){
				isDown=false;
				touchUpOutside(touch);
			}
			if(isHit && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
	}
	for(int j=childList->getSize()-1; j>=0; j--){
        G* n = childList->getGAt(j);
		n->dispatchTouchUp(touch);
	}
	
}

void G::dispatchTouchMoved(ofTouchEventArgs & touch){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::TOUCH_MOVED){
			//bool isHit=hitTest(x, y);
			//printf("\n %s %s\n", this->getLabel().data(), this->isVisible()?"true":"false");
			if(touch.id==currentTouchID && isVisible()){
				printf("touchMoved %s %s %i", this->type().data(), this->getLabel().data(), currentTouchID);
				touchMoved(touch);
			} 
			if(touch.id==currentTouchID && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
		
	}
	for(int j=childList->getSize()-1; j>=0; j--){
        G* n = childList->getGAt(j);
		n->dispatchTouchMoved(touch);
	}
}

void G::dispatchTouchDoubleTap(ofTouchEventArgs & touch){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::TOUCH_DOUBLE_TAP){
			bool isHit=hitTest(touch.x, touch.y);
			if(isHit && isVisible()) touchDoubleTap(touch);
			if(isHit && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
		
	}
	for(int j=childList->getSize()-1; j>=0; j--){
        G* n = childList->getGAt(j);
		n->dispatchTouchMoved(touch);
	}
}

void G::dispatchOrientationChanged(int newOrientation){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::ORIENTATION_CHANGED){
			orientationChanged(newOrientation);
		}
		
	}
	for(int j=childList->getSize()-1; j>=0; j--){
        G* n = childList->getGAt(j);
		n->dispatchOrientationChanged(newOrientation);
	}
}

void G::touchDown(ofTouchEventArgs & touch){
	printf("touchDown@G");
}
void G::touchUp(ofTouchEventArgs & touch){
	printf("touchUp@G");
}
void G::touchUpOutside(ofTouchEventArgs & touch){
	printf("touchUpOutside@G");
}
void G::touchMoved(ofTouchEventArgs & touch){
	printf("touchMoved@G");
}
void G::touchDoubleTap(ofTouchEventArgs & touch){
	printf("touchDoubleTap@G");
}

void G::orientationChanged(int newOrientation){
	printf("orientationChanged@G");
}

#else //------------------------------------------------------------------------------------------------------------------------------------//
bool G::hitTest(ofMouseEventArgs & mouse){
	return hitTest(mouse.x, mouse.y);
	/*
	if(mouse.x > this->x && mouse.x < (this->x+this->width) && mouse.y > this->y && mouse.y < (this->y+this->height)){
		return true;
	}
	return false;
	 */
}

void G::dispatchKeyPressed(int key){
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::KEY_PRESSED){
			keyPressed(key);
			if(event->stopPropagation){
				return;
			}
		}
		
	}
	//changed this so that it dispatches event to children, even if it does't have the event itself
	for(int j=childList->getNumObjects()-1; j>=0; j--){
		G* n = (G*)childList->getObjectAt(j);
		n->dispatchKeyPressed(key);
	}
}
void G::dispatchKeyReleased(int key){
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::KEY_RELEASED){
			keyReleased(key);
			if(event->stopPropagation){
				return;
			}
		}
	}
    for(int j=childList->getNumObjects()-1; j>=0; j--){
		G* n = (G*)childList->getObjectAt(j);
		n->dispatchKeyReleased(key);
	}
	
}
void G::dispatchMouseMoved(int x, int y){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::MOUSE_MOVED){
			bool isHit=hitTest(x, y);
			if(isHit) mouseMoved(x, y);
			if(isHit && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
		
	}
	for(int j=childList->getNumObjects()-1; j>=0; j--){
		G* n = (G*)childList->getObjectAt(j);
		n->dispatchMouseMoved(x, y);
	}
}

void G::dispatchMouseDragged(int x, int y, int button){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::MOUSE_DRAGGED){
			printf("%s has event MOUSE_DRAGGED", this->type().data());
			bool isHit=hitTest(x, y);
			if(isHit) mouseDragged(x, y, button, true);
			else {
				mouseDragged(x, y, button, false);
			}
			
			if(isHit && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
	}
	for(int j=childList->getNumObjects()-1; j>=0; j--){
		G* n = (G*)childList->getObjectAt(j);
		printf("\ncalling dispatch at child: %s\n", n->type().data());
		n->dispatchMouseDragged(x, y, button);
	}
}
void G::dispatchMousePressed(int x, int y, int button){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::MOUSE_PRESSED){
			bool isHit=hitTest(x, y);
			if(isHit){
				isDown=true;
				mousePressed(x, y, button);
			}
			if(isHit && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
	}
	for(int j=childList->getNumObjects()-1; j>=0; j--){
		G* n = (G*)childList->getObjectAt(j);
		n->dispatchMousePressed(x, y, button);
	}
}
void G::dispatchMouseReleased(int x, int y, int button){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::MOUSE_RELEASED){
			bool isHit=hitTest(x, y);
			if(isHit){
				mouseReleased(x, y, button);
			}
			else if(isDown){
				isDown=false;
				mouseReleasedOutside(x, y, button);
			}
			if(isHit && event->stopPropagation){
				//stopEvent=true;
				return;
			}
		}
	}
	for(int j=childList->getNumObjects()-1; j>=0; j--){
		G* n = (G*)childList->getObjectAt(j);
		n->dispatchMouseReleased(x, y, button);
	}
	
}
void G::dispatchWindowResized(int w, int h){
	//bool stopEvent=false;
	for(int i=0; i<eventsVector.size(); i++){
		ThEvent* event = eventsVector[i];
		if(event->eventType==ThEvent::WINDOW_RESIZED){
			windowResized(w, h);
			if(event->stopPropagation){
				return;
			}
		}
	}
	for(int j=childList->getNumObjects()-1; j>=0; j--){
		G* n = (G*)childList->getObjectAt(j);
		n->dispatchWindowResized(w, h);
	}
}


//--------------------------------------------------------------
void G::keyPressed(int key){
	
}

//--------------------------------------------------------------
void G::keyReleased(int key){
	
}

//--------------------------------------------------------------
void G::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void G::mouseDragged(int x, int y, int button){
	mouseDragged(x, y, button, false);
}
void G::mouseDragged(int x, int y, int button, bool isHit){
	printf("mouseDragged at G, %i", isHit);
}

//--------------------------------------------------------------
void G::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void G::mouseReleased(int x, int y, int button){
	
}
void G::mouseReleasedOutside(int x, int y, int button){
	
}

//--------------------------------------------------------------
void G::windowResized(int w, int h){
	
}

#endif
bool G::hitTest(int x, int y){
	ofVec2f* point=new ofVec2f(x,y);
/*
#ifdef IPHONE
	
	switch (orientation) {
		case 2:
			point->set(x-ofGetScreenWidth(), y-ofGetScreenHeight());
			point->rotate(-180);
			break;
		case 3:
			point->set(x-ofGetScreenWidth(), y);
			point->rotate(-90);
			break;
		case 4:
			point->set(x, y-ofGetScreenHeight());
			point->rotate(90);
			break;
		default:
			break;
	}
	 
#endif
 */
	if(point->x > this->x && point->x < (this->x+this->width) && point->y > this->y && point->y < (this->y+this->height)){
		return true;
	}
	return false;
}
void G::setup(){//ofEventArgs & args){
	
}
void G::update(){
	
}

void G::draw(){//ofEventArgs & args){
	
}

void G::setPosition(float x, float y, float z){
	this->x=x;
	this->y=y;
	this->z=z;
}
void G::setPosition(float x, float y){
	setPosition(x, y, 0);
}
void G::setSize(float width, float height){
	this->width=width;
	this->height=height;
}


//EVENTS:
void G::addListener(int eventType){
	addListener(eventType, false);
}
void G::addListener(int eventType, bool stopPropagation){
	eventsVector.push_back(new ThEvent(eventType, stopPropagation));
}
void G::removeListener(int eventType){
	for(int i=0; i<eventsVector.size(); i++){
		if(eventsVector[i]->eventType==eventType){
			eventsVector.erase(eventsVector.begin() +i);
			return;		
		}
	}
}



