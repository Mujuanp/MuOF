#pragma once
#include "State.h"
#include "BaseApp.h"

class TrdState :public State{
public:
	TrdState(BaseApp* ap);
	~TrdState(void);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void enter();
	void exit();
	void update();
	void draw();
private:
		ofImage goToFst;
	ofVideoGrabber 		vidGrabber;
	int 				camWidth;
	int 				camHeight;
	
	int rotacion;
};