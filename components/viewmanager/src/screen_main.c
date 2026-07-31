#include "screen_main.h"

lv_obj_t *screen_main_create(void)
{
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_white(), 0);
    return screen;
}
