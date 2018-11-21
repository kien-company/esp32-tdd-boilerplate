#include "GPIO_HAL.hpp"
#include "gmock/gmock.h"

class GPIO_Mock : public GPIO_HAL {
   public:
    MOCK_METHOD0(open, void(void));
    MOCK_METHOD1(get, ePinState(uint8_t pin));
    MOCK_METHOD1(set, void(uint8_t pin));
    MOCK_METHOD2(set, void(uint8_t pin, uint8_t level));
    MOCK_METHOD1(clear, void(uint8_t pin));
};
