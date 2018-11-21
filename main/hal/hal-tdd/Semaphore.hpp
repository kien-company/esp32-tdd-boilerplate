#pragma once

#include "RTOSSemaphore_HAL.hpp"

#include "gmock/gmock.h"

class Semaphore : public Semaphore_HAL {
   public:
    MOCK_METHOD1(take, bool(TickType_t Timeout));
    MOCK_METHOD0(give, bool());
    MOCK_METHOD1(takeFromISR, bool(BaseType_t* pxHigherPriorityTaskWoken));
    MOCK_METHOD1(giveFromISR, bool(BaseType_t* pxHigherPriorityTaskWoken));
};

class BinarySemaphore : public Semaphore {};

class CountingSemaphore : public Semaphore {};
