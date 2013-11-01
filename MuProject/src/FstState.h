#pragma once
#include "State.h"
#include "BaseApp.h"
class FstState : public State
{
public:
	FstState(BaseApp* app);
	~FstState(void);

	ofImage goToSnd,goToTrd,goToFrth;
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void enter();
	void exit();
	void update();
	void draw();

};