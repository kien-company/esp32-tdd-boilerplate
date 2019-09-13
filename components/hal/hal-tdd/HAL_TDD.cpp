#include "HAL_TDD.hpp"
#include "GPIO.hpp"
#include "I2C.hpp"

static GPIO_Mock gpioDriver;
static I2C_Mock i2cDriver;

HAL_TDD::HAL_TDD() : HAL(&gpioDriver, &i2cDriver){};

void HAL_TDD::setup() {}

HAL& getHAL() {
    static HAL_TDD hal;
    return hal;
}
