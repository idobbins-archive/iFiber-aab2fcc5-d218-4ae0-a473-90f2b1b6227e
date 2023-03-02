
project(iContext LANGUAGES C ASM)

set(CMAKE_ASM_OPTIONS "-x" "assembler-with-cpp")

add_library(${PROJECT_NAME} STATIC)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(${PROJECT_NAME}
        PRIVATE

        "icontext_load.${CMAKE_HOST_SYSTEM_PROCESSOR}.asm"
        "icontext_save.${CMAKE_HOST_SYSTEM_PROCESSOR}.asm"
        )