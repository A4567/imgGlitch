#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	int shrink = 4;

	ofSetBackgroundAuto(false);
	ofBackground(0);

	ofBackground(0);
	img.load("archie.jpg");
	img2.load("luke.jpg");
	img.resize(img.getWidth() / shrink, img.getHeight() / shrink);
	img2.resize(img2.getWidth() / shrink, img2.getHeight() / shrink);

	cout << img.getHeight() << endl;
	cout << img2.getHeight() << endl;

	x = 0;
	y = 0;
	imgPix = img.getPixels();
	paint = imgPix.getColor(x, y);

	imgPix2 = img2.getPixels();
	paint2 = imgPix2.getColor(x, y);

	segments = 100;
	segmentStart = 0;
	segmentEnd = imgPix.getWidth() / segments;
	b_drawn = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	img.update();

}

//--------------------------------------------------------------
void ofApp::draw(){ 

	if (segmentStart < imgPix.getWidth()) {
		for (int w = segmentStart; w < segmentEnd; w++) {
			for (int h = 0; h < imgPix.getHeight(); h++) {

				paint = imgPix.getColor(w, h);
				paint2 = imgPix2.getColor(w, h);

				if (b_drawn) {
					ofSetColor(paint2);
				}else{
					ofSetColor(paint);
				}
				ofDrawCircle(w, h, 1);
			}
		}

		segmentStart = segmentEnd;
		segmentEnd += imgPix.getWidth() / segments;
		b_drawn = !b_drawn;
	}
	else {
		segmentStart = 0;
		segmentEnd = imgPix.getWidth() / segments;
	}
}

//--------------------------------------------------------------
void ofApp::drawArt() {
	
}