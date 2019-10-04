#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	fft.setup();
	ofBackground(1);
}

//--------------------------------------------------------------
void ofApp::update() {
	fft.update();

	cout << fft.getBins()[40] << endl;

	if (fft.getBins()[40] > 0.1) {
		for (int i = 0; i < 2; i++) {
			Particle p = Particle(ofColor::orange,
				ofVec3f(8, 8, 8), //scale
				2.6, //vel
				ofVec3f(ofGetWidth() * ofRandom(0, 1), ofGetHeight(), 0), //pos
				14); //acc
			particlesV.push_back(p);
		}
	}
	else if (t % 14 == 0) {
			Particle p = Particle(ofColor::yellow,
				ofVec3f(5, 5, 5), //scale
				1.4, //vel
				ofVec3f(ofGetWidth() * ofRandom(0, 1), ofGetHeight(), 0), //pos
				18); //acc
			particlesV.push_back(p);	
	}


	float dt = ofGetLastFrameTime();
	for (int i = 0; i < particlesV.size(); i++) {
		particlesV[i].update(dt,t);

		if (particlesV[i].lifespan > 10.0f) {
			particlesV.erase(particlesV.begin() + i);
		}
	}

	t++;
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < particlesV.size(); i++) {
		particlesV[i].draw();
	}
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	// Particle p = Particle(ofColor::red,
	//	ofVec3f(8, 8, 8), //scale
	//	2.6, //vel
	//	ofVec3f(ofGetWidth() * ofRandom(0, 1), ofGetHeight(), 0), //pos
	//	14); //acc
	//particlesV.push_back(p);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}



//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}