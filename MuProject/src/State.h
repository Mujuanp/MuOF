#pragma once
#include "ofMain.h"
#include "BaseApp.h"
class State
{
public:	
	State(BaseApp* app);
	~State(void);

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	virtual void mousePressed(int x, int y, int button);
	void enter();
	void exit();
	virtual void update();
	virtual void draw();
protected:
	BaseApp* reference;
	ofImage fondo;
};