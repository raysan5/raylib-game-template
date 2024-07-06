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
  initPlayer(&p1, PLAYER_ONE);
  initPlayer(&p2, PLAYER_TWO);
  initBall(&b);
  initScore(&s);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    // Resetting Logic --------
    if (IsKeyPressed(KEY_SPACE))
    {
      initBall(&b);
    }
    // ------------------------

    // Update Logic -----------
    updatePlayer(&p1);
    updateBall(&b);
    // ------------------------

    // P2 AI Logic --------------
    p2.rect.y = b.rect.y - p2.rect.height / 2;
    // -----------------------

    // TODO: Scoring Logic ------
    // after the ball passes one of the 2 sides update the score
    // then start a cooldown for the next round
    // reset the positions of the players
    // --------------------------

    // Ball Bouncing Logic -----
    // TODO: FIXME: the ball is bouncing after hitting the top of player, stop that plz.
    if (CheckCollisionRecs(b.rect, p1.rect))
      bounceBall(&b, &p1);
    else if (CheckCollisionRecs(b.rect, p2.rect))
      bounceBall(&b, &p2);
    // -------------------------

    // Drawing Logic -----------
    BeginDrawing();
    {
      ClearBackground(BLACK);
      drawPlayer(&p1);
      drawPlayer(&p2);
      drawBall(&b);
      drawScore(&s);
    }
    EndDrawing();
    // -------------------------
  }

  CloseWindow();
  return 0;
}
