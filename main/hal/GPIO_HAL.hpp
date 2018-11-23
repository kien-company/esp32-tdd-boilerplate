#pragma once

#include <stdint.h>

typedef enum { ePinLow = 0, ePinHigh = 1 } ePinState;

/**
 * GPIO driver interface.
 */
class GPIO_HAL {
   public:
    ~GPIO_HAL(){};

    /**
     * Defines GPIO configuration (directions...).
     */
    virtual void open() = 0;

    /**
     * Gets a pin level
     *
     * @param pin id of pin to modify.
     * @return The state of the pin
     */
    virtual ePinState get(uint8_t pin) = 0;

    /**
     * Sets pin HIGH.
     *
     * @param pin id of pin to modify.
     */
    virtual void set(uint8_t pin) = 0;

    /**
     * Sets the pin level.
     *
     * @param pin id of pin to modify.
     * @param level value to set (1/0).
     */
    virtual void set(uint8_t pin, uint8_t level) = 0;

    /**
     * Sets pin LOW.
     *
     * @param pin id of pin to modify.
     */
    virtual void clear(uint8_t pin) = 0;
};
