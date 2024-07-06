
add_executable(Pong main.c player.c pong.c ball.c game.c score.c)

target_include_directories(Pong PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/raylib/src)

target_link_libraries(Pong raylib)