# Software Architecture

The software is divided into independent subsystems.

```
                 Camera
                    │
                    ▼
             Perception Module
                    │
                    ▼
               Vision Data
                    │
                    ▼
        Challenge-specific FSM
                    │
                    ▼
            Path Generation
                    │
                    ▼
        Pure Pursuit Controller
                    │
                    ▼
         Ackermann Steering
```

The navigation algorithms are independent from perception.

Likewise, perception does not directly control the robot.

Both subsystems communicate through shared interfaces.

This modular architecture simplifies debugging, testing and future expansion.