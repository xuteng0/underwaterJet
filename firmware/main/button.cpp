// button.cpp
#include "button.h"

// Pin definitions
static int buttonPin;
volatile unsigned int buttonClickCount = 0;
volatile bool buttonState = LOW;
volatile unsigned long lastDebounceTime = 0;

// Debounce and release timeout
const unsigned long debounceDelay = 10;  // Debounce time in milliseconds
const unsigned long releaseTimeout = 500; // Time to clear count in milliseconds

void handleButtonInterrupt();

void button_init(int pin) {
  buttonPin = pin;
  pinMode(buttonPin, INPUT_PULLUP); // Configure button pin as input with pull-up resistor
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonInterrupt, CHANGE);
}

bool button_is_pressed()
{
  return digitalRead(buttonPin) == LOW;
}

unsigned int button_get_count() {
  static unsigned int lastPrintedCount = 0;
  unsigned long currentMillis = millis();

  // Check if the button has been released for more than the timeout
  if (buttonState == HIGH && (currentMillis - lastDebounceTime) > releaseTimeout) {
    buttonClickCount = 0; // Clear the count
  }

  if (buttonClickCount != lastPrintedCount) {
    lastPrintedCount = buttonClickCount;
    return buttonClickCount;
  }

  return lastPrintedCount;
}

void handleButtonInterrupt() {
  unsigned long currentMillis = millis();
  bool currentState = digitalRead(buttonPin);

  // Debounce logic: ignore changes occurring within debounceDelay
  if ((currentMillis - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = currentMillis;

    if (currentState == LOW && buttonState == HIGH) {
      // Button pressed: increment count
      buttonClickCount++;
    }

    buttonState = currentState; // Update button state
  }
}