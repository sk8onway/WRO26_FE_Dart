# Perception Module

## Purpose

The perception subsystem detects competition obstacles using classical computer vision techniques.

Machine learning is intentionally avoided.

---

## Current Pipeline

```
Camera
      │
      ▼
Image Capture
      │
      ▼
HSV Conversion
      │
      ▼
Binary Color Mask
```

---

## Current Features

Implemented

- Camera Capture
- HSV Color Space Conversion
- Binary Color Segmentation

---

## Planned Pipeline

```
Camera
      │
      ▼
HSV Conversion
      │
      ▼
Binary Mask
      │
      ▼
Morphological Filtering
      │
      ▼
Contour Detection
      │
      ▼
Pillar Detection
      │
      ▼
Vision Data
```

---

## Planned Outputs

The perception system will provide:

- Pillar Color
- Image Position
- Bounding Box
- Estimated Distance

These outputs will be consumed by the navigation subsystem.

---

## Design Philosophy

The perception subsystem only performs sensing.

Decision making is performed by the navigation subsystem.