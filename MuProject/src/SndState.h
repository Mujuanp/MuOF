#pragma once
#include "State.h"
#include "BaseApp.h"
class SndState : public State
{
public:
	SndState(BaseApp* app);
	~SndState(void);
//	void setDireccion(ofVec2f* pos,ofVec2f* vel);
	bool pasoBordeSup(ofVec2f pos);
	bool pasoBordeInf(ofVec2f pos);
	bool pasoBordeDer(ofVec2f pos);
	bool pasoBordeIzq(ofVec2f pos);

	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void enter();
	void exit();
	void update();
	void draw();
private:
	ofImage goToFst;
	ofVideoGrabber 		vidGrabber;
	int 				camWidth;
	int 				camHeight;
	ofVec2f              velCam1;
	ofVec2f              velCam2;
	ofVec2f              velCam3;
	ofVec2f              velCam4;

	ofVec2f              posCam1;
	ofVec2f              posCam2;
	ofVec2f              posCam3;
	ofVec2f              posCam4;
	
};