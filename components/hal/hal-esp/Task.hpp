#pragma once

#include "RTOSTask_HAL.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * C++ wrapper for FreeRTOS tasks.
 */
class Task : public RTOSTask_HAL {
   public:
    xTaskHandle handle;
    ~Task() {
        vTaskDelete(handle);
        return;
    }

    void create(const char* const pcName,
                const uint32_t usStackDepth,
                uint32_t uxPriority) override {
        xTaskCreate(&taskfun, pcName, usStackDepth, this,
                    (UBaseType_t)uxPriority, &handle);
    };

    void remove() override { vTaskDelete(handle); };

    static void inline delay(uint32_t delay_ms) { vTaskDelay(delay_ms / portTICK_PERIOD_MS); };
};
