#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <unistd.h> 
using namespace cv;
using namespace std;

Mat uvc_frame; 
Mat cam_frame; 
//mutex mtx; 

void camCapture(VideoCapture cap, const string name) 
{
    Mat frame; 
 
    int frameCnt = 0;
    int frameEmpty = 0;
    time_t start = std::time(nullptr);
    time_t now  = std::time(nullptr);
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);

        frameCnt += 1;
        // check if we succeeded
        if (frame.empty()) {
	    if (frameEmpty%20 == 0) {
              cerr << "ERROR! blank frame grabbed from " << name << ", count=" << frameEmpty << endl;
            }
            frameEmpty += 1;
        }
        
        if (frameCnt % 1000 == 0) {
           now  = std::time(nullptr);
           cout << "camera=" << name << ", frameCnt = " <<  frameCnt << ", elipsed time=" << (now-start) << " sec" <<  endl;
           cout << "frameEmpty = " << frameEmpty << ", w=" << frame.cols << ", h=" << frame.rows << endl;
        }
 	//usleep(10000); 	
    }
} 

// open multiple cameras and assign each video capturing to a dedicated thread 
int main(int, char**)
{
    VideoCapture cap[4]; 

    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API

    for (int i = 0; i  < 4; i++) {
	/* if (i == 0) {  	// UVCHDCAP
	  cap[i].set(CAP_PROP_FRAME_WIDTH, 1280); 
	  cap[i].set(CAP_PROP_FRAME_HEIGHT, 720); 
	  cap[i].set(CAP_PROP_FPS, 15); 
        } */ 

	if (i != 0) { 
		cap[i].open(i, apiID);
    		// check if we succeeded
    		if (!cap[i].isOpened()) {
           	cerr << "ERROR! Unable to open camera " << i << endl;
           	return -1;
        	}
	}

    }

    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl; 

    thread uvc_cap(camCapture, cap[2], "Av.io HD"); 
    thread cam_cap(camCapture, cap[1], "front");

    uvc_cap.join(); 
    //cam_cap.join();  
  
    return 0;
}
