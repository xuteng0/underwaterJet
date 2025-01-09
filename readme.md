# Project: Arduino-Based Button, LED, and Motor Control

This project demonstrates how to control an LED and a motor using a button interface. The system uses modular C++ code to initialize and control these components effectively.

## Features

- **Button Control**: Detect button presses, debounce the input, and track the number of presses.
- **LED Control**: Turn the LED on or off based on button interactions.
- **Motor Control**: Set motor speed directly or ramp up/down to a target speed gradually.

## File Overview

### 1. Button Control

- **Files**: `button.cpp`, `button.h`
- **Description**:
  - Initializes a button with a hardware interrupt.
  - Provides functions to check if the button is pressed and to get the number of presses.
  - Implements debounce logic to ensure accurate press detection.

### 2. LED Control

- **Files**: `led.cpp`, `led.h`
- **Description**:
  - Provides functions to initialize and control an LED.
  - Supports turning the LED on or off.

### 3. Motor Control

- **Files**: `motor.cpp`, `motor.h`
- **Description**:
  - Controls a motor using a servo interface.
  - Supports setting the motor speed directly or gradually ramping to a target speed.
  - Configurable speed increment for smooth operation.

### 4. Main Program

- **File**: `main.ino`
- **Description**:
  - Integrates button, LED, and motor control.
  - Uses button presses to toggle the LED and adjust the motor speed dynamically.

## Dependencies

- **Arduino Framework**: The code relies on Arduino functions such as `pinMode`, `digitalRead`, and `millis`.
- **Servo Library**: The motor control functionality uses the Arduino Servo library.

## Setup

1. **Hardware Connections**:
   - Connect a push button to the configured pin with a pull-up resistor.
   - Attach an LED to the specified output pin with an appropriate resistor.
   - Connect a servo motor to the designated motor control pin.
2. **Software Configuration**:
   - Modify the pin numbers and speed increment values in the code as required.
   - Upload the `main.ino` file to your Arduino board.

## Usage

1. Press the button to:
   - Toggle the LED.
   - Increment the motor speed (if configured in the main program).
2. Observe the LED and motor behavior as controlled by the button.

## Code Highlights

### Button Example
```cpp
button_init(2); // Initialize button on pin 2
if (button_is_pressed()) {
    Serial.println("Button Pressed!");
}
```

### LED Example
```cpp
led_init(13); // Initialize LED on pin 13
led_set_on(); // Turn LED on
led_set_off(); // Turn LED off
```

### Motor Example
```cpp
motor_init(9, 5); // Initialize motor on pin 9 with increment step 5
motor_ramp_to_speed(50); // Gradually ramp to 50% speed
```

## Future Enhancements

- Add additional sensors for more interactive functionality.
- Implement feedback mechanisms for the motor to ensure precise control.
- Extend the project to support multiple buttons and LEDs.

## License

This project is open-source. Feel free to use and modify it for personal or educational purposes.

