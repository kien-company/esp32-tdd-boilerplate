#include "BME280.hpp"

#include "HAL.hpp"

static HAL& hal = getHAL();
static const char LTAG[] = "BME280";

uint8_t BME280::id() {
    uint8_t reg[] = {0xD0};
    uint8_t res[1];

    hal.i2c->write(BME280_I2C_ADDR, reg, 1);
    hal.i2c->read(BME280_I2C_ADDR, res, 1);
    return res[0];
}
