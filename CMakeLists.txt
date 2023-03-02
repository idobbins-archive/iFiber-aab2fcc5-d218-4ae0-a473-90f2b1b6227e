
cmake_minimum_required(VERSION 3.23)

project(iFiber LANGUAGES C)

add_subdirectory(atomic)
add_subdirectory(context)
add_subdirectory(stack)

add_executable(${PROJECT_NAME} main.c )

target_link_libraries(${PROJECT_NAME} PRIVATE iAtomic iContext iStack)

#enable_testing()

#add_subdirectory(Tests)
