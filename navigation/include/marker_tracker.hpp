#ifndef MARKER_TRACKER_HPP
#define MARKER_TRACKER_HPP

#include "sensor_data.hpp"
#include "direction_detector.hpp"

class MarkerTracker
{
    public:

        MarkerTracker();

        bool update(
            const SensorData& sensors,
            Direction direction);
    
    private:

            void reset();

            bool front_first_seen_;
            bool front_second_seen_;
            bool rear_first_seen_;
};

#endif