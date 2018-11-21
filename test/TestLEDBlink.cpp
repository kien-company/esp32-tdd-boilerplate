#include <stdio.h>
#include <string.h>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "hal/hal-tdd/GPIO.hpp"
#include "hal/hal-tdd/HAL_TDD.hpp"
static HAL& hal = getHAL();

#include "system/DebugLED.hpp"

using ::testing::_;
using ::testing::Mock;
using ::testing::Return;

namespace {

GPIO_Mock* m_gpio = static_cast<GPIO_Mock*>(hal.gpio);

class TestLEDBlink : public ::testing::Test {
   protected:
    DebugLED* led;

    virtual void SetUp() {
        led = new DebugLED();
    }

    virtual void TearDown() {
        Mock::VerifyAndClearExpectations(m_gpio);
        Mock::VerifyAndClear(m_gpio);
        Mock::AllowLeak(m_gpio);
        delete led;
    }
};

TEST_F(TestLEDBlink, SaveLEDStatus_when_TogglingLED) {
    EXPECT_CALL(*m_gpio, set(DEBUG_LED_PIN, 0));
    led->toggle();

    EXPECT_CALL(*m_gpio, set(DEBUG_LED_PIN, 1));
    led->toggle();
}

}  // namespace
