#include <Servo.h>
#include <Pixy2.h>

// ===== Debug Toggle =====
#define DEBUG_OUTPUT true  // Set to false to disable Serial prints

// ===== Pins =====
//echo blue
//trig purple
//gnd green
//vcc orange
const int TRIG_LEFT  = 6;
const int ECHO_LEFT  = 5; 
const int TRIG_RIGHT = 4;
const int ECHO_RIGHT = 2;
const int SERVO_PIN  = 9;


// ===== Motor Driver (Cytron MD13S) =====
const int PWM_PIN = 3;   // PWM pin for motor speed
const int DIR_PIN = 8;   // Direction pin yellow 

// ===== Speed Settings =====
const int MOTOR_SPEED = 35;  // Fixed motor speed

// ===== PD Control Settings =====
const float KP = 1.1;
const float KD = 1.1;

// ===== Steering Angles =====
const int CENTER_ANGLE = 50;
const int MIN_SERVO_ANGLE = 0; //right
const int MAX_SERVO_ANGLE = 100; //left

// ===== Pixy2 Steering Angles =====
const int GREEN_SOFT_LEFT    = 70;
const int GREEN_MED_LEFT     = 80;
const int GREEN_HARD_LEFT    = 90;
const int RED_SOFT_RIGHT = 30;
const int RED_MED_RIGHT  = 20;
const int RED_HARD_RIGHT = 10;

// ===== State Variables =====
Servo steeringServo;
Pixy2 pixy;

float lastError = 0;
bool pixyActive = false;

void setup() {
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, HIGH);

  steeringServo.attach(SERVO_PIN);
  steeringServo.write(CENTER_ANGLE);

  if (DEBUG_OUTPUT) Serial.begin(115200);
  pixy.init(4);

  if (DEBUG_OUTPUT) Serial.println("Robot Ready!");
}

void loop() {
  // ===== Read Ultrasonic Sensors =====
  float leftDist = getDistance(TRIG_LEFT, ECHO_LEFT);
  float rightDist = getDistance(TRIG_RIGHT, ECHO_RIGHT);

  // Handle invalid readings
  if (leftDist < 0) leftDist = rightDist;
  if (rightDist < 0) rightDist = leftDist;

  // ===== Pixy2 Pillar Steering =====
  int blocks = pixy.ccc.getBlocks();
  pixyActive = false;

  if (blocks > 0) {
    int sig = pixy.ccc.blocks[0].m_signature;
    int x = pixy.ccc.blocks[0].m_x;

    if (sig == 1) { // Red right
      pixyActive = true;
      if (x <= 120) steeringServo.write(RED_SOFT_RIGHT); //if on left: go slightly to right
      else if (x <= 200) steeringServo.write(RED_MED_RIGHT);
      else steeringServo.write(RED_HARD_RIGHT);
    }
    else if (sig == 2) { // Green left
      pixyActive = true;
      if (x >= 200) steeringServo.write(GREEN_SOFT_LEFT);
      else if (x >= 120) steeringServo.write(GREEN_MED_LEFT);
      else steeringServo.write(GREEN_HARD_LEFT);
    }
  }

  // ===== Ultrasonic PD Steering =====
  if (!pixyActive) {
    float error = leftDist - rightDist;
    float derivative = error - lastError;
    float pdOutput = KP * error + KD * derivative;
    int servoAngle = constrain(CENTER_ANGLE + pdOutput, MIN_SERVO_ANGLE, MAX_SERVO_ANGLE);
    steeringServo.write(servoAngle);
    lastError = error;
  }

  // ===== Drive Forward =====
  runMotor(MOTOR_SPEED, false);

  // ===== Debug Output =====
  if (DEBUG_OUTPUT) {
    Serial.print("Pixy: "); Serial.print(pixyActive ? "YES" : "NO");
    Serial.print(" | L: "); Serial.print(leftDist);
    Serial.print(" cm | R: "); Serial.print(rightDist);
    Serial.print(" cm | Servo: "); Serial.println(steeringServo.read());
  }

  delay(50);
}

// ===== Helper Functions =====
float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration <= 0) return -1;
  return duration * 0.034 / 2.0;
}

void runMotor(int speed, bool reverse) {
  digitalWrite(DIR_PIN, reverse ? LOW : HIGH);
  analogWrite(PWM_PIN, speed);
}

