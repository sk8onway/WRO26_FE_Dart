#ifndef DIRECTION_DETECTOR_HPP
#define DIRECTION_DETECTOR_HPP

#include "sensor_data.hpp"

enum class Direction
{
    UNKNOWN,
    CW,
    CCW
};

class DirectionDetector
{
    public:
        DirectionDetector();

        Direction update(const SensorData& sensors);

        Direction getDirection() const;
    
    private:
        Direction direction_;
};

#endif