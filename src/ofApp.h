#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawArt();



		ofImage img;
		ofImage img2;

		int x, y, segments, segmentStart, segmentEnd;

		ofColor paint, culah, cewler, paint2;
		ofPixels imgPix, imgPix2;

		bool b_drawn;
};
