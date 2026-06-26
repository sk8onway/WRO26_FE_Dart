#include "direction_detector.hpp"

DirectionDetector::DirectionDetector()
    : direction_(Direction::UNKNOWN)
{}

Direction DirectionDetector::update(
    const SensorData& sensors)
{
    if(direction_ == Direction::UNKNOWN)
    {
        if(sensors.front_blue)
        {
            direction_ = Direction::CCW;
        }
        else if(sensors.front_orange)
        {
            direction_ = Direction::CW;
        }
    }
    return direction_;
}

Direction DirectionDetector::getDirection() const
{
    return direction_;
}