#include "raylib.h"
#include "raymath.h"
#include "play_screen.h"

void initBall(Ball *b)
{
    b->rect.width = 10;
    b->rect.height = 10;
    b->rect.x = SCREEN_WIDTH / 2;
    b->rect.y = SCREEN_HEIGHT / 2;
    b->vel.x = GetRandomValue(-4, 4);
    if (fabs(b->vel.x) < 1.5)
        b->vel.x = 1.5;

    b->vel.y = GetRandomValue(-3, 3);
}

void updateBall(Ball *b)
{
    // ball-player collision, it doesnt matter which player
    if (b->rect.y <= 0)
    {
        b->rect.y = 1;
        b->vel.y = -b->vel.y;
    }
    else if (b->rect.y >= SCREEN_HEIGHT - b->rect.height)
    {
        b->rect.y = SCREEN_HEIGHT - b->rect.height - 1;
        b->vel.y = -b->vel.y;
    }

    b->rect.x += b->vel.x;
    b->rect.y += b->vel.y;
}

void drawBall(Ball *b)
{
    DrawRectangleRec(b->rect, BLUE);
}