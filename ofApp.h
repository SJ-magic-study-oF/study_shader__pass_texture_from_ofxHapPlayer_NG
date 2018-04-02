/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxHapPlayer.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	enum{
		W_MONITOR = 1280,
		H_MONITOR = 720,
		
		W_CONTENTS = 1920,
		H_CONTENTS = 1080,
	};
	
	ofxHapPlayer video;
	ofFbo fbo;
	ofShader shader;
	
public:
	ofApp();
	~ofApp();
	void exit();
	
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
