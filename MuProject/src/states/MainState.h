#pragma once
#include "State.h"
#include "../BaseApp.h"
class MainState : public State
{
public:
	MainState(BaseApp* app);
	~MainState(void);

	ofImage goToMoveCamState,goToRotateCamState,goToParticleState,goToGeometryState,goToCamShaderState;
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void enter();
	void exit();

	void update();
	void draw();
private:
	int c;

};