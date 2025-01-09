#include "led.h"

static int led_pin;

void led_init(int pin)
{
    led_pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void led_set_on()
{
    digitalWrite(led_pin, HIGH);
}

void led_set_off()
{
    digitalWrite(led_pin, LOW);
}