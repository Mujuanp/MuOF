#include "RotateCamState.h"
RotateCamState::RotateCamState(BaseApp* app):State(app){
	camWidth 		= 520;	// try to grab at this size. 
	camHeight 		= 440;
	rotacion=0;
	goToFst.loadImage("images/atras.png");


	ofSetVerticalSync(true);
	

}
void RotateCamState::exit(){
	vidGrabber.close();
}
void RotateCamState::enter(){
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth,camHeight);
}
void RotateCamState::draw(){
	State::draw();
	goToFst.draw(0,0);
	ofTranslate(ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2));
	ofRotateY(rotacion);
	ofSetHexColor(0xffffff);
	vidGrabber.draw(-vidGrabber.getWidth()/2,-vidGrabber.getHeight()/2);
	
}

void RotateCamState::update(){

	vidGrabber.update();



}
void RotateCamState::mouseMoved(int x, int y){
		cout<<"x "<<x<<" y "<<y<<"\n";
		rotacion=0.1*(x-ofGetWindowWidth()/2);
	//	ofRotateY(x);

}
void RotateCamState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight())
		reference->setCurrentState(reference->getStateById(0));
//	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
}

void RotateCamState::mouseReleased(int x, int y, int button){

}