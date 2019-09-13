#pragma once

#include <stdint.h>

/**
 * C++ wrapper for FreeRTOS tasks.
 */
class RTOSTask_HAL {
   public:
    virtual ~RTOSTask_HAL(){};

    /**
     * Start the task.
     *
     * @param pcName A descriptive name for the task.
     *               Max length defined by configMAX_TASK_NAME_LEN.
     * @param usStackDepth The size of the task stack specified as the
     * number of variables the stack can hold - not the number of bytes.
     * @param uxPriority The priority at which the task should run.
     */
    virtual void create(const char* const pcName,
                        const uint32_t usStackDepth,
                        uint32_t uxPriority) = 0;

    /**
     * Delete the task from the scheduler.
     */
    virtual void remove() = 0;

    /**
     * Block the execution of the task for the given period ot time.
     */
    static void inline delay(uint32_t delay_ms);

   protected:
    /**
     * This method has to be overriden to implement the corresponding task.
     */
    virtual void task() = 0;
    static void taskfun(void* param) {
        static_cast<RTOSTask_HAL*>(param)->task();
    }
};
