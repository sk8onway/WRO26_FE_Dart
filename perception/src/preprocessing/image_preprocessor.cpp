#include <opencv2/opencv.hpp>
#include <preprocessing/image_preprocessor.hpp>

ImagePreprocessor::ImagePreprocessor()
{
    target_size_ = cv::Size(640, 480); // Set the target size for preprocessing
}

cv::Mat ImagePreprocessor::preprocess(const cv::Mat& frame)
{
    cv::Mat resized;
    cv::Mat processed;

    cv::resize(frame, resized, target_size_);

    cv::GaussianBlur(resized,processed, cv::Size(5, 5), 0); // Apply Gaussian blur
    return processed;
}