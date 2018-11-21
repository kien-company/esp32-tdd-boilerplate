#pragma once

#include "HAL.hpp"

/**
 * Class to access the peripherals in the Hardware Abstraction Layer.
 * It's a singleton, so it must be accessed through getHAL().
 */
class HAL_TDD : public HAL {
   public:
    HAL_TDD();
    void setup() override;
};
