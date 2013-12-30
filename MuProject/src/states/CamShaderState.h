#pragma once
#include "State.h"
#include "../BaseApp.h"
class CamShaderState : public State
{
public:
	CamShaderState(BaseApp* app);
	~CamShaderState(void);


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
	ofShader shader;
	ofVideoGrabber video;
	ofFbo fbo;
	ofTexture texture;
	float choose;
	
};