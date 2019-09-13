/****************************************************************************
 *
 *  Copyright (c) 2017, Michael Becker (michael.f.becker@gmail.com)
 *  Modifications Copyright (c) 2018, OUBORG & GATIN B.V. (Netherlands)
 *
 *  This file is part of the FreeRTOS Add-ons project.
 *
 *  Source Code:
 *  https://github.com/michaelbecker/freertos-addons
 *
 *  Project Page:
 *  http://michaelbecker.github.io/freertos-addons/
 *
 *  On-line Documentation:
 *  http://michaelbecker.github.io/freertos-addons/docs/html/index.html
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files
 *  (the "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so,subject to the
 *  following conditions:
 *
 *  + The above copyright notice and this permission notice shall be included
 *    in all copies or substantial portions of the Software.
 *  + Credit is appreciated, but not required, if you find this project
 *    useful enough to include in your application, product, device, etc.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 *  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ***************************************************************************/
#pragma once

#include <stdint.h>
#include "RTOSTypes_HAL.hpp"

template <class T>
class Queue_HAL {
   public:
    virtual ~Queue_HAL(){};

    /**
     * @brief Get number of items in the Queue.
     * @return The number of item in the Queue.
     */
    virtual unsigned waiting() const = 0;

    /**
     * @brief Return number of spaces available in Queue
     * @return the number of spaces available in the Queue.
     */
    virtual unsigned available() const = 0;

    /**
     * @brief Reset the Queue.
     * Resets the Queue to an empty state.
     */
    virtual void reset() = 0;

    /**
     * @brief Is Queue Full.
     * Note: Interrupt service routines should only call _ISR routines.
     * @return True if Queue is Full.
     */
    virtual bool full_ISR() = 0;

    /**
     * @brief Is Queue Empty.
     * Note: Interrupt service routines should only call _ISR routines.
     * @return True if Queue is Empty.
     */
    virtual bool empty_ISR() = 0;

    /**
     * @brief Get number of message waiting.
     * Note: Interrupt service routines should only call _ISR routines.
     * @return The number of messages waiting.
     */
    virtual unsigned waiting_ISR() = 0;

    /**
     * @brief Push an item onto the Queue.
     * Puts an item onto the Queue so it will be the next item to remove.
     * @param item The item to put on the Queue.
     * @param time How long to wait for room if Queue is full.
     * @return True if successful
     */
    virtual bool push(T const& item, TickType_t time = 0) = 0;

    /**
     * @brief add an item at end of the Queue.
     * Puts an item onto the Queue so it will be the last item to remove.
     * @param item The item to put on the Queue.
     * @param time How long to wait for room if Queue is full.
     * @return True if successful
     */
    virtual bool add(T const& item, TickType_t time = 0) = 0;

    /**
     * @brief Get an item from the Queue.
     * Gets the first item from the Queue
     * @param var Variable to place the item
     * @param time How long to wait for an item to be available.
     * @return True if an item returned.
     */
    virtual bool pop(T& var, TickType_t time = 0) = 0;

    /**
     * @brief Look at the first item in the Queue.
     * Gets the first item from the Queue leaving it there.
     * @param var Variable to place the item
     * @param time How long to wait for an item to be available.
     * @return True if an item returned.
     */
    virtual bool peek(T& var, TickType_t time = 0) = 0;

    /**
     * @brief Push an item onto the Queue.
     * Puts an item onto the Queue so it will be the next item to remove.
     *
     * Note: Interrupt service routines should only call _ISR routines.
     * @param item The item to put on the Queue.
     * @param waswoken Flag variable to determine if context switch is needed.
     * @return True if successful
     */
    virtual bool push_ISR(T const& item, int& waswoken) = 0;

    /**
     * @brief add an item at end of the Queue.
     * Puts an item onto the Queue so it will be the last item to remove.
     *
     * Note: Interrupt service routines should only call _ISR routines.
     * @param item The item to put on the Queue.
     * @param waswoken Flag variable to determine if context switch is needed.
     * @return True if successful
     */
    virtual bool add_ISR(T const& item, int& waswoken) = 0;

    /**
     * @brief Get an item from the Queue.
     * Gets the first item from the Queue
     *
     * Note: Interrupt service routines should only call _ISR routines.
     * @param var Variable to place the item
     * @param waswoken Flag variable to determine if context switch is needed.
     * @return True if an item returned.
     */
    virtual bool pop_ISR(T& var, int& waswoken) = 0;

    /**
     * @brief Look at the first item in the Queue.
     * Gets the first item from the Queue leaving it there.
     *
     * Note: Interrupt service routines should only call _ISR routines.
     * @param var Variable to place the item
     * @param waswoken Flag variable to determine if context switch is needed.
     * @return True if an item returned.
     */
    virtual bool peek_ISR(T& var, int& waswoken) = 0;

    /**
     * Pointer to the queue. Public visibility to enable using it from C.
     */
    QueueHandle_t handle;
};
