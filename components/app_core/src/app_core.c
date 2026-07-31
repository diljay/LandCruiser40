#include "app_core.h"
#include "speed_model.h"
#include "app_state_machine.h"

void app_core_init(void)
{
    speed_model_init();
    app_sm_init();
}
