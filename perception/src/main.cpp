#include <iostream>
#include <opencv2/opencv.hpp>

#include "camera/camera.hpp"
#include "preprocessing/image_preprocessor.hpp"
#include "segmentation/color_segmenter.hpp"

int main()
{
    Camera camera;
    ImagePreprocessor preprocessor;
    ColorSegmenter segmenter;

    if (!camera.initialize())
    {
        std::cerr << "Failed to initialize camera.\n";
        return -1;
    }

    cv::Mat frame;
    cv::Mat processedFrame;

    while (true)
    {
        // Capture frame
        if (!camera.readFrame(frame))
        {
            std::cerr << "Failed to read frame.\n";
            break;
        }

        // Preprocess frame
        processedFrame = preprocessor.preprocess(frame);

        // Display images
        cv::imshow("Original Frame", frame);
        cv::imshow("Processed Frame", processedFrame);
        cv::Mat redMask = segmenter.getRedMask(processedFrame);
        cv::Mat greenMask = segmenter.getGreenMask(processedFrame);
        cv::imshow("Red Mask", redMask);
        cv::imshow("Green Mask", greenMask);

        // Exit on ESC
        if (cv::waitKey(1) == 27)
        {
            break;
        }
    }

    return 0;
}