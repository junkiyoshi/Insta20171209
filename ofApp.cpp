#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(128);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() { 
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	float x, y;
	float radius = 250;
	int tmp_deg;
	float tmp_x, tmp_y;
	ofColor color;

	this->cam.begin();

	for(int deg = 0; deg <= 360; deg += 10) {
		color.setHsb(deg / 360.f * 255.f, 255, 255);
		ofSetColor(color);

		x = radius * cos(deg * DEG_TO_RAD);
		y = radius * sin(deg * DEG_TO_RAD);

		ofDrawCircle(x, y, 5);

		tmp_deg = deg + ofGetFrameNum() % 360;

		tmp_x = radius * 0.8 * cos(tmp_deg * DEG_TO_RAD);
		tmp_y = radius * 0.8 * sin(tmp_deg * DEG_TO_RAD);

		ofDrawCircle(tmp_x, tmp_y, 5);

		ofDrawLine(x, y, tmp_x, tmp_y);

	}

	this->cam.end();
	
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}