#include "raylib.h"
#include "raymath.h"
#include "pong.h"

void bounceBall(Ball *b, Player *p)
{

    Vector2 p1Center = {p->rect.x + p->rect.width / 2.0, p->rect.y + p->rect.height / 2.0};
    Vector2 bCenter = {b->rect.x + b->rect.width / 2.0, b->rect.y + b->rect.height / 2.0};

    float bSpeed = Vector2Length(b->vel);

    b->vel = Vector2Subtract(bCenter, p1Center);
    b->vel = Vector2Scale(Vector2Normalize(b->vel), bSpeed);
}
