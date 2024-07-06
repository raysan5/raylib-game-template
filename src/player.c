#include "raylib.h"
#include "raymath.h"
#include "pong.h"

void initPlayer(Player *p, PlayerE pE)
{
    p->rect.width = 20;
    p->rect.height = 100;
    switch (pE)
    {
    case PLAYER_ONE:
        p->rect.x = 20;
        break;
    case PLAYER_TWO:
        p->rect.x = SCREEN_WIDTH - 20;
        break;
    }
    p->rect.y = SCREEN_HEIGHT / 2;
}

void updatePlayer(Player *p)
{
    if (IsKeyDown(KEY_DOWN))
    {
        p->rect.y += 5;
    }
    else if (IsKeyDown(KEY_UP))
    {
        p->rect.y -= 5;
    }
    else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        p->rect.y = GetMouseY() - p->rect.height / 2;
    }

    p->rect.y = Clamp(p->rect.y, 0, SCREEN_HEIGHT - p->rect.height);
}

void drawPlayer(Player *p)
{
    DrawRectangleRec(p->rect, RAYWHITE);
}
