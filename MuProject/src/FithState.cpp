#include "FithState.h"

FithState::FithState(BaseApp* app) : State(app){
	goToFst.loadImage("images/atras.png");

}

void FithState::enter(){
	vector<ofVec2f> puntos= vector<ofVec2f>();
	for(float w= 0.0 ;w<1; w+=0.1){
		for(float h= 0.0 ;h<1; h+=0.1){
			puntos.push_back( ofVec2f(w,h));
		}
	}
	cylinder= Cylinder(puntos);
}
void FithState::exit(){

}

void FithState::update(){
	
}
void FithState::draw(){
		State::draw();
		cylinder.draw();

}

void FithState::mouseMoved(int x, int y){

}
void FithState::mousePressed(int x, int y, int button){
	

}
void FithState::mouseReleased(int x, int y, int button){

}