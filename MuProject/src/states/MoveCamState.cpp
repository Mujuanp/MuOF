#include "MoveCamState.h"
MoveCamState::MoveCamState(BaseApp* app) : State(app){
	goToFst.loadImage("images/atras.png");
	camWidth 		= 320;	// try to grab at this size. 
	camHeight 		= 240;
	posCam1 = ofVec2f(30,30);
	posCam2 = ofVec2f(380,30);
	posCam3 = ofVec2f(30,270);
	posCam4 = ofVec2f(380,270);
	velCam1 = ofVec2f(ofRandom(-1,1),ofRandom(-1,1));
	velCam2 = ofVec2f(ofRandom(-1,1),ofRandom(-1,1));
	velCam3 = ofVec2f(ofRandom(-1,1),ofRandom(-1,1));
	velCam4 = ofVec2f(ofRandom(-1,1),ofRandom(-1,1));

	
	
	ofSetVerticalSync(true);

}
void MoveCamState::exit(){
	
	vidGrabber.close();
}
void MoveCamState::enter(){

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);

	vidGrabber.initGrabber(camWidth,camHeight);
}


MoveCamState::~MoveCamState(void)
{
}
void MoveCamState::draw(){
	State::draw();
	goToFst.draw(0,0);

	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	
	ofSetHexColor(0xffffff);
	//vidGrabber.draw(camX,15);
	ofEnableNormalizedTexCoords();
	vidGrabber.getTextureReference().bind();
	glBegin(GL_QUADS);
		glTexCoord2i(0, 0);
		glVertex2f(posCam1.x,posCam1.y);

		glTexCoord2i(1, 0);
		glVertex2f(posCam2.x,posCam2.y);

		glTexCoord2i(1, 1);
		glVertex2f(posCam3.x,posCam3.y);

		glTexCoord2i(0, 1);
		glVertex2f(posCam4.x,posCam4.y);

	glEnd();
	vidGrabber.getTextureReference().unbind();
	ofDisableNormalizedTexCoords();
//	vidGrabber.getTextureReference().bind();


//	videoTexture.draw(20+camWidth,20,camWidth,camHeight);
	

	

	
}

void MoveCamState::update(){

	vidGrabber.update();
	
	if(pasoBordeSup(posCam1))
		velCam1= ofVec2f(ofRandom(-1,1),1);
	if(pasoBordeInf(posCam1))
		velCam1 = ofVec2f(ofRandom(-1,1),-1);
	if(pasoBordeDer(posCam1))
		velCam1 =ofVec2f(-1,ofRandom(-1,1));
	if(pasoBordeIzq(posCam1))
		velCam1 =  ofVec2f(1,ofRandom(-1,1));

	if(pasoBordeSup(posCam2))
		velCam2= ofVec2f(ofRandom(-1,1),1);
	if(pasoBordeInf(posCam2))
		velCam2 = ofVec2f(ofRandom(-1,1),-1);
	if(pasoBordeDer(posCam2))
		velCam2 =ofVec2f(-1,ofRandom(-1,1));
	if(pasoBordeIzq(posCam2))
		velCam2 =  ofVec2f(1,ofRandom(-1,1));

	if(pasoBordeSup(posCam3))
		velCam3= ofVec2f(ofRandom(-1,1),1);
	if(pasoBordeInf(posCam3))
		velCam3 = ofVec2f(ofRandom(-1,1),-1);
	if(pasoBordeDer(posCam3))
		velCam3 =ofVec2f(-1,ofRandom(-1,1));
	if(pasoBordeIzq(posCam3))
		velCam3 =  ofVec2f(1,ofRandom(-1,1));

	if(pasoBordeSup(posCam4))
		velCam4= ofVec2f(ofRandom(-1,1),1);
	if(pasoBordeInf(posCam4))
		velCam4 = ofVec2f(ofRandom(-1,1),-1);
	if(pasoBordeDer(posCam4))
		velCam4 =ofVec2f(-1,ofRandom(-1,1));
	if(pasoBordeIzq(posCam4))
		velCam4 =  ofVec2f(1,ofRandom(-1,1));

		posCam1+=velCam1;
		posCam2+=velCam2;
		posCam3+=velCam3;
		posCam4+=velCam4;
}

void MoveCamState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight())
		reference->setCurrentState(reference->getStateById(0));
	
}
void MoveCamState::mouseReleased(int x, int y, int button){

}

void MoveCamState::mouseMoved(int x, int y ){

}


bool MoveCamState::pasoBordeSup(ofVec2f pos){
	bool result;
	if(pos.y<=0)
		result=true;
	else 
		result=false;
	return result;
}
bool MoveCamState::pasoBordeInf(ofVec2f pos){
	bool result;
	if(pos.y>=ofGetWindowSize().y)
		result=true;
	else 
		result=false;
	return result;
}

bool MoveCamState::pasoBordeIzq(ofVec2f pos){
	bool result;
	if(pos.x<=0)
		result=true;
	else 
		result=false;
	return result;
}
bool MoveCamState::pasoBordeDer(ofVec2f pos){
	
	bool result;
	if(pos.x>=ofGetWindowSize().x)
		result=true;
	else 
		result=false;
	return result;
}
//void MoveCamState::setDireccion(ofVec2f* pos,ofVec2f* vel){
//	if(pasoBordeSup(pos))
//		vel= new ofVec2f(ofRandom(-1,1),1);
//	if(pasoBordeInf(pos))
//		vel = new ofVec2f(ofRandom(-1,1),-1);
//	if(pasoBordeDer(pos))
//		vel =new ofVec2f(-1,ofRandom(-1,1));
//	if(pasoBordeIzq(pos))
//		vel = new ofVec2f(1,ofRandom(-1,1));
//
//}