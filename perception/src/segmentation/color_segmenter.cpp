#include <opencv2/opencv.hpp>
#include "segmentation/color_segmenter.hpp"

ColorSegmenter::ColorSegmenter()
{
}

cv::Mat ColorSegmenter::getRedMask(const cv::Mat& frame)
{
    cv::Mat hsv;
    cv::Mat lowerRedMask;
    cv::Mat upperRedMask;
    cv::Mat redMask;

    // Convert BGR to HSV
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    // Lower red range
    cv::inRange(
        hsv,
        cv::Scalar(0, 120, 70),
        cv::Scalar(10, 255, 255),
        lowerRedMask
    );

    // Upper red range
    cv::inRange(
        hsv,
        cv::Scalar(170, 120, 70),
        cv::Scalar(180, 255, 255),
        upperRedMask
    );

    // Combine both masks
    redMask = lowerRedMask | upperRedMask;

    return redMask;
}

cv::Mat ColorSegmenter::getGreenMask(const cv::Mat& frame)
{
    cv::Mat hsv;
    cv::Mat greenMask;

    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    cv::inRange(
        hsv,
        cv::Scalar(35, 50, 50),
        cv::Scalar(85, 255, 255),
        greenMask
    );

    return greenMask;
}