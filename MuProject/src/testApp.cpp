#include "testApp.h"
#include "State.h"

//--------------------------------------------------------------
void testApp::setup(){
	current= new FstState((BaseApp*)this);
	states.push_back(current);
	states.push_back(new SndState((BaseApp*)this));
	states.push_back(new TrdState((BaseApp*)this));
	states.push_back(new FthState((BaseApp*)this));
	states.push_back(new FithState((BaseApp*)this));
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