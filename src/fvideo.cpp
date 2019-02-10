#include "fvideo.h"

// using namespace Fvideo;

// #include<iostream>

// #include <opencv2/core/core.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/highgui/highgui.hpp>

// using namespace std;
// using namespace cv;

// constructor
Fvideo::Fvideo(char *s) {
  cout << s << endl;
  cap = VideoCapture(s);
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
  }
}


// this function display the video
int Fvideo::showVideo() {
  while(true) {
    Mat frame;
    cap >> frame;
    // If the frame is empty, break immediately
    if (frame.empty())
      break; 
    // Display the resulting frame
    imshow( "Frame", frame );
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27) {
      break;
    }
  }
  cap.release();
  return 0;
}

int Fvideo::showFrame(int f) {
  Mat frameDes;
  if (getFrame(frameDes, f) == 0) {
    imshow("Frame selected", frameDes);
    waitKey(0);
    return 0;
  }
  return -1;
}


int Fvideo::getFrame(Mat &des, int indexframe) {
  int nframes = getLength();
  if (indexframe < nframes && indexframe > 0) {
    // read frame
    cap.set ( CV_CAP_PROP_POS_FRAMES , indexframe );
    bool success = cap.read(des); 
    if (!success) {
      cout << "Cannot read  frame " << endl;
      return -1;
    }
    // imshow("Frame ", currentFrame);
    // waitKey(0);
    return 0;

  } else {
    cout << "Frame is out from bound" << endl;
    return -1;
  }
}

int Fvideo::getLength() {
  //int frames = cap.get(0);
  return cap.get(CAP_PROP_FRAME_COUNT);
}

int Fvideo::isOpened() {
  // return cap.isOpened();
  return cap.isOpened();
}

