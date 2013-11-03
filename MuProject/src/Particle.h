#pragma once
#include "BaseApp.h"
class Particle{
public:
	Particle();
	~Particle(void);
	ofVec2f vel,acc,pos;

	void update();
	void draw();
	void setVel(int vel);
private:
	int vul;
};