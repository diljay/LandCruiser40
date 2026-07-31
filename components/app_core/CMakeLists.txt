idf_component_register(
    SRCS
        "src/app_core.c"
    INCLUDE_DIRS "include"
    PRIV_REQUIRES speed statemachine
)
