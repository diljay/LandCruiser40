#include "screen_bootup.h"
#include "speed_model.h"

lv_obj_t *screen_bootup_create(void)
{
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);

    lv_obj_t *label = lv_label_create(screen);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_48, 0);
    lv_label_bind_text(label, speed_model_get_subject(), "%d km/h");
    lv_obj_center(label);

    return screen;
}
