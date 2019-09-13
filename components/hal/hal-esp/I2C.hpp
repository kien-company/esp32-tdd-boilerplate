#pragma once

#include "I2C_HAL.hpp"

/**
 * I2C driver for ESP32.
 */
class I2C_ESP : public I2C_HAL {
   public:
    void begin(int freq) override;
    Result write(uint8_t addr, uint8_t* data, size_t len) override;
    Result read(uint8_t addr, uint8_t* data, size_t len) override;

   private:
    int port;
};
