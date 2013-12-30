#pragma once
#include "Shape.h"
class Sphere :public Shape{
public:
	Sphere(void);
	Sphere(double R, int segmentosX, int segmentosY);
	~Sphere(void){}
	ofVec3f phi(double x, double y);
	ofVec3f phiPX(double x, double y);
	ofVec3f phiPY(double x, double y);
	void draw();
	double getR() const { return R; }
	void setR(double val) { R = val; }

private:
	double R;
	int segmentosX, segmentosY;
	float rotateY,rotateX,rotateZ;

	ofVec3f center;

};