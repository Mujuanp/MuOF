#pragma once
#include "Shape.h"
class Cylinder :public Shape{
public:
	Cylinder(void);
	Cylinder(double r, double h, int segmentosX, int segmentosY);
	~Cylinder(void){}
	ofVec3f phi(double x, double y);
	ofVec3f phiPX(double x, double y);
	ofVec3f phiPY(double x, double y);
	void draw();

	double getH() const { return H; }
	void setH(double val) { H = val; }
	double getR() const { return R; }
	void setR(double val) { R = val; }

private:
	double R,H;
	int segmentosX, segmentosY;
	float rotateY,rotateX,rotateZ;

	ofVec3f center;

};