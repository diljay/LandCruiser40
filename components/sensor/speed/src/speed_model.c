#include "speed_model.h"

#define SPEED_DEMO_STEP_KPH   5
#define SPEED_DEMO_MAX_KPH    220
#define SPEED_DEMO_PERIOD_MS  100

static lv_subject_t speed_subject;
static lv_timer_t *demo_timer;

static void demo_timer_cb(lv_timer_t *timer)
{
    LV_UNUSED(timer);
    int32_t next = speed_model_get_kph() + SPEED_DEMO_STEP_KPH;
    if (next > SPEED_DEMO_MAX_KPH) {
        next = 0;
    }
    speed_model_set_kph(next);
}

void speed_model_init(void)
{
    lv_subject_init_int(&speed_subject, 0);

    /* Stand-in for a real sensor/CAN task, which would call
     * speed_model_set_kph() from its own task/thread instead. */
    demo_timer = lv_timer_create(demo_timer_cb, SPEED_DEMO_PERIOD_MS, NULL);
}

void speed_model_set_kph(int32_t kph)
{
    lv_subject_set_int(&speed_subject, kph);
}

int32_t speed_model_get_kph(void)
{
    return lv_subject_get_int(&speed_subject);
}

lv_subject_t *speed_model_get_subject(void)
{
    return &speed_subject;
}
