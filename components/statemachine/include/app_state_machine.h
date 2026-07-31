#pragma once

#include "view_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Initializes the state machine and enters its first state (APP_STATE_BOOTUP),
 * which triggers view_manager to load the corresponding screen. */
void app_sm_init(void);

void app_sm_goto(app_state_t state);
app_state_t app_sm_get_state(void);

#ifdef __cplusplus
}
#endif
