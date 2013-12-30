#include "CamShaderState.h"

CamShaderState::CamShaderState(BaseApp* app) : State(app){
	goToFst.loadImage("images/atras.png");
	ofSetVerticalSync(true);
	choose=-1;

}
void CamShaderState::exit(){
	
	video.close();
}
void CamShaderState::enter(){

	shader.load("shaders/negativeShader.vert", "shaders/negativeShader.frag");

	video.initGrabber(ofGetWidth(),ofGetHeight(),true);
	fbo.allocate(ofGetWidth(),ofGetHeight());
	texture.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);

}


CamShaderState::~CamShaderState(void)
{
}
void CamShaderState::draw(){
	State::draw();
	

	video.update();
    shader.begin();
	shader.setUniformTexture("cam",fbo.getTextureReference(),0);
	shader.setUniform1f("choose",choose);
	glUniform1i(0, 0);
	glActiveTexture(GL_TEXTURE0);

	ofRect(0, 0, ofGetWidth(), ofGetHeight());
		
	shader.end();
	goToFst.draw(0,0);

	
}

void CamShaderState::update(){
	if(video.isFrameNew()){
	fbo.begin();
		video.draw(0,0);
		fbo.end();
	}
}

void CamShaderState::mousePressed(int x, int y, int button){
	if(x>=0 && x<=goToFst.getWidth() && y>=0 && y<=goToFst.getHeight())
		reference->setCurrentState(reference->getStateById(0));
	else
		choose*=-1;
	
}
void CamShaderState::mouseReleased(int x, int y, int button){

}

void CamShaderState::mouseMoved(int x, int y ){

}




