#pragma once
#include "../BaseApp.h"

class Shape {
public:
	Shape(void){}
	virtual ~Shape(void){}
	virtual ofVec3f phi(double x, double y) = 0;
	virtual ofVec3f phiPX(double x, double y) = 0;
	virtual ofVec3f phiPY(double x, double y)=0;
	virtual void draw()=0;

};