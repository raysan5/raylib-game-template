add_executable(Pong main.c)

add_subdirectory(intro_screen)
target_link_libraries(Pong IntroScreen)

add_subdirectory(play_screen)
target_link_libraries(Pong PlayScreen)

target_include_directories(Pong PRIVATE ${CMAKE_SOURCE_DIR}/raylib/src)

target_link_libraries(Pong raylib)