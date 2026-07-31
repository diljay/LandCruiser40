cmake_minimum_required(VERSION 3.16)
project(landcruiser_sim C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# lv_conf.h lives next to this file; LVGL's own CMakeLists.txt auto-detects
# it there when no LV_BUILD_CONF_PATH/DIR override is given.
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

list(APPEND CMAKE_PREFIX_PATH /opt/homebrew)
find_package(SDL2 REQUIRED)

include(FetchContent)
FetchContent_Declare(
    lvgl
    GIT_REPOSITORY https://github.com/lvgl/lvgl.git
    GIT_TAG v9.5.0
)
FetchContent_MakeAvailable(lvgl)

# The SDL driver sources live inside LVGL's own "lvgl" target (LV_USE_SDL=1
# in lv_conf.h), so that target needs SDL2's headers to compile, not just
# the final executable that links against it.
target_include_directories(lvgl PUBLIC ${SDL2_INCLUDE_DIRS})

set(COMPONENTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../components)
set(APP_CORE_DIR ${COMPONENTS_DIR}/app_core)
set(SPEED_DIR ${COMPONENTS_DIR}/sensor/speed)
set(STATEMACHINE_DIR ${COMPONENTS_DIR}/statemachine)
set(VIEWMANAGER_DIR ${COMPONENTS_DIR}/viewmanager)

add_executable(landcruiser_sim
    sim_main.c
    ${APP_CORE_DIR}/src/app_core.c
    ${SPEED_DIR}/src/speed_model.c
    ${STATEMACHINE_DIR}/src/app_state_machine.c
    ${VIEWMANAGER_DIR}/src/view_manager.c
    ${VIEWMANAGER_DIR}/src/screen_bootup.c
)

target_include_directories(landcruiser_sim PRIVATE
    ${APP_CORE_DIR}/include
    ${SPEED_DIR}/include
    ${STATEMACHINE_DIR}/include
    ${VIEWMANAGER_DIR}/include
)
target_link_libraries(landcruiser_sim PRIVATE lvgl::lvgl SDL2::SDL2)
