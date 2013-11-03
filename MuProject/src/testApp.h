#pragma once

#include "ofMain.h"
#include "ofGraphics.h"
#include "FstState.h"
#include "SndState.h"
#include "TrdState.h"
#include "FthState.h"

class State;
class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

 void keyPressed(int key);
 void keyReleased(int key);
 void mouseMoved(int x, int y );
 void mouseDragged(int x, int y, int button);
 void mousePressed(int x, int y, int button);
 void mouseReleased(int x, int y, int button);
 void windowResized(int w, int h);
 void dragEvent(ofDragInfo dragInfo);
 void gotMessage(ofMessage msg);

 vector<State*>* getStates();
 State* getCurrentState();
 State* getStateById(int id);
 void setCurrentState(State* state);
	
private:
	vector<State*> states;
	State* current;



};