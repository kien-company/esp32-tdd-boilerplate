#pragma once

#include "I2C_HAL.hpp"
#include "gmock/gmock.h"

class I2C_Mock : public I2C_HAL {
   public:
    MOCK_METHOD1(begin, void(int freq));
    MOCK_METHOD3(write, Result(uint8_t addr, uint8_t* data, size_t len));
    MOCK_METHOD3(read, Result(uint8_t addr, uint8_t* data, size_t len));
};
