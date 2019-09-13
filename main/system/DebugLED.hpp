#pragma once

#include "HAL.hpp"

/**
 * This is a debugging class which can be used to blink the onboard LED.
 */
class DebugLED : public Task {
   public:
    DebugLED();

    void toggle();

    /**
     * Start blinking the LED at the given period.
     */
    void blinkStart(uint32_t period);

    /**
     * Stop blinking the LED.
     */
    void blinkStop();

   private:
    uint8_t level;
    uint32_t blinkPeriod;
    void task() override;
};
