#pragma once

#include "RTOSQueue_HAL.hpp"

#include "gmock/gmock.h"

template <class T>
class Queue : public Queue_HAL<T> {
   public:
    Queue(uint32_t queueLenght){};
    MOCK_CONST_METHOD0_T(waiting, unsigned());
    MOCK_CONST_METHOD0_T(available, unsigned());

    MOCK_METHOD0_T(reset, void());
    MOCK_METHOD0_T(full_ISR, bool());
    MOCK_METHOD0_T(empty_ISR, bool());
    MOCK_METHOD0_T(waiting_ISR, unsigned());

    MOCK_METHOD2_T(push, bool(T const& item, TickType_t time));
    MOCK_METHOD1_T(push, bool(T const& item));
    MOCK_METHOD2_T(add, bool(T const& item, TickType_t time));
    MOCK_METHOD1_T(add, bool(T const& item));
    MOCK_METHOD2_T(pop, bool(T& var, TickType_t time));
    MOCK_METHOD1_T(pop, bool(T& var));
    MOCK_METHOD2_T(peek, bool(T& var, TickType_t time));
    MOCK_METHOD1_T(peek, bool(T& var));

    MOCK_METHOD2_T(push_ISR, bool(T const& item, int& waswoken));
    MOCK_METHOD2_T(add_ISR, bool(T const& item, int& waswoken));
    MOCK_METHOD2_T(pop_ISR, bool(T& var, int& waswoken));
    MOCK_METHOD2_T(peek_ISR, bool(T& var, int& waswoken));
};
