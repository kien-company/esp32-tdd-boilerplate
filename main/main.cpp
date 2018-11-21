#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "system/DebugLED.hpp"

#include "hal/hal-esp/HAL_ESP.hpp"

static HAL& hal = getHAL();

extern "C" void app_main() {
    hal.setup();

    DebugLED led;
    led.blinkStart(500);

    while (true) {
    }
}
