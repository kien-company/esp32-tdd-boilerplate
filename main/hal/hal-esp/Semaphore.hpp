#pragma once
#include "RTOSSemaphore_HAL.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

class Semaphore : public Semaphore_HAL {
   public:
    bool take(TickType_t timeout = RTOS_MAX_DELAY) override {
        return xSemaphoreTake(this->handle, timeout);
    };
    bool give() override { return xSemaphoreGive(this->handle); };
    bool takeFromISR(BaseType_t* pxHigherPriorityTaskWoken) override {
        return xSemaphoreTakeFromISR(this->handle, pxHigherPriorityTaskWoken);
    };
    bool giveFromISR(BaseType_t* pxHigherPriorityTaskWoken) override {
        return xSemaphoreGiveFromISR(this->handle, pxHigherPriorityTaskWoken);
    };

    ~Semaphore() { vSemaphoreDelete(this->handle); };
};

class BinarySemaphore : public Semaphore {
   public:
    /**
     *  Constructor to create a binary semaphore.
     *
     *  @param set Is this semaphore "full" or not?
     *  @return Instance of a BinarySemaphore.
     */
    BinarySemaphore(bool set = false) {
        this->handle = xSemaphoreCreateBinary();

        if (this->handle == NULL) {
            configASSERT(!"BinarySemaphore Constructor Failed");
        }

        if (set) {
            xSemaphoreGive(handle);
        }
    };
};

class CountingSemaphore : public Semaphore {
   public:
    /**
     *  Constructor to create a counting semaphore.
     *
     *  @param maxCount Must be greater than 0.
     *  @param initialCount Must not be greater than maxCount.
     *  @return Instance of a CountingSemaphore.
     */
    CountingSemaphore(BaseType_t maxCount, BaseType_t initialCount) {
        if (maxCount == 0) {
            configASSERT(!"CountingSemaphore Constructor bad maxCount");
        }

        if (initialCount > maxCount) {
            configASSERT(!"CountingSemaphore Constructor bad initialCount");
        }

        this->handle = xSemaphoreCreateCounting(maxCount, initialCount);

        if (this->handle == NULL) {
            configASSERT(!"CountingSemaphore Constructor Failed");
        }
    };
};
