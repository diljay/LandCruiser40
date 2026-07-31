idf_component_register(
    SRCS
        "src/view_manager.c"
        "src/screen_bootup.c"
    INCLUDE_DIRS "include"
    REQUIRES lvgl
    PRIV_REQUIRES speed
)
