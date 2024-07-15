add_executable(Pong main.c)
add_library(Driver driver.c)

add_subdirectory(intro_screen)
add_subdirectory(play_screen)


target_include_directories(Driver PRIVATE ${CMAKE_SOURCE_DIR}/raylib/src)
target_link_libraries(Driver IntroScreen PlayScreen)



target_include_directories(Pong PRIVATE ${CMAKE_SOURCE_DIR}/raylib/src)
target_link_libraries(Pong Driver)
target_link_libraries(Pong raylib)