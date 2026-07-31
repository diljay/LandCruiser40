#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Single entry point shared by the target (main/main.c) and simulator
 * (sim/sim_main.c). Call once after lv_init()/display setup and while
 * holding the LVGL lock, if the port uses one. */
void app_core_init(void);

#ifdef __cplusplus
}
#endif
