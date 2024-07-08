#include "raylib.h"
#include "raymath.h"
#include "pong.h"

void updateEnemy(Player *p, Ball *b)
{
    p->rect.y = Clamp(b->rect.y - p->rect.height / 2, b->rect.y - 0.2, b->rect.y + 0.2);
}