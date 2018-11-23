#pragma once

#include <stdint.h>

#define BME280_I2C_ADDR 0x76

class BME280 {
   public:
    uint8_t id();
};
