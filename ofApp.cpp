/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/
/******************************
******************************/
ofApp::ofApp()
{
}

/******************************
******************************/
ofApp::~ofApp()
{
	video.stop();
	video.close();
}

/******************************
******************************/
void ofApp::exit(){
	printf("> Good bye\n");
}

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("shader study");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(W_MONITOR, H_MONITOR);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	ofEnableSmoothing();
	
	/********************
	********************/
	fbo.allocate(W_CONTENTS, H_CONTENTS, GL_RGBA);
	shader.load( "copy.vert", "copy.frag");
	
	/********************
	********************/
	video.load("video.mov");
	
	video.setLoopState(OF_LOOP_NORMAL); // OF_LOOP_NONE
	video.setSpeed(1);
	video.setVolume(1.0);
	// video.setVolume(0.0);
	video.play();
 	
	/*
	wait to avoid block noise.
	Sleep(ms) is not defined.
	sleep(sec) is too long.
	so here, I use usleep().
	*/
	usleep(120e3); // 十分長く、且つ、気付かない程度の長さ.
	// sleep(1); // sec : too long.
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
}

//--------------------------------------------------------------
/******************************
description
	shaderにtextureを渡す際の注意。
	ofxHapPlayerでそのままdrawしてもpassできないが、fbo経由ならOKだった。
	
	ofFbo::getTexture()はRefedenceだが、ofxHapPlayer::getTexture()はpointer.
	Referenceを取得するためのmethodが定義されていると、passできる、と考えて良さそう。
	ofImageもReferenceだが、こちらもOK.
******************************/
void ofApp::draw(){
	/********************
	こちらはNG.
	textureがshaderに伝わらなかった.
	********************/
	/*
	ofClear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	
	shader.begin();
		shader.setUniform2f( "u_resolution", ofGetWidth(), ofGetHeight() );
		video.draw(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();
	*/
	
	/********************
	fbo経由で渡す.
	********************/
	// 
	fbo.begin();
	ofClear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	video.draw(0, 0, fbo.getWidth(), fbo.getHeight());
	fbo.end();
	
	// 
	ofClear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	
	
	shader.begin();
		shader.setUniform2f( "u_resolution", ofGetWidth(), ofGetHeight() );
		// video.draw(0, 0, ofGetWidth(), ofGetHeight());
		fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'k':
		video.setPosition(0.2);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
