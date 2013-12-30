#include "GeometryState.h"

GeometryState::GeometryState(BaseApp* app) : State(app){
	goToFst.loadImage("images/atras.png");

}

void GeometryState::enter(){
	//	vector<ofVec2f> puntos= vector<ofVec2f>();
	//	for(float w= 0.0 ;w<1; w+=0.1){
	//		
	//		for(float h= 0.0 ;h<1; h+=0.1){
	//			puntos.push_back( ofVec2f(w,h));
	//		}
	//	}
	sphere = Sphere(ofRandom(10,300),30,30);
	//	toro= Toro(ofRandom(10,100),ofRandom(120,300),30,30);
}
void GeometryState::exit(){

}

void GeometryState::update(){

}
void GeometryState::draw(){
	State::draw();
	goToFst.draw(0,0);
	//cylinder.draw();
//	toro.draw();
	sphere.draw();
}

void GeometryState::mouseMoved(int x, int y){

}
void GeometryState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight())
		reference->setCurrentState(reference->getStateById(0));


}
void GeometryState::mouseReleased(int x, int y, int button){

}