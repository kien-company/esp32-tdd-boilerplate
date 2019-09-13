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

#include <cstdio>
#include <exception>
#include <string>

#include "RTOSTypes_HAL.hpp"

/**
 *  Base wrapper class around FreeRTOS's implementation of semaphores.
 *
 *  We do not want a Semaphore ctor. This class should never be directly
 *  created, this is a base class only.
 *
 *  It is not expected that an application will derive from this class.
 *
 *  Note that we distinguish between Semaphore, Binary Semaphores,
 *  Counting Semaphores, and Mutexes. Mutexes, while implemented as a kind
 *  of semaphore in FreeRTOS, are conceptually very different in use and
 *  behavior from semaphores. We acknowledge this difference in the class
 *  heirarchy, implementing mutextes as a completely different class heirarchy.
 */
class Semaphore_HAL {
    /////////////////////////////////////////////////////////////////////////
    //
    //  Public API
    //
    /////////////////////////////////////////////////////////////////////////
   public:
    /**
     *  Aquire (take) a semaphore.
     *
     *  Example of blocking indefinitely:
     *      aSemaphore.take();
     *
     *  Example of blocking for 100 ticks:
     *      aSemaphore.take(100);
     *
     *  @param timeout How long to wait to get the Lock until giving up.
     *  @return true if the Semaphore was acquired, false if it timed out.
     */
    virtual bool take(TickType_t timeout = RTOS_MAX_DELAY) = 0;

    /**
     *  Release (give) a semaphore.
     *
     *  @return true if the Semaphore was released, false if it failed.
     */
    virtual bool give() = 0;

    /**
     *  Aquire (take) a semaphore from ISR context.
     *
     *  @param pxHigherPriorityTaskWoken Did this operation result in a
     *         rescheduling event.
     *  @return true if the Semaphore was acquired, false if it timed out.
     */
    virtual bool takeFromISR(BaseType_t* pxHigherPriorityTaskWoken) = 0;

    /**
     *  Release (give) a semaphore from ISR context.
     *
     *  @param pxHigherPriorityTaskWoken Did this operation result in a
     *         rescheduling event.
     *  @return true if the Semaphore was released, false if it failed.
     */
    virtual bool giveFromISR(BaseType_t* pxHigherPriorityTaskWoken) = 0;

    /**
     *  Our destructor
     */
    virtual ~Semaphore_HAL(){};

    /////////////////////////////////////////////////////////////////////////
    //
    //  Protected API
    //  Not intended for use by application code.
    //
    /////////////////////////////////////////////////////////////////////////
   protected:
    /**
     *  FreeRTOS semaphore handle.
     */
    SemaphoreHandle_t handle;
};

/**
 *  Wrapper class for Binary Semaphores.
 */
class BinarySemaphore_HAL : public Semaphore_HAL {};

/**
 *  Wrapper class for Counting Semaphores.
 */
class CountingSemaphore_HAL : public Semaphore_HAL {};
