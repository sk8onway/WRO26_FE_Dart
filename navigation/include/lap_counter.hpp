#ifndef LAP_COUNTER_HPP
#define LAP_COUNTER_HPP

class LapCounter
{
public:
    LapCounter();

    void update(bool section_crossed);

    int getSectionCount() const;

    int getLapCount() const;

private:
    static constexpr int SECTIONS_PER_LAP = 4;

    int section_count_;
    int lap_count_;
};

#endif