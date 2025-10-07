AUM-Future-Engineers-2025/
│
├── README.md
├── LICENSE
│
├── docs/
│   ├── Vehicle_Design_Report.pdf          ← Detailed printed documentation
│   ├── System_Architecture.png            ← Overall system block diagram
│   ├── Sensor_Placement_Diagram.png       ← Position layout of sensors
│   └── commit_log_summary.txt             ← Development and commit timeline
│
├── code/
│   ├── main_controller/
│   │   ├── main.py / main.cpp             ← Main program controlling movement and logic
│   │   ├── motor_control.py               ← DC motor and steering control
│   │   ├── navigation.py                  ← Track-following and lap logic
│   │   └── sensors.py                     ← Ultrasonic and other sensor interfaces
│   ├── vision/
│   │   ├── line_tracking.py               ← Line or lane-following camera processing
│   │   └── object_detection.py            ← Red/green traffic sign detection
│   └── utils/
│       └── helper_functions.py            ← Shared utility functions
│
├── models/
│   ├── chassis_3d_model.stl               ← 3D printable chassis model
│   ├── sensor_mount.stl                   ← Mount model for ultrasonic sensors
│   └── wheel_cad_model.stl                ← Wheel CAD model
│
├── videos/
│   └── demo_link.txt                      ← YouTube demo link (public/unlisted)
│
└── photos/
    ├── top_view.jpg
    ├── bottom_view.jpg
    ├── left_side.jpg
    ├── right_side.jpg
    ├── front_view.jpg
    ├── rear_view.jpg
    └── team_photo.jpg


<p align="center">
  <img width="512" height="512" alt="AUMers Logo" src="https://github.com/user-attachments/assets/88de7538-2cd9-4d02-96d0-4ed30c3b0e1c" />
</p>



Discussion, Information, and Motivation for the Vehicle’s Mobility, Power, Sensing, and Obstacle Management
====

Our autonomous vehicle, AUMers, is engineered to perform fully autonomous driving while completing three laps on a track with randomly placed walls and traffic signs. The project combines mechanical design, embedded control, and computer vision to achieve precise navigation, adaptive decision-making, and robust obstacle management.
________________________________________
1. Mobility System
Our autonomous vehicle, AUMers, is designed to demonstrate precise navigation, intelligent sensing, and adaptive obstacle management under dynamic conditions. The primary goal of the project is to develop a robust system capable of completing three laps on a closed track featuring randomized wall and traffic sign placements, while maintaining reliable control and safety throughout the run. 
The robot’s chassis is designed for optimal balance and traction, ensuring smooth operation during turns and speed changes. One DC motor provide the car to drive forward or backward, while a front servo motor is used for steering control. The combination of DC motor (Driving forward/backward) and servo steering enables the robot to maintain smooth motion while following curves and making fine adjustments based on sensor data.
________________________________________
2. Power System
The entire system is powered by a 7.4V Li-Po battery, providing a stable power supply for both the control electronics and motors. The Xmotion board manages power distribution efficiently, ensuring stable operation even during rapid acceleration or steering corrections.
This setup minimizes electrical noise and voltage drop, ensuring consistent performance throughout the three laps and the final parking sequence.
________________________________________
3. Sensing System
To achieve reliable detection of the surrounding objects and track walls, the robot integrates multiple sensing components:
•	Ultrasonic Sensors (HC-SR04):
Three ultrasonic sensors are mounted strategically — one facing forward, one angled to the right, and one angled to the left. These sensors continuously measure the distance to the surrounding walls or obstacles.
The robot uses this data to maintain its centered position within the track, dynamically adjusting its steering based on the distance difference between the left and right sensors. This ensures stable navigation even when the wall positions are randomized.
•	PixyCam (Vision Sensor):
In the Obstacle Challenge, a PixyCam is used for traffic sign recognition. The camera is pre-trained to detect two specific color markers:
1-	Red pillar → indicates the robot must keep to the right side of the lane.
2-	Green pillar → indicates the robot must keep to the left side of the lane.
The PixyCam sends real-time color detection data to the Xmotion controller, which processes the information and adjusts the driving path accordingly. The robot is programmed to avoid touching or displacing any traffic signs during operation.
________________________________________
4. Obstacle Management and Intelligent Behavior
The robot combines data from ultrasonic sensors and the PixyCam to build an adaptive understanding of its environment.
•	The ultrasonic sensors prevent collisions with the side walls and allow precise lane centering.
•	The PixyCam provides high-level scene interpretation, enabling behavior-based decision-making when encountering colored traffic indicators.
After completing the three laps, AUMers executes its final autonomous task: locating and entering the parking zone. Using visual data and distance measurements, the robot identifies the parking area and performs a parallel parking maneuver precisely within the designated space.
________________________________________
5. Motivation and Engineering Principles
The AUMers project was developed to simulate real-world autonomous driving scenarios within the World Robot Olympiad framework. The system design reflects principles used in modern robotics — sensor fusion, embedded control, and real-time decision-making.
Our motivation is to demonstrate how a compact, educational platform can replicate key aspects of autonomous vehicle behavior — perception, reasoning, and control — while maintaining simplicity, robustness, and modularity. The integration of the Xmotion controller, ultrasonic sensors, and vision-based navigation represents a complete engineering solution that balances performance and reliability.
This project embodies our commitment to engineering excellence, teamwork, and the spirit of innovation that defines the Future Engineers category at WRO.


