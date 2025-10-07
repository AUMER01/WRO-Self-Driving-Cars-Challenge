#🤖 AUMers – AUM University Future Engineers 2025
<p align="center"> <img width="512" height="512" alt="AUMers Logo" src="https://github.com/user-attachments/assets/88de7538-2cd9-4d02-96d0-4ed30c3b0e1c" /> </p>
📘 Table of Contents

## Table of Contents

- [Project Overview](#project-overview)
- [Repository Structure](#repository-structure)
  - [docs/](#docs)
  - [code/](#code)
  - [main_controller/](#main_controller)
  - [vision/](#vision)
  - [utils/](#utils)
  - [models/](#models)
  - [videos/](#videos)
  - [photos/](#photos)
- [Hardware and Components](#hardware-and-components)
- [Software Description](#software-description)
- [Mobility, Power, and Sensing System](#mobility-power-and-sensing-system)
- [Obstacle Management and Vision System](#obstacle-management-and-vision-system)
- [Testing and Calibration](#testing-and-calibration)
- [Results and Performance](#results-and-performance)
- [Video Demonstration](#video-demonstration)
- [Team Members](#team-members)
- [License](#license)


## 🧩 Project Overview

AUMers is an autonomous vehicle developed by AUM University (Kuwait) for the World Robot Olympiad – Future Engineers 2025 competition.
The vehicle is designed to navigate a track autonomously, complete three laps under randomized wall conditions, detect colored traffic signs (red and green pillars), and finish with an automatic parking maneuver.

This project demonstrates the integration of mobility control, sensor-based navigation, and computer vision using an Xmotion controller, ultrasonic sensors, and a PixyCam.


## 📁 docs/

Contains all reference documents and diagrams related to system design, sensor placement, and commit history.


## ⚙️ code/

Includes all software used to control and operate the robot:

main_controller/ – core driving and logic code

vision/ – image processing and traffic sign recognition

utils/ – helper functions shared between modules


## 🧱 models/

3D printable and CAD files used for the robot’s mechanical structure.


## 🎥 videos/

Contains a text file with a YouTube demo link showing the autonomous driving test.


## 📸 photos/

Includes high-resolution images of the robot (all sides), system components, and the team.


## 🔩 Hardware and Components
Component	Description	Purpose
Xmotion Controller	Integrated motor control + logic board	Core control and communication unit
DC Motors	Dual drive motors	Provide motion and steering control
Servo Motor	Steering actuator	Front wheel steering
Ultrasonic Sensors (HC-SR04)	3 units (front, left, right)	Distance measurement and wall alignment
PixyCam	Vision sensor	Detects traffic signs and parking cues
7.4V Li-Po Battery	Power supply	Provides energy to the system
3D Printed Chassis and Mounts	Custom design	Mechanical support and sensor positioning


## 💻 Software Description

The software is written in Python and runs on the Xmotion platform.
The architecture is divided into independent modules for sensing, control, navigation, and vision.
Key algorithms include:

PID-based motor speed control

Obstacle avoidance logic using ultrasonic data

Vision-based color detection for lane side selection

Parallel parking maneuver using combined vision and distance feedback


## 🚗 Mobility, Power, and Sensing System

The robot’s mobility relies on two DC motors controlled through the Xmotion board, providing smooth and precise motion.
A 7.4V Li-Po battery powers all components efficiently.
Three ultrasonic sensors maintain the robot’s centered position by comparing left and right distances, ensuring lane balance and wall avoidance.


## 👁️ Obstacle Management and Vision System

The PixyCam identifies red and green pillars:

Red pillar: stay on the right side of the lane

Green pillar: stay on the left side of the lane

Using the color recognition data, the robot dynamically adjusts its path.
Obstacle avoidance and wall-following behavior are combined with vision-based decisions for reliable navigation.


## 🧪 Testing and Calibration

Several tests were conducted to:

Calibrate ultrasonic sensor distances for accurate wall tracking

Train the PixyCam on various lighting conditions

Tune motor speed and steering PID parameters for smooth cornering

Validate the final three-lap and parking performance


##📈 Results and Performance
Test	Outcome
Track navigation (3 laps)	Completed successfully in consistent times
Traffic sign recognition	>95% accuracy in various lighting conditions
Obstacle avoidance	Smooth navigation with no collisions
Parking maneuver	Successfully performed parallel parking within boundaries


##🎬 Video Demonstration

🎥 Watch the YouTube Demo

(Ensure the video is set to “public” or “unlisted” so judges can access it)


##👨‍🔧 Team Members
Name	Role	Responsibility
[Your Name]	Team Leader	System integration, navigation logic
[Member 2]	Hardware Engineer	Chassis design, wiring, and assembly
[Member 3]	Software Engineer	Vision system and code optimization
[Member 4]	Documentation Lead	Report writing and GitHub maintenance


##📄 License

This project is licensed under the MIT License — see the LICENSE
 file for details.
