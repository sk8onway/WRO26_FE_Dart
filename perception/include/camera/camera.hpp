#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <opencv2/opencv.hpp>

class Camera
{
    public:
        Camera();
        ~Camera();

        bool initialize(int camera_id=0);
        bool readFrame(cv::Mat& frame);

        bool isOpened() const;
        void release();
    
    private:
        cv::VideoCapture cap_;
};

#endif