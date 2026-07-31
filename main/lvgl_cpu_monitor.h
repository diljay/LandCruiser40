#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Real per-core idle percentage, for LVGL's sysmon performance monitor overlay.
 *
 * ESP-IDF's FreeRTOS never wires up the traceTASK_SWITCHED_IN/OUT hooks that LVGL's
 * default LV_OS_FREERTOS idle tracking relies on, so without this the overlay always
 * reports a stuck 0% idle / 100% CPU regardless of real load. This computes a real
 * value instead, from the FreeRTOS runtime stats ESP-IDF already tracks
 * (CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS / CONFIG_FREERTOS_USE_TRACE_FACILITY).
 *
 * Wired in as LV_SYSMON_GET_IDLE via a compile define on the lvgl__lvgl component in
 * main/CMakeLists.txt - not called directly anywhere in this project.
 */
uint32_t lvgl_cpu_monitor_get_idle_percent(void);

#ifdef __cplusplus
}
#endif
