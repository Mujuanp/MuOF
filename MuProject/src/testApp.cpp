#include "testApp.h"
#include "states/State.h"

//--------------------------------------------------------------
void testApp::setup(){
	current= new MainState((BaseApp*)this);
	states.push_back(current);
	states.push_back(new MoveCamState((BaseApp*)this));
	states.push_back(new RotateCamState((BaseApp*)this));
	states.push_back(new ParticleState((BaseApp*)this));
	states.push_back(new GeometryState((BaseApp*)this));
	states.push_back(new CamShaderState((BaseApp*)this));
}



//--------------------------------------------------------------
void testApp::update(){
	current->update();
}

//--------------------------------------------------------------
void testApp::draw(){
	current->draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	current->mouseMoved(x,y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	current->mousePressed(x,y,button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	current->mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

vector<State*>* testApp::getStates(){
	return &states;
}
State* testApp::getCurrentState(){
	return current;
}
State* testApp::getStateById(int id){
	return states[id];
}
void testApp::setCurrentState(State* state){
	current->exit();
	state->enter();
	current=state;
}