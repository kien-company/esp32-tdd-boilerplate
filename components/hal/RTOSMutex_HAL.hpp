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
 *  + The above copyright notice and this permission notice shall be
 *    included in all copies or substantial portions of the Software.
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

#include "RTOSTypes_HAL.hpp"

/**
 *  Base wrapper class around FreeRTOS's implementation of mutexes.
 *
 *  By definition, Mutexes can @em NOT be used from ISR contexts.
 *
 *  @note It is expected that an application will instantiate one of the
 *        derived classes and use that object for synchronization. It is
 *        not expected that a user or application will derive from these
 *        classes.
 */
class Mutex_HAL {
   public:
    virtual ~Mutex_HAL(){};

    /**
     *  Lock the Mutex.
     *
     *  Each type of Mutex implements it's own locking code as per the
     *  FreeRTOS API.
     *
     *  @param tout How long to wait to get the Lock until giving up.
     *  @return true if the Lock was acquired, false if it timed out.
     */
    virtual bool lock(TickType_t tout = RTOS_MAX_DELAY) = 0;

    /**
     *  Unlock the Mutex.
     *
     *  @return true if the Lock was released, false if it failed. (Hint,
     *           if it fails, did you call Lock() first?)
     */
    virtual bool unlock() = 0;

   protected:
    /**
     *  FreeRTOS semaphore handle.
     */
    MutexHandle_t handle;
};
