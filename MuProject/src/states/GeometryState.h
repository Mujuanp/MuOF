#pragma once
#include "State.h"
#include "../BaseApp.h"
#include "../geometry/Cylinder.h"
#include "../geometry/Toro.h"
#include "../geometry/Sphere.h"
class GeometryState :public State{
public:
	GeometryState(BaseApp* ap);
	~GeometryState(void);
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
	Cylinder cylinder;
	Toro toro;
	Sphere sphere;


};