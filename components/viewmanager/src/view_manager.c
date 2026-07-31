#include "view_manager.h"
#include "screen_bootup.h"

static lv_obj_t *screens[APP_STATE_COUNT];

void view_manager_show_state(app_state_t state)
{
    if (!screens[state]) {
        switch (state) {
            case APP_STATE_BOOTUP:
                screens[state] = screen_bootup_create();
                break;
            default:
                return;
        }
    }

    lv_screen_load(screens[state]);
}
