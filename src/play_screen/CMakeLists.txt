add_library(PlayScreen player.c play_screen.c ball.c game.c score.c enemy.c)

target_include_directories(PlayScreen PRIVATE ${CMAKE_SOURCE_DIR}/raylib/src)