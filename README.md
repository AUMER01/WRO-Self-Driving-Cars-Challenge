Engineering materials
====

This repository contains engineering materials of **AUMers** self-driven vehicle's model participating in the WRO Future Engineers competition in the season 2025.
<img width="1024" height="1024" alt="image" src="https://github.com/user-attachments/assets/f051f0e4-e086-4fe0-86a9-88b353c8dc6b" />



## Content

* `t-photos` contains 2 photos of the team (an official one and one funny photo with all team members)
* `v-photos` contains 6 photos of the vehicle (from every side, from top and bottom)
* `video` contains the video.md file with the link to a video where driving demonstration exists
* `schemes` contains one or several schematic diagrams in form of JPEG, PNG or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.
* `src` contains code of control software for all components which were programmed to participate in the competition
* `models` is for the files for models used by 3D printers, laser cutting machines and CNC machines to produce the vehicle elements. If there is nothing to add to this location, the directory can be removed.
* `other` is for other files which can be used to understand how to prepare the vehicle for the competition. It may include documentation how to connect to a SBC/SBM and upload files there, datasets, hardware specifications, communication protocols descriptions etc. If there is nothing to add to this location, the directory can be removed.

## Introduction

_This part includes the technical clarifications about the code: which modules the code consists of, how they are related to the electromechanical components of the vehicle, and what is the process to build/compile/upload the code to the vehicle’s controllers._
Python code explanation for a self-driving car prototype using a Raspberry Pi:
1. Hardware Setup
•	Motor Control (MD13S Driver)
o	DIR (Pin 23): Sets motor direction (forward/reverse).
o	PWM (Pin 18): Controls motor speed via PWM (1 kHz frequency).
•	Servo Motor (Steering)
o	SERVO_PIN (Pin 17): Adjusts steering angle using 50 Hz PWM.
o	Limits: min_right_servo=3.0 (max left), max_right_servo=10.0 (max right).
•	Ultrasonic Sensors (3x)
o	Pins for left, front, and right sensors (TRIG/ECHO GPIOs).
o	Avoid GPIO conflicts by using non-overlapping pins (e.g., front sensor uses 20/21).

2. Core Functions
•	Motor Control
o	set_motor_forward(speed_percent): Drives motor forward at a given speed (e.g., motor_speed=40%).
o	stop_motor(): Stops the motor by setting PWM duty cycle to 0.
•	Servo Control
o	set_servo_angle(duty): Adjusts steering angle by changing PWM duty cycle (3.0–10.0 ≈ 0°–180°).
•	Distance Measurement
o	measure_distance(trig_pin, echo_pin): Uses ultrasonic sensors to calculate distance (cm) via echo pulse timing.
	Timeout: Returns None if no echo is detected within 50 ms.
•	Proportional Steering Logic
o	calculate_servo_duty(): Adjusts servo angle based on the error (difference between left/right sensor distances).
	KP Gain: 1.5 / max_error_cm ensures smooth corrections (clamped to servo limits).

3. Main Workflow
1.	Initialization
o	Motor starts at motor_speed=40% and servo centers at 7.5 duty cycle.
o	A timer (timer=23.478s) is set to stop the car after a fixed duration.
2.	Sensor Loop
o	Measures distances from left and right ultrasonic sensors.
o	Handles timeouts by defaulting to 100 cm if no echo is detected.
o	Calculates error (dist_left - dist_right):
	Positive error: Too close to the right → steer left.
	Negative error: Too close to the left → steer right.
3.	Steering Adjustment
o	Converts error into a servo duty cycle using proportional control (KP).
o	Prints real-time data (distances, error, servo duty) for debugging.
4.	Shutdown
o	Stops after the timer expires or on KeyboardInterrupt (Ctrl+C).
o	Cleans up GPIO pins to prevent damage.

