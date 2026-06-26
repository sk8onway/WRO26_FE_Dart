#ifndef COLOR_SEGMENTER_HPP
#define COLOR_SEGMENTER_HPP

#include <opencv2/opencv.hpp>

class ColorSegmenter
{
public:
    ColorSegmenter();

    cv::Mat getRedMask(const cv::Mat& frame);

    cv::Mat getGreenMask(const cv::Mat& frame);
};

#endif