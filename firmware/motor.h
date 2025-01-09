// motor.h
#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

// Motor PWM settings
#define PWM_UPPER_LIMIT 2000  // Full forward
#define PWM_STOP_DUTY_CYCLE 1500
#define PWM_LOWER_LIMIT 1000  // Full reverse


// Speed percentage limits
#define MOTOR_MIN_PERCENT -100
#define MOTOR_MAX_PERCENT 100

void motor_init(int pin, float increment_step=1);
void motor_set_speed(float percent);
float motor_ramp_to_speed(float percent);
float motor_get_current_speed();

#endif // MOTOR_H