#include "lap_counter.hpp"
#include <iostream>

LapCounter::LapCounter()
{
    section_count_ = 0;
    lap_count_ = 0;
}

void LapCounter::update(bool section_crossed)
{
    if(section_crossed)
    {
        section_count_++;

        std::cout << "Section: "
                  << section_count_
                  << std::endl;

        if(section_count_ >= SECTIONS_PER_LAP)
        {
            lap_count_++;

            std::cout << "Lap "
                      << lap_count_
                      << " completed\n";

            section_count_ = 0;
        }
    }
}

int LapCounter::getSectionCount() const
{
    return section_count_;
}

int LapCounter::getLapCount() const
{
    return lap_count_;
}