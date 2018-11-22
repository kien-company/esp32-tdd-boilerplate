#pragma once

#include "GPIO_HAL.hpp"
#include "I2C_HAL.hpp"
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
    HAL(GPIO_HAL* _gpio) : gpio(_gpio){};
    GPIO_HAL* gpio;

    /**
     * Initializes the peripherals.
     */
    virtual void setup() = 0;
};

// Must be implemented by the concrete HALs.
HAL& getHAL();
