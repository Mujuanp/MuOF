#include "TrdState.h"
TrdState::TrdState(BaseApp* app):State(app){
	camWidth 		= 520;	// try to grab at this size. 
	camHeight 		= 440;
	rotacion=0;
	goToFst.loadImage("images/atras.png");


	ofSetVerticalSync(true);
	

}
void TrdState::exit(){
	vidGrabber.close();
}
void TrdState::enter(){
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth,camHeight);
}
void TrdState::draw(){
	State::draw();
	goToFst.draw(0,0);
	ofTranslate(ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2));
	ofRotateY(rotacion);
	ofSetHexColor(0xffffff);
	vidGrabber.draw(-vidGrabber.getWidth()/2,-vidGrabber.getHeight()/2);
	
}

void TrdState::update(){

	vidGrabber.update();



}
void TrdState::mouseMoved(int x, int y){
		cout<<"x "<<x<<" y "<<y<<"\n";
		rotacion=0.1*(x-ofGetWindowWidth()/2);
	//	ofRotateY(x);

}
void TrdState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight())
		reference->setCurrentState(reference->getStateById(0));
//	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
}

void TrdState::mouseReleased(int x, int y, int button){

}