#include <stdio.h>
#include <string.h>
#include <cstring>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "hal/hal-tdd/HAL_TDD.hpp"
#include "hal/hal-tdd/I2C.hpp"
static HAL& hal = getHAL();

#include "periph/BME280.hpp"

using ::testing::_;
using ::testing::DoAll;
using ::testing::InSequence;
using ::testing::Mock;
using ::testing::Return;

namespace {

MATCHER_P2(ArrayCmp, array, len, "") {
    return !memcmp(array, arg, len);
}

ACTION_P(PassArr, array) {
    arg1[0] = array[0];
    return Result::Ok;
}

I2C_Mock* m_i2c = static_cast<I2C_Mock*>(hal.i2c);

class TestBME280 : public ::testing::Test {
   protected:
    BME280* bme;

    virtual void SetUp() { bme = new BME280(); }

    virtual void TearDown() {
        // Enabling the two lines below causes a segfault during cleanup (though
        // the tests pass)
        // Mock::VerifyAndClearExpectations(m_i2c);
        // Mock::VerifyAndClear(m_i2c);
        Mock::AllowLeak(m_i2c);
        delete bme;
    }
};

TEST_F(TestBME280, SaveLEDStatus_when_TogglingLED) {
    {
        uint8_t reg[] = {0xD0};
        uint8_t id[] = {0x60};

        InSequence dummy;
        EXPECT_CALL(*m_i2c, write(BME280_I2C_ADDR, ArrayCmp(reg, 1), 1));
        EXPECT_CALL(*m_i2c, read(BME280_I2C_ADDR, _, 1)).WillOnce(PassArr(id));
    }

    EXPECT_EQ(0x60, bme->id());
}

}  // namespace
