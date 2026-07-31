#include "lvgl.h"
#include "src/drivers/sdl/lv_sdl_window.h"
#include "src/drivers/sdl/lv_sdl_mouse.h"
#include <SDL2/SDL.h>

#include "app_core.h"

/* Mirrors BSP_LCD_H_RES / BSP_LCD_V_RES from
 * common_components/espressif__esp32_p4_function_ev_board/include/bsp/display.h
 * so the simulator matches the target panel's resolution. */
#define SIM_H_RES 1024
#define SIM_V_RES 600

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    lv_init();
    lv_tick_set_cb(SDL_GetTicks);

    lv_sdl_window_create(SIM_H_RES, SIM_V_RES);
    lv_sdl_mouse_create();

    app_core_init();

    while (1) {
        uint32_t idle_ms = lv_timer_handler();
        SDL_Delay(idle_ms ? idle_ms : 1);
    }

    return 0;
}
