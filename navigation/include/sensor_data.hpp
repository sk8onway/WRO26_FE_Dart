#ifndef SENSOR_DATA_HPP
#define SENSOR_DATA_HPP

struct SensorData
{
    double front_tof = 0.0;
    double left_tof = 0.0;
    double right_tof = 0.0;

    bool front_blue = false;
    bool front_orange = false;

    bool rear_blue = false;
    bool rear_orange = false;

    bool red_pillar = false;
    bool green_pillar = false;
};

#endif