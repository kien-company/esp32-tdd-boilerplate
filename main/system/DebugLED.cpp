#include "DebugLED.hpp"

static HAL& hal = getHAL();
static const char LTAG[] = "DLED";

DebugLED::DebugLED() : level(0), blinkPeriod(0) {}

void DebugLED::task() {
    LOGI(LTAG, "Blinking LED every %i ms", this->blinkPeriod);
    for (;;) {
        Task::delay(this->blinkPeriod);
    }
    this->remove();
}

void DebugLED::toggle() {
    hal.gpio->set(DEBUG_LED_PIN, this->level);
    this->level = !this->level;
}

void DebugLED::blinkStart(uint32_t period) {
    this->blinkPeriod = period;
    this->create("debug_led", 2048, 10);
}

void DebugLED::blinkStop() {
    this->remove();
}
