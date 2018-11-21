#pragma once

#include <stdint.h>
#include "pins.h"
#include "GPIO_HAL.hpp"

/**
 * GPIO driver for ESP32.
 */
class GPIO_ESP : public GPIO_HAL {
   public:
    GPIO_ESP();

    void open() override;
    ePinState get(uint8_t pin) override;
    void set(uint8_t pin) override;
    void set(uint8_t pin, uint8_t level) override;
    void clear(uint8_t pin) override;
};
