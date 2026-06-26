#include "camera/camera.hpp"

Camera::Camera()
{
}

Camera::~Camera()
{
    release();
}

bool Camera::initialize(int cameraID)
{
    return cap_.open(cameraID);
}

bool Camera::readFrame(cv::Mat& frame)
{
    return cap_.read(frame);
}

bool Camera::isOpened() const
{
    return cap_.isOpened();
}

void Camera::release()
{
    if (cap_.isOpened())
    {
        cap_.release();
    }
}