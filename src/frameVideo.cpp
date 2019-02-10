// without oop
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// int main(int argc, char **argv) {
//   VideoCapture cap("media/v_PlayingPiano_g01_c01.avi");    
//   if(!cap.isOpened()){
//     cout << "Error opening video stream or file" << endl;
//     return -1;
//   }
//   while(1){
//     Mat frame;
//     // Capture frame-by-frame
//     cap >> frame;
//     // If the frame is empty, break immediately
//     if (frame.empty())
//       break;
//     // Display the resulting frame
//     imshow( "Frame", frame );
//     // Press  ESC on keyboard to exit
//     char c=(char)waitKey(25);
//     if(c==27)
//       break;
//   }
//   // When everything done, release the video capture object
//   cap.release();
//   // Closes all the frames
//   destroyAllWindows();
//   return 0;
// }

#include "fvideo.h"

// using namespace Fvideo;

int main(int argc, char **argv) {
  
  Fvideo fvideo("media/KIWI.mp4");
  // fvideo.showVideo();
  cout << "video opened: " << fvideo.isOpened() << endl;
  cout << "Number of frames: " << fvideo.getLength() << endl;

  fvideo.showFrame(3000);

  fvideo.showVideo();

  return 0;
}
