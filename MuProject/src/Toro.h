#pragma once
#include "Shape.h"
class Toro :public Shape{
public:
	Toro(void);
	Toro(double r, double R, int segmentosX, int segmentosY);
	~Toro(void){}
	ofVec3f phi(double x, double y);
	ofVec3f phiPX(double x, double y);
	ofVec3f phiPY(double x, double y);
	void draw();

	double getr() const { return r; }
	void setH(double val) { r = val; }
	double getR() const { return R; }
	void setR(double val) { R = val; }

private:
	double R,r;
	int segmentosX, segmentosY;
	float rotateY,rotateX,rotateZ;

	ofVec3f center;

};