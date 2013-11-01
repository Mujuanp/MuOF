#include "FstState.h"
FstState::FstState(BaseApp* app) : State(app){
	goToSnd.loadImage("images/snd.jpg");
	goToTrd.loadImage("images/trd.jpg");
	goToFrth.loadImage("images/frth.jpg");
}


FstState::~FstState(void)
{
}
void FstState::draw(){
	ofBackground(100);
	goToSnd.draw(15,15);
	goToTrd.draw(360,15);
	goToFrth.draw(720,15);
}

void FstState::update(){
}

void FstState::mousePressed(int x, int y, int button){
	if(x>=15 && x<=goToSnd.getWidth() && y>=15 && y<=goToSnd.getHeight()){
		reference->setCurrentState(reference->getStateById(0));
		printf("he");

	}
}