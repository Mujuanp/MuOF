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
	ofLight luz = ofLight();
	ofMaterial material = ofMaterial();
	luz.setPosition(100,0,300);
	luz.enable();
	material.setAmbientColor(ofFloatColor(0.5));
	material.begin();
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
			norm = norm.normalize();
			//	cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<"\n";
			//				ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
			ofSetColor(255,0,0);
			
			ofSetColor(0);
			glNormal3f(p1.x+norm.x*30,p1.y+norm.y*30,p1.z+norm.z*30);
			glVertex3f(p1.x,p1.y,p1.z);
			glNormal3f(p3.x+norm.x*30,p3.y+norm.y*30,p3.z+norm.z*30);
			glVertex3f(p3.x,p3.y,p3.z);
			glNormal3f(p4.x+norm.x*30,p4.y+norm.y*30,p4.z+norm.z*30);
			glVertex3f(p4.x,p4.y,p4.z);
			glNormal3f(p2.x+norm.x*30,p2.y+norm.y*30,p2.z+norm.z*30);
			glVertex3f(p2.x,p2.y,p2.z);

		}
	}
	material.end();
	luz.disable();
	glEnd();

	ofSetColor(255);


	ofDisableNormalizedTexCoords();
	ofSetColor(255,255,255);





}
