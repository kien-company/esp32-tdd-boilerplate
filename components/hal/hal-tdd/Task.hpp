#pragma once

#include "RTOSTask_HAL.hpp"
#include "gmock/gmock.h"

/**
 * C++ wrapper for FreeRTOS tasks.
 */
class Task : public RTOSTask_HAL {
   public:
    MOCK_METHOD3(create,
                 void(const char* const pcName,
                      const uint32_t usStackDepth,
                      uint32_t uxPriority));

    MOCK_METHOD0(remove, void());
    static inline void delay(uint32_t delay_ms){};
};
