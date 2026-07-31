#include "lvgl_cpu_monitor.h"

#include <string.h>
#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define CPU_MONITOR_MAX_TASKS (40)

typedef struct {
    TaskStatus_t tasks[CPU_MONITOR_MAX_TASKS];
    UBaseType_t task_count;
    uint32_t total_runtime;
    bool valid;
} cpu_monitor_snapshot_t;

static cpu_monitor_snapshot_t s_prev;

static UBaseType_t find_task_by_number(const cpu_monitor_snapshot_t *snapshot, UBaseType_t task_number)
{
    for (UBaseType_t i = 0; i < snapshot->task_count; i++) {
        if (snapshot->tasks[i].xTaskNumber == task_number) {
            return i;
        }
    }
    return snapshot->task_count; // not found
}

static bool is_idle_task(const TaskStatus_t *task)
{
    return strncmp(task->pcTaskName, "IDLE", 4) == 0;
}

// ulTotalRunTime is a single wall-clock counter shared by all cores, so a fully
// idle system accumulates ~total_delta of idle task run time PER core.
static uint32_t idle_percent_from_delta(uint32_t idle_delta, uint32_t total_delta)
{
    uint64_t idle_capacity = (uint64_t)total_delta * configNUMBER_OF_CORES;
    if (idle_capacity == 0) {
        return 100;
    }

    uint32_t idle_percent = (uint32_t)(((uint64_t)idle_delta * 100) / idle_capacity);
    return idle_percent > 100 ? 100 : idle_percent;
}

uint32_t lvgl_cpu_monitor_get_idle_percent(void)
{
    cpu_monitor_snapshot_t current = { 0 };
    current.task_count = uxTaskGetSystemState(current.tasks, CPU_MONITOR_MAX_TASKS, &current.total_runtime);

    if (current.task_count == 0) {
        // uxTaskGetSystemState() returns 0 if CPU_MONITOR_MAX_TASKS was too small to
        // hold every task; skip this sample rather than compute from empty data.
        return 100;
    }

    uint32_t idle_percent = 100;

    if (s_prev.valid && current.total_runtime > s_prev.total_runtime) {
        uint32_t total_delta = current.total_runtime - s_prev.total_runtime;
        uint32_t idle_delta = 0;

        for (UBaseType_t i = 0; i < current.task_count; i++) {
            if (!is_idle_task(&current.tasks[i])) {
                continue;
            }
            UBaseType_t prev_idx = find_task_by_number(&s_prev, current.tasks[i].xTaskNumber);
            if (prev_idx < s_prev.task_count) {
                idle_delta += current.tasks[i].ulRunTimeCounter - s_prev.tasks[prev_idx].ulRunTimeCounter;
            }
        }

        idle_percent = idle_percent_from_delta(idle_delta, total_delta);
    }

    current.valid = true;
    s_prev = current;

    return idle_percent;
}
