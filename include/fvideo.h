
#ifndef FVIDEO_H
#define FVIDEO_H

// without oop
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


class Fvideo{

  public: 
    // Fvideo();
    Fvideo(char *s);
    
    // int openVideo(char *s);
    int getFrame(Mat &des, int indexframe);
    int getLength();
    int isOpened();

    int showVideo();
    // int getFrame(int f);
    // int showVideoByFrame();
    int showFrame(int f);


  private:
    VideoCapture cap;
    int length;
};


#endif // #ifndef FVIDEO_H;
