#pragma once

// Run-time substitution
#include "GPIO_HAL.hpp"
#include "I2C_HAL.hpp"

// Link-time substitution
#include "LOGS.h"
#include "Mutex.hpp"
#include "Queue.hpp"
#include "Semaphore.hpp"
#include "System.hpp"
#include "Task.hpp"
#include "pins.h"

/**
 * Class to access the peripherals in the Hardware Abstraction Layer.
 * It's a singleton, so it must be accessed through getHAL().
 */
class HAL {
   public:
    HAL(GPIO_HAL* _gpio, I2C_HAL* _i2c) : gpio(_gpio), i2c(_i2c){};
    GPIO_HAL* gpio;
    I2C_HAL* i2c;

    /**
     * Initializes the peripherals.
     */
    virtual void setup() = 0;
};

// Must be implemented by the concrete HALs.
HAL& getHAL();
