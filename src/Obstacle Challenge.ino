// ===== Libraries =====
#include <Servo.h>              // Controls steering servo

// ===== Debug Toggle =====
#define DEBUG_OUTPUT true        // Set to false to disable Serial prints

// ===== Pin Definitions =====
const int TRIG_LEFT  = A4;       // Ultrasonic left trigger pin
const int ECHO_LEFT  = A2;       // Ultrasonic left echo pin
const int TRIG_RIGHT = A5;       // Ultrasonic right trigger pin
const int ECHO_RIGHT = 1;        // Ultrasonic right echo pin
const int SERVO_PIN  = A1;       // Servo motor control pin
const int PWM_PIN    = 11;       // Motor PWM pin (speed control)
const int DIR_PIN    = 13;       // Motor direction control pin

// ===== Speed Settings =====
const int MOTOR_SPEED = 35;      // Normal driving speed

// ===== PD Controller Settings (wall-following) =====
const float KP = 2.0;            // Proportional gain
const float KD = 1.0;            // Derivative gain

// ===== Steering Angle Settings =====
const int CENTER_ANGLE     = 90;   // Servo center (straight ahead)
const int MIN_SERVO_ANGLE  = 30;   // Minimum steering angle (full right)
const int MAX_SERVO_ANGLE  = 150;  // Maximum steering angle (full left)

// ===== State Variables =====
Servo steeringServo;              // Steering servo object
float lastError = 0;              // Last PD control error (for derivative term)

// ===== Setup Function =====
void setup() {
  // Setup ultrasonic pins
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);

  // Setup motor pins
  pinMode(PWM_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, HIGH);    // Set motor direction (forward)

  // Setup servo
  steeringServo.attach(SERVO_PIN);
  steeringServo.write(CENTER_ANGLE);  // Start with wheels centered

  // Setup serial debug
  if (DEBUG_OUTPUT) Serial.begin(115200);
}

// ===== Main Loop =====
void loop() {
  // --- ULTRASONIC SENSORS ---
  float leftDist = getDistance(TRIG_LEFT, ECHO_LEFT);   // Left distance
  float rightDist = getDistance(TRIG_RIGHT, ECHO_RIGHT);// Right distance
  if (leftDist < 0) leftDist = rightDist;               // If failed, use other
  if (rightDist < 0) rightDist = leftDist;

  // --- PD Wall Following Control ---
  float error = leftDist - rightDist;                 // Difference in distances
  float derivative = error - lastError;               // Change in error
  float pdOutput = KP * error + KD * derivative;      // PD controller output
  int servoAngle = constrain(CENTER_ANGLE + pdOutput, // Calculate steering
                             MIN_SERVO_ANGLE,
                             MAX_SERVO_ANGLE);
  steeringServo.write(servoAngle);                    // Apply steering
  lastError = error;                                  // Save for next loop

  // --- Run Motor Forward ---
  runMotor(MOTOR_SPEED, false);

  // --- Debug Monitor Output ---
  if (DEBUG_OUTPUT) {
    Serial.print("L:"); Serial.print(leftDist);
    Serial.print(" R:"); Serial.print(rightDist);
    Serial.print(" | Servo: "); Serial.println(servoAngle);
  }

  delay(50);   // Small delay for stability
}

// ===== Helper Function: Get Ultrasonic Distance =====
float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);             // Clear trigger
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);            // Send 10µs pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);  // Measure echo time
  if (duration <= 0) return -1;                   // If timeout, return -1
  return duration * 0.034 / 2;                    // Convert to cm
}

// ===== Helper Function: Run Motor =====
void runMotor(int speed, bool reverse) {
  digitalWrite(DIR_PIN, reverse ? LOW : HIGH);  // Set direction
  analogWrite(PWM_PIN, speed);                  // Set speed (0–255)
}

