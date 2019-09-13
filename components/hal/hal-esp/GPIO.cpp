#include "GPIO.hpp"
#include "driver/gpio.h"

GPIO_ESP::GPIO_ESP() {
    this->open();
}

void GPIO_ESP::open() {
    gpio_set_direction(DEBUG_LED_PIN, GPIO_MODE_OUTPUT);
}

ePinState GPIO_ESP::get(uint8_t pin) {
    return (gpio_get_level((gpio_num_t)pin) ? ePinHigh : ePinLow);
}

void GPIO_ESP::set(uint8_t pin) {
    gpio_set_level((gpio_num_t)pin, 1);
}

void GPIO_ESP::set(uint8_t pin, uint8_t level) {
    gpio_set_level((gpio_num_t)pin, (uint32_t)level);
}

void GPIO_ESP::clear(uint8_t pin) {
    gpio_set_level((gpio_num_t)pin, 0);
}
