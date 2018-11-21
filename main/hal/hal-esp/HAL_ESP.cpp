#include "HAL_ESP.hpp"
#include "GPIO.hpp"

static GPIO_ESP gpioDriver;

HAL_ESP::HAL_ESP() : HAL(&gpioDriver){};

void HAL_ESP::setup() {}

HAL& getHAL() {
    static HAL_ESP hal;
    return hal;
}
