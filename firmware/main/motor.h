// Motor.h
#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <Servo.h>

class Motor {
private:
    Servo motorServo;           // Servo object for motor control
    const int motorPin;         // Pin for motor control (constant after initialization)
    const int pwmUpperLimit;    // Full forward PWM limit
    const int pwmLowerLimit;    // Full reverse PWM limit
    const int pwmStopDutyCycle; // Stop position PWM value

    float currentSpeed;  // Current speed (-1 to 1)
    float targetSpeed;   // Target speed (-1 to 1)

public:
    // Constructor
    Motor(int pin, int upperLimit = 2000, int lowerLimit = 1000, int stopDutyCycle = 1500);

    // Initialize the motor
    void init();

    // Set the motor speed directly
    void setSpeed(float speed);

    // Gradually ramp to the target speed, returns the current speed
    float rampToSpeed(float speed, float incrementStep = 0.1);

    // Get the current motor speed
    float getCurrentSpeed() const;
};

#endif // MOTOR_H