// motor.cpp
#include "motor.h"
#include <Servo.h>

static Servo motorServo; // Servo object for motor control
static float currentSpeedPercent = 0;
static int targetSpeedPercent = 0;
static int motorPin;
static float speed_increment_step = 10; // Increment per ramp step

// Initialize the motor
void motor_init(int pin, float increment_step)
{
    motorPin = pin;
    speed_increment_step = increment_step;
    motorServo.attach(motorPin);
    motorServo.writeMicroseconds(PWM_STOP_DUTY_CYCLE); // Set motor to stop position
    currentSpeedPercent = 0;
    Serial.println("Motor initialized to stop position.");
}

// Set the motor speed directly
void motor_set_speed(float percent)
{
    static int last_pwm_value = 0;
    static float last_speed_percent = 0;
    currentSpeedPercent = constrain(percent, MOTOR_MIN_PERCENT, MOTOR_MAX_PERCENT);
    int pwmValue = map(currentSpeedPercent, MOTOR_MIN_PERCENT, MOTOR_MAX_PERCENT, PWM_LOWER_LIMIT, PWM_UPPER_LIMIT);
    motorServo.writeMicroseconds(pwmValue);

    // if(pwmValue != last_pwm_value || currentSpeedPercent != last_speed_percent)
    // {
    //     Serial.print("Motor speed:");
    //     Serial.print(currentSpeedPercent);
    //     Serial.print("%, PWM:");
    //     Serial.println(pwmValue);

    //     last_pwm_value = pwmValue;
    //     last_speed_percent = currentSpeedPercent;
    // }
}

// Gradually ramp to the target speed, returns the current speed percentage
float motor_ramp_to_speed(float percent)
{
    targetSpeedPercent = constrain(percent, MOTOR_MIN_PERCENT, MOTOR_MAX_PERCENT);

    if (currentSpeedPercent < targetSpeedPercent)
    {
        currentSpeedPercent = min(currentSpeedPercent + speed_increment_step, targetSpeedPercent);
    }
    else if (currentSpeedPercent > targetSpeedPercent)
    {
        currentSpeedPercent = max(currentSpeedPercent - speed_increment_step, targetSpeedPercent);
    }

    // Use motor_set_speed to apply the new speed
    motor_set_speed(currentSpeedPercent);
    return currentSpeedPercent;

    // Serial.print("Motor ramping to ");
    // Serial.print(targetSpeedPercent);
    // Serial.print("% (Current: ");
    // Serial.print(currentSpeedPercent);
    // Serial.println("%)");
}

// Get the current motor speed percentage
float motor_get_current_speed()
{
    return currentSpeedPercent;
}