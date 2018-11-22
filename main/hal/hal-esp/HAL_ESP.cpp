#include "HAL_ESP.hpp"
#include "GPIO.hpp"
#include "I2C.hpp"

static GPIO_ESP gpioDriver;
static I2C_ESP i2cDriver;

HAL_ESP::HAL_ESP() : HAL(&gpioDriver, &i2cDriver){};

void HAL_ESP::setup() {
    i2cDriver.begin(100000);
}

HAL& getHAL() {
    static HAL_ESP hal;
    return hal;
}
