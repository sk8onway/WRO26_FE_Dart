#include "pure_pursuit.hpp"
#include <iostream>
#include <cmath>

PurePursuitController::PurePursuitController(double wheelbase, double lookahead_distance)
    : wheelbase_(wheelbase), lookahead_distance_(lookahead_distance) {}

double PurePursuitController::computeSteering(
    const Pose& current_pose,
    const std::vector<Waypoint>& path)
{
    Waypoint target = findLookaheadPoint(current_pose, path);
    // Simplified steering computation - replace with actual pure pursuit logic

    double dx = target.x - current_pose.x;
    double dy = target.y - current_pose.y;
    double local_x = cos(current_pose.yaw) * dx + sin(current_pose.yaw) * dy;
    double local_y = -sin(current_pose.yaw) * dx + cos(current_pose.yaw) * dy;
    double ld = sqrt(local_x * local_x + local_y * local_y);
    double curvature = (2 * local_y) / (ld * ld);
    double steering_angle = atan(wheelbase_ * curvature);

    std::cout
    << "Target: "
    << target.x << ", "
    << target.y << std::endl;

    std::cout
    << "Local X: "
    << local_x << std::endl;

    std::cout
    << "Local Y: "
    << local_y << std::endl;

    std::cout
    << "Lookahead Distance: "
    << ld << std::endl;

    std::cout
    << "Curvature: "
    << curvature << std::endl;

    std::cout
    << "Steering Angle: "
    << steering_angle << std::endl;

    return steering_angle;
}

Waypoint PurePursuitController::findLookaheadPoint(
    const Pose& current_pose,
    const std::vector<Waypoint>& path)
{
    for(const Waypoint& waypoint : path)
    {
        double dx = waypoint.x - current_pose.x;
        double dy = waypoint.y - current_pose.y;
        double distance = sqrt(dx*dx + dy*dy);
        if (distance >= lookahead_distance_)
        {
            return waypoint;
        }
    }
    return path.back(); // Return the last waypoint if no lookahead point is found
}
    