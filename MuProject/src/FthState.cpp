#include "FthState.h"

FthState::FthState(BaseApp* app):State(app){
	goToFst.loadImage("images/atras.png");
	max=2000;
}

void FthState::enter(){
	for (int ch = 0 ; ch< max;ch++)
		particles.push_back(new Particle());
	

}
void FthState::exit(){

}

void FthState::update(){
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->update();
}
void FthState::draw(){
	State::draw();
	goToFst.draw(0,0);
//	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->draw();
	
}

void FthState::mouseMoved(int x, int y){

}
void FthState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight())
		reference->setCurrentState(reference->getStateById(0));
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->setVel(3);

}
void FthState::mouseReleased(int x, int y, int button){
	cout<<"e";
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->setVel(6);
}