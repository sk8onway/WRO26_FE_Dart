#include "marker_tracker.hpp"
#include <iostream>

MarkerTracker::MarkerTracker()
{
    reset();
}

void MarkerTracker::reset()
{
    front_first_seen_=false;
    front_second_seen_=false;
    rear_first_seen_=false;
}

bool MarkerTracker::update(
    const SensorData& sensors,
    Direction direction)
{
    if(direction == Direction::CCW)
    {
        if(!front_first_seen_ && sensors.front_blue)
        {
            front_first_seen_=true;
            std::cout << "Front blue marker seen\n";
        }
        if(front_first_seen_ && !front_second_seen_ && sensors.front_orange)
        {
            front_second_seen_=true;
            std::cout << "Front sequence completed\n";
        }
        if(!rear_first_seen_ && front_second_seen_ && sensors.rear_blue)
        {
            rear_first_seen_=true;
            std::cout << "Rear blue marker seen\n";
        }
        if(front_second_seen_ && rear_first_seen_ && sensors.rear_orange)
        {
            std::cout << "Section completed in CCW direction\n";
            reset();
            return true;
        }
    }
    else if(direction == Direction::CW)
    {
        if(!front_first_seen_ && sensors.front_orange)
        {
            front_first_seen_=true;
            std::cout << "Front orange marker seen\n";
        }
        if(front_first_seen_ && !front_second_seen_ && sensors.front_blue)
        {
            front_second_seen_=true;
            std::cout << "Front sequence completed\n";
        }
        if(!rear_first_seen_ && front_second_seen_ && sensors.rear_orange)
        {
            rear_first_seen_=true;
            std::cout << "Rear orange marker seen\n";
        }
        if(front_second_seen_ && rear_first_seen_ && sensors.rear_blue)
        {
            std::cout << "Section completed in CW direction\n";
            reset();
            return true;
        }
    }
    return false;
}