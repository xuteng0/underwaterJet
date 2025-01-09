#include "button.h"
#include "motor.h"
#include "led.h"

const int motorPin = 3;
const int buttonPin = 2;
const int ledPin = 13;

void setup()
{
  Serial.begin(115200);
  button_init(buttonPin);
  motor_init(motorPin, 0.1);
  led_init(ledPin);
  delay(1000);
  led_set_on();
  Serial.println("Setup complete.");
}

void loop()
{
  static unsigned int lastCount = 0;
  unsigned int count = button_get_count(); // Get the current button click count
  static float lastSpeed = 0;
  float currentSpeed = motor_get_current_speed(); // Get the current motor speed

  // Print the count if it's greater than 0
  if (lastCount != count)
  {
    Serial.print("btnCount:");
    Serial.println(count);
    lastCount = count;
  }

  if(lastSpeed != currentSpeed)
  {
    Serial.print("speed:");
    Serial.print(currentSpeed);
    Serial.println("%");
    lastSpeed = currentSpeed;
  }

  if (count == 0 || !button_is_pressed())
  {
    motor_set_speed(0);
  }
  else if (count == 1)
  {
    motor_ramp_to_speed(15);
  }
  else if (count == 2)
  {
    motor_ramp_to_speed(50);
  }
  else
  {
    motor_ramp_to_speed(100);
  }
  delay(1);
}
