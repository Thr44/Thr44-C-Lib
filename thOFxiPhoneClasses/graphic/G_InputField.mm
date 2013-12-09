//
//  G_InputField.mm
//  eventsExample
//
//  Created by machine on 8/27/10.
//  Copyright 2010 .. All rights reserved.
//

#import "G_InputField.h"



G_InputField::G_InputField():G(){
	isKeyboardEnabled=false;

	//textField.loadFont("DomesSanNor.ttf", 11);
	keyboard = new ofxiPhoneKeyboard(0,0,100,100);
	
	keyboard->setFontSize(13);
	keyboard->setPlaceholder(textString);
	//keyboard->setFontSize(1);
	keyboard->setFontColor(0, 0, 0, 255);
	keyboard->setBgColor(255, 255, 255, 255);
	keyboard->setVisible(false);
	//printf("~~~~~~~~~A.SETVISIBLE FALSE");
}

void G_InputField::setLabel(string label){
	this->label=label;
}

string G_InputField::getValue(){
	if(this->isVisible() && this->isKeyboardEnabled){
		value=this->keyboard->getText().data();
	}
	if(value.length()!=0) return value.data();
	return this->textString;
}

void G_InputField::setPlaceHolderLabel(string label){
	this->textString=label;
	keyboard->setPlaceholder(textString);
}
/*
void G_InputField::setPosition(float x, float y){
	setPosition(x, y, 0);
}

void G_InputField::setPosition(float x, float y, float z){
	G::setPosition(x, y, z);
	keyboard->setPosition(x, y);
}
 */
void G_InputField::setup(){
	 
	addListener(ThEvent::ORIENTATION_CHANGED, true);
	
}

void G_InputField::setVisible(bool value){
	G::setVisible(value);
	if(value==false && isKeyboardEnabled){
		this->value=keyboard->getText().data();
		keyboard->setVisible(false);
		isKeyboardEnabled=false;
	}

}

void G_InputField::touchDown(int x, int y, int id){
	//printf("\npressed on display keys");
	if(!keyboard->isKeyboardShowing()){
		keyboard->openKeyboard();
		keyboard->setVisible(true);
		//printf("1.SETVISIBLE");
		this->value=keyboard->getText();
		
	} else{
		keyboard->setVisible(false);
	}	
}

void G_InputField::orientationChanged(int newOrientation){
	printf("keyboard orientation!!!!!!!!!");
	keyboard->updateOrientation();
	isKeyboardEnabled=false;
}
void G_InputField::draw(){	
	//font.drawString("teste", 10, 10);
	//printf("\ndraw at key");
	if(isVisible()){
		//printf("\n-isVisible(true)");
		//if(keyboard->updateOrientation(); //limpa tudo, não pode estar aqui
		
		//printf("drawing at InputField");
		ofSetColor(255, 255, 255);
		font.drawString(this->label, this->x, this->y+10);
		
		ofFill();
		ofBeginShape();
		GeometryUtils::drawRoundRect(x+font.stringWidth(label)+2, y, width - font.stringWidth(label)-2, 20, 4);
		ofEndShape(true);
		//
		value=keyboard->getText().data();
		//keyboard->setVisible(true);
		//printf("2.SETVISIBLE");
		//printf("\nkey? %s", isKeyboardEnabled?"true":"false");
		if (!isKeyboardEnabled) {
			//printf("\n!iskeyboardenabled");
			isKeyboardEnabled=true;
			//keyboard->openKeyboard();
			keyboard->setPosition(x+font.stringWidth(label)+4, y+17);
			keyboard->setSize( width-font.stringWidth(label)-8, 16);
			keyboard->setVisible(true);
			//printf("3.SETVISIBLE");
		}else {
			//printf("\nelse");
			//keyboard->setVisible(true);
			//isKeyboardEnabled=false;
			value=keyboard->getText();
			//printf("\n<1.  %s :: %s>", textString.data(), value.data());
		}
		
		
	}else{
		//printf("\n-isVisible(false)");
		
		if(isKeyboardEnabled){
			value=keyboard->getText();
			//FIXME: keyboard->closeKeyboard();
			keyboard->setVisible(false);
			//printf("~~~~~~~~~B.SETVISIBLE FALSE");
			
						
		}
		isKeyboardEnabled=false;
		 

	}
	
} 
	
