#include "app_state_machine.h"
#include "view_manager.h"

static app_state_t current_state = APP_STATE_BOOTUP;

void app_sm_init(void)
{
    app_sm_goto(APP_STATE_BOOTUP);
}

void app_sm_goto(app_state_t state)
{
    current_state = state;
    view_manager_show_state(state);
}

app_state_t app_sm_get_state(void)
{
    return current_state;
}
