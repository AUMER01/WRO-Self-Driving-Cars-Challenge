#🤖 AUMers – AUM University Future Engineers 2025
<p align="center"> <img width="512" height="512" alt="AUMers Logo" src="https://github.com/user-attachments/assets/88de7538-2cd9-4d02-96d0-4ed30c3b0e1c" /> </p>

## Table of Contents

- [🧩 Project Overview](#-project-overview)
- [Repository Structure](#-repository-structure)
  - [📁 docs/](#-docs)
  - [⚙️ code/](#-code)
  - [main_controller/](#main_controller)
  - [vision/](#vision)
  - [🧱 models/](#-models)
  - [🎥 videos/](#-videos)
  - [📸 photos/](#-photos)
- [🔩 Hardware and Components](#-hardware-and-components)
- [💻 Software Description](#-software-description)
- [🚗 Mobility, Power, and Sensing System](#-mobility-power-and-sensing-system)
- [👁️ Obstacle Management and Vision System](#-obstacle-management-and-vision-system)
- [🧪 Testing and Calibration](#-testing-and-calibration)
- [📈 Results and Performance](#-results-and-performance)
- [🎬 Video Demonstration](#-video-demonstration)
- [👨‍🔧 Team Members](#-team-members)


## 🧩 Project Overview

The AUMers project introduces an autonomous vehicle designed to complete three fully autonomous laps on a closed track featuring randomly traffic signs. The system integrates mechanical design, embedded control, and computer vision to achieve smooth navigation, adaptive decision-making, and intelligent obstacle management.

AUMers is built around four core subsystems:

Mobility System:
A balanced chassis driven by a DC motor for propulsion and a servo motor for steering enables precise motion control. The system ensures stable navigation through curves and speed variations using real-time sensor feedback.

Power System:
A 7.4V Li-Po battery supplies stable power to both motors and control electronics. The Xmotion board manages efficient power distribution, minimizing electrical noise and ensuring consistent performance during acceleration and steering.

Sensing System:
Three ultrasonic sensors continuously measure distances to nearby walls and obstacles, maintaining the robot’s centered position. A PixyCam vision sensor detects red and green traffic markers, guiding directional decisions and sign-based behavior.

Obstacle Management and Intelligent Behavior:
Sensor fusion between ultrasonic data and PixyCam vision enables dynamic lane centering, traffic sign interpretation, and collision avoidance. After completing three laps, the vehicle autonomously locates and parks precisely within the designated zone.

Overall, AUMers demonstrates a comprehensive approach to autonomous mobility, combining reliable sensing, efficient power control, and intelligent decision-making to operate safely and effectively in a variable environment.


## 📁 docs/

Contains all reference documents and diagrams related to system design, sensor placement, and commit history.


## ⚙️ code/

The full code for both open challenge and obstacle challenge are provided inside code file on the top of this page. 


## 🧱 models/

3D printed design used for the robot’s mechanical structure.
<p align="center"> <img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/41ec272d-5294-4c83-8e19-9ecab00ad179" />


## 🎥 videos/

This is a YouTube link showing a demo for our autonomous driving test.
https://www.youtube.com/shorts/YcODsZENiaM
The full viseos for both open challenge and obstacle challenge are provided inside videos file on the top of this page

## 📸 photos/

Images of the robot (all sides)
<div align="center">

<table>
  <tr>
    <td><img width="220" src="https://github.com/user-attachments/assets/bcfedd58-0cac-417d-aeb3-2eb8b212f7ef" /></td>
    <td><img width="220" src="https://github.com/user-attachments/assets/a8079dca-615e-4b55-9f72-6bb9f630937b" /></td>
    <td><img width="220" src="https://github.com/user-attachments/assets/e3ce21d4-4cd9-439d-9274-82af3605b75f" /></td>
  </tr>
  <tr>
    <td><img width="220" src="https://github.com/user-attachments/assets/581d9ba8-7fb7-40f2-ab8f-64d2de9f3165" /></td>
    <td><img width="220" src="https://github.com/user-attachments/assets/2a9d8bb3-ee46-4803-8cc3-46ba6ddcda77" /></td>
    <td><img width="220" src="https://github.com/user-attachments/assets/afcc0fe8-2d0e-4aef-aea4-6d611f3f30ef" /></td>
  </tr>
</table>

Robot's components
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/b178bf55-6c87-4521-a2f3-9c944bf2b491" />

Tools Used in the Lab
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/b750eb5a-1c5d-4c75-9160-fdc2dd91ea35" />



## 🔩 Hardware and Components

| Component                | Description                         | Purpose                                      |
|--------------------------|-------------------------------------|---------------------------------------------|
| Xmotion Controller       | Integrated motor control + logic board | Core control and communication unit        |
| DC Motor                | Provide motion and steering control | Drive system for movement and steering      |
| Servo Motor              | Steering actuator                   | Front wheel steering                         |
| Ultrasonic Sensors (HC-SR04) | 3 units (front, left, right)     | Distance measurement and wall alignment     |
| PixyCam Version 2.1      | Vision sensor                        | Detects traffic signs and parking cues      |
| 7.4V Li-Po Battery       | Power supply                         | Provides energy to the system               |
| 3D Printed Chassis and Mounts | Custom design                     | Mechanical support and sensor positioning   |



## 💻 Software Description

The Xmotion board is programmed using the Arduino IDE, with code written in C/C++.
The code architecture is divided into independent modules for sensing, control, navigation, and vision.

## 🚗 Mobility, Power, and Sensing System

The robot’s mobility relies on one DC motors controlled through the Xmotion board, providing smooth and precise motion(Forward or Backward).
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


## 📈 Results and Performance
Test	Outcome
| Task                     | Performance                                      |
|--------------------------|-------------------------------------------------|
| Track navigation (3 laps) | Completed successfully in consistent times     |
| Traffic sign recognition  | >95% accuracy in various lighting conditions   |
| Obstacle avoidance        | Smooth navigation with no collisions           |
| Parking maneuver          | Successfully performed parallel parking within boundaries |



## 🎬 Video Demonstration

🎥 Watch the YouTube Demo

https://www.youtube.com/shorts/YcODsZENiaM

## 👨‍🔧 Team Members

| Name               | Role                | Responsibility                               |
|-------------------|-------------------|---------------------------------------------|
| Mohammad Sharsheer | Coach        | System integration, navigation logic        |
| Noor Alkhayat               | Chassis designer   | Chassis design and assembly, documentation, GitHub maintenance |
| Farah AlHayek              | Vision Detection programmer  | Vision system development and code optimization |



