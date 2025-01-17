#include "button.h"
#include "motor.h"
#include "led.h"
#include "pin.h"

Motor motorL(motorLeftPin, 2000, 1000, 1500);   // clockwise propeller
Motor motorR(motorRightPin, 1000, 2000, 1500);  // anticlockwise propeller

void setup() {
  Serial.begin(115200);
  button_init(buttonPin);
  motorL.init();
  motorR.init();
  led_init(ledPin);
  delay(1000);
  led_set_on();
  Serial.println("Setup complete.");
}

void loop() {
  static unsigned int lastCount = 0;
  unsigned int count = button_get_count();  // Get the current button click count
  static float lastSpeed = 0;
  float currentSpeed = motorL.getCurrentSpeed();  // Get the current motor speed

  // Print the count if it's greater than 0
  if (lastCount != count) {
    Serial.print("btnCount:");
    Serial.println(count);
    lastCount = count;
  }

  if (lastSpeed != currentSpeed) {
    Serial.print("speed:");
    Serial.print(currentSpeed * 100);  // Convert speed to percentage
    Serial.println("%");
    lastSpeed = currentSpeed;
  }

  if (count == 0 || !button_is_pressed()) {
    motorL.setSpeed(0.0);
    motorR.setSpeed(0.0);
  } else if (count == 1) {
    motorL.rampToSpeed(0.15, 0.01);  // Ramp to 15% speed
    motorR.rampToSpeed(0.15, 0.01);  // Ramp to 15% speed
  } else if (count == 2) {
    motorL.rampToSpeed(0.50);  // Ramp to 50% speed
    motorR.rampToSpeed(0.50);  // Ramp to 50% speed
  } else {
    motorL.rampToSpeed(1.0);  // Ramp to 100% speed
    motorR.rampToSpeed(1.0);  // Ramp to 100% speed
  }
  delay(1);
}
