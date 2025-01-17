// Motor.cpp
#include "Motor.h"

// Constructor
Motor::Motor(int pin, int upperLimit, int lowerLimit, int stopDutyCycle)
    : motorPin(pin), pwmUpperLimit(upperLimit), pwmLowerLimit(lowerLimit), pwmStopDutyCycle(stopDutyCycle),
      currentSpeed(0), targetSpeed(0) {}

// Initialize the motor
void Motor::init() {
    motorServo.attach(motorPin);
    motorServo.writeMicroseconds(pwmStopDutyCycle); // Set motor to stop position
    Serial.println("Motor initialized to stop position.");
}

// Set the motor speed directly
void Motor::setSpeed(float speed) {
    currentSpeed = constrain(speed, -1.0, 1.0);
    int pwmValue = map(currentSpeed * 1000, -1000, 1000, pwmLowerLimit, pwmUpperLimit);
    motorServo.writeMicroseconds(pwmValue);
}

// Gradually ramp to the target speed, returns the current speed
float Motor::rampToSpeed(float speed, float incrementStep) {
    targetSpeed = constrain(speed, -1.0, 1.0);

    if (currentSpeed < targetSpeed) {
        currentSpeed = min(currentSpeed + incrementStep, targetSpeed);
    } else if (currentSpeed > targetSpeed) {
        currentSpeed = max(currentSpeed - incrementStep, targetSpeed);
    }

    setSpeed(currentSpeed);
    return currentSpeed;
}

// Get the current motor speed
float Motor::getCurrentSpeed() const {
    return currentSpeed;
}
