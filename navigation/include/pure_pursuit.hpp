// pure_pursuit.hpp

#ifndef PURE_PURSUIT_HPP
#define PURE_PURSUIT_HPP

#include <vector>

struct Pose
{
    double x;
    double y;
    double yaw;
};

struct Waypoint
{
    double x;
    double y;
};

class PurePursuitController
{
public:
    PurePursuitController(double wheelbase,
                          double lookahead_distance);

    double computeSteering(
        const Pose& current_pose,
        const std::vector<Waypoint>& path);

    Waypoint findLookaheadPoint(
    const Pose& current_pose,
    const std::vector<Waypoint>& path);

private:
    double wheelbase_;
    double lookahead_distance_;
};

#endif