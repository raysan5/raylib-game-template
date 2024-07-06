#include "raylib.h"
#include "raymath.h"
#include "pong.h"

Player p1;
Player p2;
Ball b;
Score s;

int main()
{
  GetRandomValue(2, 3);
  initGame(&p1, &p2, &b, &s);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    // Quick Reset Logic --------
    if (IsKeyPressed(KEY_SPACE))
    {
      initBall(&b);
    }
    // ------------------------

    // P2 AI Logic --------------
    p2.rect.y = b.rect.y - p2.rect.height / 2;
    // -----------------------

    // Ball Collision Logic -----
    if (CheckPlayerScored(&p1, &b))
    {
      resetRound(&p1, &p2, &b);
      s.p1Score++;
    }
    else if (CheckPlayerScored(&p2, &b))
    {
      resetRound(&p1, &p2, &b);
      s.p2Score++;
    }
    else if (CheckCollisionRecs(b.rect, p1.rect))
      bounceBall(&b, &p1);
    else if (CheckCollisionRecs(b.rect, p2.rect))
      bounceBall(&b, &p2);
    // -------------------------

    // Update Logic -----------
    if (CheckRoundResetting())
      updateReset();
    else
    {
      updatePlayer(&p1);
      updateBall(&b);
    }
    updateScoreText(&s);
    // ------------------------

    // Drawing Logic -----------
    BeginDrawing();
    {
      ClearBackground(BLACK);

      drawPlayer(&p1);
      drawPlayer(&p2);
      drawScore(&s);
      drawBall(&b);

      if (CheckRoundResetting())
        drawResetRoundCounter();
    }
    EndDrawing();
    // -------------------------
  }

  CloseWindow();
  return 0;
}
