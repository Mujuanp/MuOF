#pragma once
#include "Shape.h"
class Cylinder :public Shape{
public:
	Cylinder(void);
	Cylinder(vector<ofVec2f> puntos);
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
	vector<ofVec2f> puntos;
	ofVec3f center;

};