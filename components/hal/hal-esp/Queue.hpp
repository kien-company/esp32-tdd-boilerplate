#pragma once
#include "RTOSQueue_HAL.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

template <class T>
class Queue : public Queue_HAL<T> {
   public:
    Queue(uint32_t queueLength) { this->handle = xQueueCreate(queueLength, sizeof(T)); }
    ~Queue() { vQueueDelete(this->handle); }
    unsigned waiting() const override { return uxQueueMessagesWaiting(this->handle); }
    unsigned available() const override { return uxQueueSpacesAvailable(this->handle); }
    void reset() override { xQueueReset(this->handle); }
    bool full_ISR() override { return xQueueIsQueueFullFromISR(this->handle); }
    bool empty_ISR() override { return xQueueIsQueueEmptyFromISR(this->handle); }
    unsigned waiting_ISR() override { return uxQueueMessagesWaitingFromISR(this->handle); }
    bool push(T const& item, TickType_t time = 0) {
        return xQueueSendToFront(this->handle, &item, time);
    }
    bool add(T const& item, TickType_t time = 0) override {
        return xQueueSendToBack(this->handle, &item, time);
    }
    bool pop(T& var, TickType_t time = 0) override {
        return xQueueReceive(this->handle, &var, time);
    }
    bool peek(T& var, TickType_t time = 0) override {
        return xQueuePeek(this->handle, &var, time);
    }
    bool push_ISR(T const& item, portBASE_TYPE& waswoken) override {
        return xQueueSendToFrontFromISR(this->handle, &item, &waswoken);
    }
    bool add_ISR(T const& item, portBASE_TYPE& waswoken) override {
        return xQueueSendToBackFromISR(this->handle, &item, &waswoken);
    }
    bool pop_ISR(T& var, portBASE_TYPE& waswoken) override {
        return xQueueReceiveFromISR(this->handle, &var, &waswoken);
    }
    bool peek_ISR(T& var, portBASE_TYPE& waswoken) override {
        return xQueuePeekFromISR(this->handle, &var);
    }
};
