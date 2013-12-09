/*
 *  G.h
 *  eventsExample
 *
 *  Created by machine on 8/15/10.
 *  Copyright 2010 .. All rights reserved.
 *
 */

#ifndef _G
#define _G
#include "Object.h"
#include "ofMain.h"
#include "Settings.h"

#include "ThEvent.h"
#include "Globals.h"


class GList;
class G_Tree;

//TODO: make Node protected and allow access to its methods
class G : public Object{
	
public:
	G();
	//~G();
    //gTree:
    GList *childList;
    G_Tree* getGTree();
	void setGTree(G_Tree* gTree);
    int gID;
    virtual void setLabel(string label);
	virtual string getLabel();
    
    //names to be provided for each control parameter:
    vector<string> controlNames;
    
    virtual void setControlNames(vector<string> names);
    //virtual vector<string> getControlNames();
	
	/**
	 adds node to network and creates relation
	 \param node node to be added
	 \return returns a boolean whether it added the node to the network
	 **/
	bool addChild(G* gObject);
	
	/**
	 removes relation to this node
	 \param node related node to remove relation
	 \return returns a boolean whether it added the node to the network
	 **/
	bool removeChild(G* gObject);
    void printG();
    
    
	//ThEvent* tempEvent;
	virtual string toString();
	virtual string type();
	string alignment;
	virtual void setPosition(float x, float y);
	virtual void setPosition(float x, float y, float z);
	virtual void setSize(float width, float height);
	//virtual void addListeners();
	//virtual void removeListeners();
	bool isVisible();
	void setVisible(bool visible);
	float x;
	float y;
	float z;
	//physics properties:
	float vx;
	float vy;
	float vz;
	float ax;
	float ay;
	float az;
	//
	float width;
	float height;
	void updateIfVisible();
	void drawIfVisible();
	virtual void setup();//ofEventArgs & args);
	virtual void update();
	virtual void draw();//ofEventArgs & args);
	
	void addListener(int eventType);
	void addListener(int eventType, bool stopPropagation);
	void removeListener(int eventType);
	
	
	bool isDown;
#ifdef IPHONE
	bool hitTest(ofTouchEventArgs & touch);
	
	void dispatchTouchDown(ofTouchEventArgs & touch);
	virtual void touchDown(ofTouchEventArgs & touch);
	
	void dispatchTouchMoved(ofTouchEventArgs & touch);
	virtual void touchMoved(ofTouchEventArgs & touch);
	void dispatchTouchUp(ofTouchEventArgs & touch);
	virtual void touchUp(ofTouchEventArgs & touch);
	virtual void touchUpOutside(ofTouchEventArgs & touch);
	void dispatchTouchDoubleTap(ofTouchEventArgs & touch);
	virtual void touchDoubleTap(ofTouchEventArgs & touch);
	void dispatchOrientationChanged(int newOrientation);
	virtual void orientationChanged(int newOrientation);
	
	int currentTouchID;
#else
	void dispatchKeyPressed  (int key);
	virtual void keyPressed  (int key);
	void dispatchKeyReleased(int key);
	virtual void keyReleased(int key);
	void dispatchMouseMoved(int x, int y );
	virtual void mouseMoved(int x, int y );
	void dispatchMouseDragged(int x, int y, int button);
	virtual void mouseDragged(int x, int y, int button);
	virtual void mouseDragged(int x, int y, int button, bool isHit);
	void dispatchMousePressed(int x, int y, int button);
	virtual void mousePressed(int x, int y, int button);
	void dispatchMouseReleased(int x, int y, int button);
	virtual void mouseReleased(int x, int y, int button);
	virtual void mouseReleasedOutside(int x, int y, int button);
	void dispatchWindowResized(int w, int h);
	virtual void windowResized(int w, int h);
	
	bool hitTest(ofMouseEventArgs & mouse);
	
#endif
	virtual bool hitTest(int x, int y);
	
protected:
    string label;
    G_Tree* _gTree;
	bool _visible;
	std::vector<ThEvent*> eventsVector;
	 
};

#endif
