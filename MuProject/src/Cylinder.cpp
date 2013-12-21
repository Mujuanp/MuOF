#include "Cylinder.h"
Cylinder::Cylinder(double r,double h, int segmentosX, int segmentosY){
	H = h;
	R = r;
	this->segmentosX=segmentosX;
	this->segmentosY=segmentosY;
	center = ofVec3f(ofGetWidth()/2,ofGetHeight()/2-100);
	rotateX=1;
	rotateY=1;
	rotateZ=1;
}
Cylinder::Cylinder(){

}
ofVec3f Cylinder::phi(double x, double y){
	ofVec3f result= ofVec3f(R*cos(x*2*PI),y *H,R*sin(x*2*PI));
	return result;
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
	ofTranslate(ofGetWidth()/2,ofGetHeight()/2-100);
	ofRotateX(rotateX);
	ofRotateY(rotateY);
	//ofRotateZ(rotateZ);
	rotateX+=ofRandom(1,3);
	rotateY+=ofRandom(1,1.4);
	rotateZ+=ofRandom(1,1.3);
	glBegin(GL_QUADS);

	ofEnableNormalizedTexCoords();
	ofSetHexColor(0xffffff);

	for (int i = 0 ; i < segmentosX ; i++){
		float fi = i/(float)segmentosX;
		float fi1= (i+1)/(float)segmentosX;
		for(int j = 0; j < segmentosY-1; j++){

			float fj = j/(float)segmentosY;
			float fj1 = (j+1)/(float)segmentosY;

			ofVec3f p1 = phi(fi,fj);
			ofVec3f p2 = phi(fi,fj1);
			ofVec3f p3 = phi(fi1,fj);
			ofVec3f p4 = phi(fi1,fj1);
			ofVec3f norm = phiPX(fi,fj).cross(phiPY(fi,fj));
			//	cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<"\n";
			//				ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
			ofSetColor(255,0,0);
			glNormal3f(norm.x,norm.y,norm.z);
			ofSetColor(0);
			glVertex3f(p1.x,p1.y,p1.z);
			glVertex3f(p3.x,p3.y,p3.z);
			glVertex3f(p4.x,p4.y,p4.z);
			glVertex3f(p2.x,p2.y,p2.z);

		}
	}

	glEnd();

	glBegin(GL_LINES);// GL_POINTf
	ofSetHexColor(0xffffff);

	for (int i = 0 ; i < segmentosX; i++){
		float fi = i/(float)segmentosX;
		for(int j = 0; j < segmentosY; j++){
			float fj = j/(float)segmentosY;
			ofVec3f pX = phiPX(fi,fj).cross(phiPY(fi,fj));
			ofVec3f psum = pX+15;

		//	cout<<pX<<" cross "<<psum<<"sum "<<"\n";
			ofSetColor(200,200,200);
			glVertex3f(pX.x,pX.y,pX.z);
			glVertex3f(psum.x,psum.y,psum.z);
		}
	}

	glEnd();
	ofSetColor(255);


	ofDisableNormalizedTexCoords();
	ofSetColor(255,255,255);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glPointSize(5);

	glBegin(GL_POINTS);// GL_POINTf
	ofSetHexColor(0xffffff);


	for (int i = 0 ; i < segmentosX; i++){
		float fi = i/(float)segmentosX;
		for(int j = 0; j < segmentosY; j++){
			float fj = j/(float)segmentosY;
			ofVec3f pX = phi(fi,fj);
			ofVec3f norm = phiPX(fi,fj).cross(phiPY(i,fj));
			glVertex3f(pX.x,pX.y,pX.z);
			glNormal3f(norm.x,norm.y,norm.z);
		}
	}

	glEnd();



}

