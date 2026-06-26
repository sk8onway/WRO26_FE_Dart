#ifndef IMAGE_PREPROCESSOR_HPP
#define IMAGE_PREPROCESSOR_HPP

#include <opencv2/opencv.hpp>

class ImagePreprocessor
{
public:
    ImagePreprocessor();

    cv::Mat preprocess(const cv::Mat& frame);

private:
    cv::Size target_size_;
};

#endif