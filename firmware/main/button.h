// button.h
#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

void button_init(int pin);
bool button_is_pressed();
unsigned int button_get_count();

#endif // BUTTON_H