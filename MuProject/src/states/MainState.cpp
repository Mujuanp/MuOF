#include "MainState.h"

MainState::MainState(BaseApp* app) : State(app){
	goToMoveCamState.loadImage("images/moveCamState.png");
	goToRotateCamState.loadImage("images/rotateCamState.png");
	goToParticleState.loadImage("images/particleState.png");
	goToGeometryState.loadImage("images/geometryState.png");
	goToCamShaderState.loadImage("images/shaderCamState.png");
	c=0;
}


MainState::~MainState(void)
{
}


void MainState::draw(){
	State::draw();
	goToMoveCamState.draw(15,15);
	goToRotateCamState.draw(goToMoveCamState.getWidth()+30,15);
	goToParticleState.draw(goToMoveCamState.getWidth()+goToRotateCamState.getWidth()+45,15);
	goToGeometryState.draw(15,271);
	goToCamShaderState.draw(goToGeometryState.getWidth()+30,271);
}
void MainState::enter(){

}

void MainState::exit(){

}
void MainState::update(){
}

void MainState::mousePressed(int x, int y, int button){
	
	
	if(x>=15 && x<=goToMoveCamState.getWidth()+15 && y>=15 && y<=goToMoveCamState.getHeight()+15)
		reference->setCurrentState(reference->getStateById(1));
	else if(x>=goToMoveCamState.getWidth()+30 && x<=goToRotateCamState.getWidth()+goToMoveCamState.getWidth()+30 && y>=15 && y<=goToRotateCamState.getHeight()+15)
		reference->setCurrentState(reference->getStateById(2));
	else if(x>=goToMoveCamState.getWidth()+goToRotateCamState.getWidth()+45 && x<=goToParticleState.getWidth()+goToMoveCamState.getWidth()+goToRotateCamState.getWidth()+45 && y>=15 && y<=goToParticleState.getHeight()+15)
		reference->setCurrentState(reference->getStateById(3));
	else if(x>=15 && x<=goToGeometryState.getWidth()+15 && y>=271 && y<=goToGeometryState.getHeight()+271)
		reference->setCurrentState(reference->getStateById(4));
	else if(x>=goToGeometryState.getWidth()+30 && x<=goToGeometryState.getWidth()+goToCamShaderState.getWidth()+30 && y>=271 && y<=goToCamShaderState.getHeight()+271)
		reference->setCurrentState(reference->getStateById(5));
	

}
void MainState::mouseMoved(int x, int y ){

}
void MainState::mouseReleased(int x, int y, int button){

}