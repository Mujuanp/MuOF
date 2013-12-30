#include "BaseApp.h"
#include "states/State.h"

//--------------------------------------------------------------
void BaseApp::keyPressed(int key){

}

//--------------------------------------------------------------
void BaseApp::keyReleased(int key){

}

//--------------------------------------------------------------
void BaseApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void BaseApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void BaseApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void BaseApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void BaseApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void BaseApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void BaseApp::dragEvent(ofDragInfo dragInfo){ 

}

vector<State*>* BaseApp::getStates(){
	return &states;
}
State* BaseApp::getCurrentState(){
	return current;
}
State* BaseApp::getStateById(int id){
	return states[id];
}
void BaseApp::setCurrentState(State* state){
	current->exit();
	state->enter();
	current=state;
}

