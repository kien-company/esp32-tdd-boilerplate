#include "RTOSMutex_HAL.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

class Mutex : public Mutex_HAL {
   public:
    Mutex() { this->handle = xSemaphoreCreateMutex(); }
    ~Mutex() { vSemaphoreDelete(this->handle); }
    bool lock(TickType_t tout = portMAX_DELAY) override {
        BaseType_t success = xSemaphoreTake(this->handle, tout);
        return success == pdTRUE ? true : false;
    }
    bool unlock() override {
        BaseType_t success = xSemaphoreGive(this->handle);
        return success == pdTRUE ? true : false;
    }
};
