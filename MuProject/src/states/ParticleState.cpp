#include "ParticleState.h"

ParticleState::ParticleState(BaseApp* app):State(app){
	goToFst.loadImage("images/atras.png");
	max=2000;
}

void ParticleState::enter(){
	for (int ch = 0 ; ch< max;ch++)
		particles.push_back(new Particle());
}
void ParticleState::exit(){

}

void ParticleState::update(){
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->update();
}
void ParticleState::draw(){
	State::draw();
	goToFst.draw(0,0);
//	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->draw();
	
}

void ParticleState::mouseMoved(int x, int y){

}
void ParticleState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight())
		reference->setCurrentState(reference->getStateById(0));
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->setVel(3);

}
void ParticleState::mouseReleased(int x, int y, int button){
	cout<<"e";
	for (int ch = 0 ; ch< max;ch++)
		particles[ch]->setVel(6);
}