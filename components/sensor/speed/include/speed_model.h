#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Speed data model. Owns an lv_subject_t so views can bind to it directly
 * (lv_label_bind_text etc.) instead of polling. Backed today by a demo timer;
 * a real sensor/CAN task will call speed_model_set_kph() the same way.
 */
void speed_model_init(void);

void speed_model_set_kph(int32_t kph);
int32_t speed_model_get_kph(void);

lv_subject_t *speed_model_get_subject(void);

#ifdef __cplusplus
}
#endif
