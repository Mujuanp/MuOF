#pragma once

#include "ofMain.h"
#include "ofGraphics.h"

class State;
class BaseApp : public ofBaseApp{

public:
	void setup() = 0;
	void update() = 0;
	void draw() = 0;

	virtual void keyPressed(int key);
	virtual void keyReleased(int key);
	virtual void mouseMoved(int x, int y );
	virtual void mouseDragged(int x, int y, int button);
	virtual void mousePressed(int x, int y, int button);
	virtual void mouseReleased(int x, int y, int button);
	virtual void windowResized(int w, int h);
	virtual void dragEvent(ofDragInfo dragInfo);
	virtual void gotMessage(ofMessage msg);

	vector<State*>* getStates();
	State* getCurrentState();
	State* getStateById(int id);
	void setCurrentState(State* state);
private:
	vector<State*> states;
	State* current;
};