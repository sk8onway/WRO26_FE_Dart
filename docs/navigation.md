# Navigation Module

## Purpose

The navigation subsystem converts sensor information into steering decisions.

The current implementation consists of several reusable modules.

---

## Pure Pursuit Controller

Responsible for computing steering angles from generated paths.

Input

- Robot Pose
- Waypoint Path

Output

- Steering Angle

---

## SensorData

Acts as a common interface for navigation sensors.

Stores:

- Ground Color Sensors
- ToF Sensors
- Future sensor values

---

## DirectionDetector

Determines whether the robot is travelling clockwise or counter-clockwise using ground color markers.

Output

- CW
- CCW

---

## MarkerTracker

Tracks valid marker sequences.

Responsibilities

- Detect section crossings
- Ignore invalid sequences
- Report completed sections

---

## LapCounter

Counts completed sections.

Every four completed sections correspond to one completed lap.

Output

- Section Count
- Lap Count

---

## Future Work

- Open Challenge FSM
- Obstacle Challenge FSM
- Parking Logic
- Dynamic Path Planning