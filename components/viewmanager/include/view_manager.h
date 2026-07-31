#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    APP_STATE_BOOTUP = 0,
    APP_STATE_MAIN,
    APP_STATE_COUNT
} app_state_t;

/* Loads (and creates on first use) the lv_obj_t screen for the given app
 * state and makes it active. Called by the controller on every transition. */
void view_manager_show_state(app_state_t state);

#ifdef __cplusplus
}
#endif
