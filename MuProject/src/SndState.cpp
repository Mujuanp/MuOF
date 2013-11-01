#include "SndState.h"
SndState::SndState(BaseApp* app) : State(app){
	goToFst.loadImage("images/atras.png");
}


SndState::~SndState(void)
{
}
void SndState::draw(){
	State::draw();


	goToFst.draw(0,0);
}

void SndState::update(){
}

void SndState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight()){
		reference->setCurrentState(reference->getStateById(0));
	

	}
}