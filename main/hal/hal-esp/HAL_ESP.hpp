#pragma once

#include "HAL.hpp"

/**
 * Class to access the peripherals in the Hardware Abstraction Layer.
 * The application shall keep a single instance of this class. To do so,
 * it must be accessed through getHAL().
 */
class HAL_ESP : public HAL {
   public:
    HAL_ESP();
    void setup() override;
};
