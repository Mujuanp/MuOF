#include "FstState.h"

FstState::FstState(BaseApp* app) : State(app){
	goToSnd.loadImage("images/snd.jpg");
	goToTrd.loadImage("images/trd.jpg");
	goToFth.loadImage("images/fth.jpg");
	c=0;
}


FstState::~FstState(void)
{
}


void FstState::draw(){
	State::draw();
	goToSnd.draw(15,15);
	goToTrd.draw(360,15);
	goToFth.draw(720,15);
}
void FstState::enter(){

}

void FstState::exit(){

}
void FstState::update(){
}

void FstState::mousePressed(int x, int y, int button){
	
	
	if(x>=15 && x<=goToSnd.getWidth()+15 && y>=15 && y<=goToSnd.getHeight()+15)
		reference->setCurrentState(reference->getStateById(1));
	if(x>=360 && x<=goToTrd.getWidth()+360 && y>=15 && y<=goToTrd.getHeight()+15)
		reference->setCurrentState(reference->getStateById(2));
	if(x>=720 && x<=goToFth.getWidth()+720 && y>=15 && y<=goToFth.getHeight()+15)
		reference->setCurrentState(reference->getStateById(3));
	

}
void FstState::mouseMoved(int x, int y ){

}
void FstState::mouseReleased(int x, int y, int button){

}