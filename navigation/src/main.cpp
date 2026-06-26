#include <iostream>
#include <vector>

#include "pure_pursuit.hpp"
#include "sensor_data.hpp"
#include "direction_detector.hpp"
#include "marker_tracker.hpp"
#include "lap_counter.hpp"

int main()
{
    SensorData sensors;

    sensors.front_orange = true ;// Simulate front blue sensor detection

    DirectionDetector detector;

    Direction dir = detector.update(sensors);

    MarkerTracker tracker;

    tracker.update(sensors, dir);

    sensors.front_orange = false; // Simulate front orange sensor no longer detected
    sensors.front_blue = true; // Simulate front blue sensor detection

    tracker.update(sensors, dir);

    sensors.rear_orange = true; // Simulate rear orange sensor detection

    tracker.update(sensors, dir);

    sensors.rear_blue = true; // Simulate rear blue sensor detection

    tracker.update(sensors, dir);

    LapCounter counter;

    counter.update(true);
    counter.update(true);
    counter.update(true);
    counter.update(true);

    return 0;
}