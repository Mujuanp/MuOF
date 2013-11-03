#include "Particle.h"

Particle::Particle(){
	vul = 6;
	acc = ofVec2f(0,0.1);
	vel = ofVec2f(ofRandom(-vul,vul),ofRandom(-vul,vul));
	pos = ofVec2f(ofGetMouseX(),ofGetMouseY());

}

void Particle::update(){
	vel+=acc;
	pos+=vel;
	if(pos.y > ofGetWindowHeight() || pos.x<0 || pos.x>ofGetWindowWidth()){
		vel = ofVec2f(ofRandom(-vul,vul),ofRandom(-vul,vul));
		pos = ofVec2f(ofGetMouseX(),ofGetMouseY());
	
	}
}
void Particle::setVel(int nVel){
	vul= nVel;
}

void Particle::draw(){
	
//	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	ofCircle(pos,ofRandom(1,3));
	
}