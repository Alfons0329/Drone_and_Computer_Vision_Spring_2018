#include <opencv2/aruco.hpp>
#include "calibration.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat cameraMatrix;
Mat distCoeffs;
double markerLength = 7.05;

int main(void){

	Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_6X6_250);

	vector<int> ids;
	vector<vector<Point2f> > corners;

	my_camera_calibration(cameraMatrix, distCoeffs, "config.xml");

	VideoCapture cap;
	cap.open(0);
	int framePerSecond = 20;
	Mat frame;
	getchar(); //act as a system pause
	while(cap.grab())
	{
		Mat image, imageCopy;
	    cap.retrieve(image);
	    image.copyTo(imageCopy);
	    vector<int> ids;
	    vector<vector<Point2f> > corners;
	    aruco::detectMarkers(image, dictionary, corners, ids);
	    // if at least one marker detected
	    if (ids.size() > 0) {
	        aruco::drawDetectedMarkers(imageCopy, corners, ids);
	        vector<Vec3d> rvecs, tvecs;
			aruco::estimatePoseSingleMarkers(corners, markerLength, cameraMatrix, distCoeffs, rvecs, tvecs);
	        // draw axis for each marker
	        aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs, tvecs, 10);
	        cout << tvecs[0] << endl;
	    }
	    imshow("out", imageCopy);
		waitKey(100);
	}

	return 0;
}
