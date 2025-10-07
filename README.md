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
- [📄 License](#-license)


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

Includes code fucntions used to control and operate the robot:

main_controller/ – core driving and logic code
```cpp
void loop() {
  float leftDist = getDistance(TRIG_LEFT, ECHO_LEFT);   
  float rightDist = getDistance(TRIG_RIGHT, ECHO_RIGHT);
  if (leftDist < 0) leftDist = rightDist;               
  if (rightDist < 0) rightDist = leftDist;
  float error = leftDist - rightDist;                 
  float derivative = error - lastError;               
  float pdOutput = KP * error + KD * derivative;      
  int servoAngle = constrain(CENTER_ANGLE + pdOutput, 
                             MIN_SERVO_ANGLE,
                             MAX_SERVO_ANGLE);
  steeringServo.write(servoAngle);                    
  lastError = error;                                  
  runMotor(MOTOR_SPEED, false);
  if (DEBUG_OUTPUT) {
    Serial.print("L:"); Serial.print(leftDist);
    Serial.print(" R:"); Serial.print(rightDist);
    Serial.print(" | Servo: "); Serial.println(servoAngle);
  }

  delay(50);
}
```
vision/ – image processing and traffic sign recognition
```cpp
int blocks = pixy.ccc.getBlocks();     
  pixyActive = false;                   
  int sig3TotalX = 0, sig3Count = 0;
  for (int i = 0; i < blocks; i++) {
    if (pixy.ccc.blocks[i].m_signature == 3) {   
    
      sig3Count++;
    }
  }

  if (sig3Count > 0) {                    
    if (avgX < 120) steeringServo.write(RED_HARD_LEFT);
    else if (avgX > 200) steeringServo.write(GREEN_HARD_RIGHT);
    else steeringServo.write(CENTER_ANGLE);

    runMotor(SLOW_SPEED, false);          
    if (DEBUG_OUTPUT) Serial.println("PARKING MODE ACTIVE");
    return;                           
  }

  if (!parkingMode && blocks > 0) {
    int sig = pixy.ccc.blocks[0].m_signature;  
    int x   = pixy.ccc.blocks[0].m_x;         
    if (sig == 1) {   // Red object detected
      pixyActive = true;
      if (x >= 200) steeringServo.write(RED_SOFT_LEFT);
      else if (x >= 120) steeringServo.write(RED_MED_LEFT);
      else steeringServo.write(RED_HARD_LEFT);
    }
    else if (sig == 2) {   
      pixyActive = true;
      if (x <= 120) steeringServo.write(GREEN_SOFT_RIGHT);
      else if (x <= 200) steeringServo.write(GREEN_MED_RIGHT);
      else steeringServo.write(GREEN_HARD_RIGHT);
    }
  }
```


## 🧱 models/

3D printed design used for the robot’s mechanical structure.
<p align="center"> <img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/a00a63ab-6055-4bf1-bd73-553fc028580a" />
<p align="center"> <img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/d83b65ee-1889-44d3-88d0-1d860c7195da" />


## 🎥 videos/

This is a YouTube link showing a demo for our autonomous driving test.
https://www.youtube.com/shorts/YcODsZENiaM

## 📸 photos/

Includes high-resolution images of the robot (all sides), system components, and the team.
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/370c67ba-887e-4f19-9b49-af6233d8e356" />
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/9de4440c-2568-4540-a5c2-69495093c9ee" />
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/cf5b756a-f996-47a3-838f-0b76ed1a9f25" />
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/a3a793fc-9b64-4f06-9266-ef11fa7deebe" />
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/3c058c81-6d25-4169-a338-65a1c3444224" />
<p align="center"><img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/55c5cd97-d009-4695-becd-e91ec7da2367" />




## 🔩 Hardware and Components
Component	Description	Purpose
Xmotion Controlle:r	Integrated motor control + logic board	Core control and communication unit
DC Motors:	Provide motion and steering control
Servo Motor:	Steering actuator	Front wheel steering
Ultrasonic Sensors (HC-SR04)	3 units (front, left, right):	Distance measurement and wall alignment
PixyCam	Virsion 2.1:	Detects traffic signs and parking cues
7.4V Li-Po Battery:	Power supply	Provides energy to the system
3D Printed Chassis and Mounts:	Custom design	Mechanical support and sensor positioning


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
Track navigation (3 laps):	Completed successfully in consistent times
Traffic sign recognition:	>95% accuracy in various lighting conditions
Obstacle avoidance:	Smooth navigation with no collisions
Parking maneuver:	Successfully performed parallel parking within boundaries


## 🎬 Video Demonstration

🎥 Watch the YouTube Demo



## 👨‍🔧 Team Members

| Name               | Role                | Responsibility                               |
|-------------------|-------------------|---------------------------------------------|
| Mohammad Sharsheer | Team Leader        | System integration, navigation logic        |
| Noor Alkhayat               | Chassis Designer   | Chassis design and assembly, documentation, GitHub maintenance |
| Farah AlHayek              | Vision Engineer    | Vision system development and code optimization |



##📄 License

 file for details.
