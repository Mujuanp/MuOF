#include "Sphere.h"
Sphere::Sphere(double R, int segmentosX, int segmentosY){

	this->R = R;
	this->segmentosX=segmentosX;
	this->segmentosY=segmentosY;
//	center = ofVec3f(ofGetWidth()/2,ofGetHeight()/2-100);
	rotateX=1;
	rotateY=1;
	rotateZ=1;
}
Sphere::Sphere(){

}
ofVec3f Sphere::phi(double x, double y){
	ofVec3f result= ofVec3f(R*cos(x*2*PI)* sin(y*2*PI),R*sin(x*2*PI)* sin(y*2*PI),R*cos(y*2*PI));
	return result;
}

ofVec3f Sphere::phiPX(double x, double y){
	ofVec3f result= ofVec3f(-R*sin(2*PI*x)*sin(2*PI*y),R*cos(2*PI*y),0);
	return result;
}
ofVec3f Sphere::phiPY(double x, double y){
	ofVec3f result= ofVec3f(-R*cos(2*PI*x)*cos(2*PI*y),-R*sin(2*PI*x)*cos(2*PI*y),-R*sin(y*2*PI));
	return result;
}
void Sphere::draw(){
	ofTranslate(ofGetWidth()/2,ofGetHeight()/2-100);
	ofRotateX(rotateX);
	ofRotateY(rotateY);
	//ofRotateZ(rotateZ);
	rotateX+=ofRandom(1,3);
	rotateY+=ofRandom(1,1.4);
	rotateZ+=ofRandom(1,1.3);
	     GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };

    glLightModelfv (GL_LIGHT_MODEL_AMBIENT, luz_ambiental); 
	 glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);  // GL_FALSE par observador en el infinito 

	 void glMaterial(GLenum cara, GLenum nombre); glColorMaterial(GL_FRONT, GL_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL); 

	glBegin(GL_QUADS);

	ofEnableNormalizedTexCoords();
	ofSetHexColor(0xffffff);

	for (int i = 0 ; i < segmentosX ; i++){
		float fi = i/(float)segmentosX;
		float fi1= (i+1)/(float)segmentosX;
		for(int j = 0; j < segmentosY; j++){

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

	glEnd();

	ofSetColor(255);


	ofDisableNormalizedTexCoords();
	ofSetColor(255,255,255);





}
