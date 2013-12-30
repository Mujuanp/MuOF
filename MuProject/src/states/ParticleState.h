#pragma once
#include "State.h"
#include "../BaseApp.h"
#include "../physics/Particle.h"
class ParticleState :public State{
public:
	ParticleState(BaseApp* ap);
	~ParticleState(void);
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
	vector<Particle*> particles;
	int  max;
};