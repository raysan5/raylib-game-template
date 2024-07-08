add_library(IntroScreen intro_screen.c)

target_include_directories(IntroScreen PRIVATE ${CMAKE_SOURCE_DIR}/raylib/src)