#pragma once

#include <stddef.h>
#include <stdint.h>
#include "System.hpp"

/**
 * I2C driver interface.
 */
class I2C_HAL {
   public:
    /**
     * Initializes a master I2C peripheral at the given frequency..
     *
     * @param freq SCL line frequency.
     */
    virtual void begin(int freq) = 0;

    /**
     * Performs a I2C write operation.
     *
     * @param addr slave address.
     * @param data pointer to the data to be written.
     * @param len number of bytes to be written.
     */
    virtual Result write(uint8_t addr, uint8_t* data, size_t len) = 0;

    /**
     * Performs a I2C read operation.
     *
     * @param addr slave address.
     * @param data pointer to a buffer to save the read data.
     * @param len number of bytes to be read.
     */
    virtual Result read(uint8_t addr, uint8_t* data, size_t len) = 0;
};
