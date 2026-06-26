# WRO 2026 Future Engineers – Autonomous Vehicle

## Overview

This repository contains the software development of our autonomous vehicle for the **World Robot Olympiad (WRO) 2026 Future Engineers** competition.

The objective is to design a reliable autonomous Ackermann-steered vehicle capable of completing both the Open Challenge and Obstacle Challenge using deterministic robotics algorithms.

The project emphasizes:

- Classical Robotics
- Deterministic Control
- Modular Software Architecture
- Explainable Decision Making
- Competition Reliability

Machine learning is intentionally avoided unless required by the competition rules.

---

# Current Progress

## Navigation

- ✅ Pure Pursuit Controller
- ✅ Sensor Data Interface
- ✅ Direction Detection
- ✅ Marker Tracking
- ✅ Lap Counter

## Perception

- ✅ Camera Interface
- ✅ HSV Color Space Conversion
- ✅ Binary Color Mask Generation

---

# Planned Features

Navigation

- Open Challenge FSM
- Obstacle Challenge FSM
- Dynamic Path Generation
- Parking Logic

Perception

- Morphological Filtering
- Contour Detection
- Pillar Detection
- Distance Estimation

Hardware

- ToF Sensor Integration
- Color Sensor Integration
- Motor Interface
- Steering Control

---

# Sensor Stack

Current planned hardware:

- Monocular Camera
- 3 × ToF Distance Sensors
- 2 × Ground Color Sensors

---

# Software Architecture

```
Camera
      │
      ▼
Perception
      │
      ▼
Vision Data
      │
      ▼
Challenge FSM
      │
      ▼
Path Generator
      │
      ▼
Pure Pursuit
      │
      ▼
Ackermann Steering
```

---

# Repository Structure

```
navigation/
    include/
    src/

perception/
    include/
    src/

docs/

README.md
```

---

# Development Philosophy

The software is developed as independent reusable modules.

Each module has:

- One responsibility
- Well-defined inputs
- Well-defined outputs
- Independent testing

This allows both competition challenges to reuse the same core software components.

---

# Competition

World Robot Olympiad

Future Engineers

2026