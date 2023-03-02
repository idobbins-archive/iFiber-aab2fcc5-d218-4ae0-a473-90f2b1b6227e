
project(iStack LANGUAGES C)

add_library(${PROJECT_NAME} STATIC)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(${PROJECT_NAME}
        PRIVATE

        "istack.c"
        )