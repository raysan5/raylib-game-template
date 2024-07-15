#include "raylib.h"
#include "raymath.h"
#include "driver.h"

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  SetTargetFPS(60);

  initScreen();

  while (!WindowShouldClose())
  {

    // Updating Logic ---------
    updateScreen();
    // ------------------------

    // Switching Screens Logic
    // TODO: create a check in every screen to see whether its done or not
    //  or atleast just the intro screenk
    /**
     * we check if the intro screen is done
     * if the intro screen is done
     *  we set the next screen
     *  we begin fading to black
     *  once we are completely black we switch screens
     *  we init the next screen
     *  and we begin unfading
     *  we set isScreenTransitioning to false
     * if the screen is not done we continue as normal
     */

    // ------------------------

    // Drawing Logic -----------
    BeginDrawing();
    {
      DrawFPS(0, 0);
      drawScreen();
    }
    EndDrawing();
    // -------------------------
  }

  CloseWindow();
  return 0;
}
