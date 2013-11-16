#include "Cylinder.h"
Cylinder::Cylinder(vector<ofVec2f> untos){
	puntos=untos;
	H = 300;
	R = 100;
	center = ofVec3f(ofGetWidth()/2,100);
}
Cylinder::Cylinder(){

}
ofVec3f Cylinder::phi(double x, double y){
	ofVec3f result= ofVec3f(R*cos(x*2*PI),y *H,R*sin(x*2*PI));
	return result+center;
}

ofVec3f Cylinder::phiPX(double x, double y){
	ofVec3f result= ofVec3f(-2*R*PI*sin(2*PI*x),0,2*PI*R*cos(2*PI*x));
	return result;
}
ofVec3f Cylinder::phiPY(double x, double y){
	ofVec3f result= ofVec3f(0,H,0);
	return result;
}
void Cylinder::draw(){
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glPointSize(5);

	glBegin(GL_POINTS);// GL_POINT
	ofSetHexColor(0xffffff);
	for (ofVec2f p : puntos){
		ofVec3f pX = phi(p[0],p[1]);
		glVertex3f(pX.x,pX.y,pX.z);
	}
	glEnd();
}
