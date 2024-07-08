#include "raylib.h"
#include "raymath.h"
#include "play_screen/play_screen.h"

typedef enum SCREEN
{
  INTRO_SCREEN,
  PLAY_SCREEN
} SCREEN;

SCREEN currentScreen = PLAY_SCREEN;

// TODO: move everything here to init and update PlayScreen
int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  SetTargetFPS(60);

  initPlayScreen();

  while (!WindowShouldClose())
  {
    switch (currentScreen)
    {
    case INTRO_SCREEN:
      break;
    case PLAY_SCREEN:
      updatePlayScreen();
    }

    // Drawing Logic -----------
    BeginDrawing();
    {
      ClearBackground(BLACK);

      switch (currentScreen)
      {
      case INTRO_SCREEN:
        break;
      case PLAY_SCREEN:
        drawPlayScreen();
        break;
      }
      drawPlayScreen();
    }
    EndDrawing();
    // -------------------------
  }

  CloseWindow();
  return 0;
}
