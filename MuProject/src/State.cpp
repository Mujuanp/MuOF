#include "State.h"

State::State(BaseApp* app)
{
	reference=app;
	fondo.loadImage("images/fondo.png");
}


State::~State(void)
{
}
void State::keyPressed(int key){

}

//--------------------------------------------------------------
void State::keyReleased(int key){

}

//--------------------------------------------------------------
void State::mouseMoved(int x, int y ){

}



//--------------------------------------------------------------
void State::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void State::mouseReleased(int x, int y, int button){

}

void State::enter(){

}
void State::exit(){

}
void State::update(){

}
void State::draw(){
	fondo.draw(0,0,ofGetWindowSize().x,ofGetWindowSize().y);
}