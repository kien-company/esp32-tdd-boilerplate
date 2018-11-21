#include "HAL_TDD.hpp"
#include "GPIO.hpp"

static GPIO_Mock gpioDriver;

HAL_TDD::HAL_TDD() : HAL(&gpioDriver){};

void HAL_TDD::setup() {}

HAL& getHAL() {
    static HAL_TDD hal;
    return hal;
}
