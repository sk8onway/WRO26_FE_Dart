cmake_minimum_required(VERSION 3.10)

project(WRO_Perception)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(wro_perception
    src/main.cpp
    src/camera/camera.cpp
    src/preprocessing/image_preprocessor.cpp
    src/segmentation/color_segmenter.cpp
)

target_link_libraries(wro_perception
    ${OpenCV_LIBS}
)