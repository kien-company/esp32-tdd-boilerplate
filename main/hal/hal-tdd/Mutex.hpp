#pragma once

#include "RTOSMutex_HAL.hpp"

#include "gmock/gmock.h"

class Mutex : public Mutex_HAL {
   public:
    MOCK_METHOD1(lock, bool(TickType_t tout));
    MOCK_METHOD0(lock, bool()); // Default tout value

    MOCK_METHOD0(unlock, bool());
};
