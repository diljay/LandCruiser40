idf_component_register(
    SRCS main.c lvgl_cpu_monitor.c
    INCLUDE_DIRS .)

# lvgl_cpu_monitor_get_idle_percent() is only referenced indirectly, via the
# -DLV_SYSMON_GET_IDLE define below, so nothing in this component's own object
# files pulls its .o out of libmain.a at link time. Force it, the same way
# ESP-IDF force-links app_main itself.
target_link_libraries(${COMPONENT_LIB} INTERFACE "-u lvgl_cpu_monitor_get_idle_percent")

idf_component_get_property(LVGL_LIB lvgl__lvgl COMPONENT_LIB)
target_compile_options(
    ${LVGL_LIB}
    PRIVATE
        -DLV_LVGL_H_INCLUDE_SIMPLE
        # ESP-IDF's FreeRTOS never wires up the traceTASK_SWITCHED_IN/OUT hooks that
        # LV_OS_FREERTOS's default idle tracking needs, so without this override the
        # sysmon performance monitor always reads a stuck 100% CPU. lvgl_cpu_monitor_get_idle_percent()
        # (lvgl_cpu_monitor.c) computes a real idle percentage from FreeRTOS runtime stats instead.
        -DLV_SYSMON_GET_IDLE=lvgl_cpu_monitor_get_idle_percent
)
