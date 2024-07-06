#include "raylib.h"
#include "raymath.h"
#include "pong.h"
#include "stdio.h"

static int resetTimer = 3;
static bool isRoundResetting = false;
static char resetTimerString[3];
static Vector2 resetTimerTextSize;
static double lastUpdatedResetTimer;

void initGame(Player *p1, Player *p2, Ball *b, Score *s)
{
    if (p1)
        initPlayerOne(p1);
    if (p2)
        initPlayerTwo(p2);
    if (b)
        initBall(b);
    if (s)
        initScore(s);
}

bool CheckRoundResetting()
{
    return isRoundResetting;
}

void resetRound(Player *p1, Player *p2, Ball *b)
{
    initGame(p1, p2, b, 0);
    resetTimer = 3;
    isRoundResetting = true;
    lastUpdatedResetTimer = GetTime();
}

void updateReset()
{
    if (GetTime() - lastUpdatedResetTimer >= 1)
    {
        resetTimer--;
        if (resetTimer == 0)

            isRoundResetting = false;
        lastUpdatedResetTimer = GetTime();
    }

    sprintf(resetTimerString, "%d", resetTimer);

    resetTimerTextSize = MeasureTextEx(GetFontDefault(), resetTimerString,
                                       40, 1);
}

void drawResetRoundCounter()
{
    DrawText(resetTimerString, SCREEN_WIDTH / 2 - resetTimerTextSize.x / 2,
             SCREEN_HEIGHT / 2 - resetTimerTextSize.y / 2, 40, RAYWHITE);
}

void bounceBall(Ball *b, Player *p)
{

    Vector2 p1Center = {p->rect.x + p->rect.width / 2.0, p->rect.y + p->rect.height / 2.0};
    Vector2 bCenter = {b->rect.x + b->rect.width / 2.0, b->rect.y + b->rect.height / 2.0};

    float bSpeed = Vector2Length(b->vel);

    b->vel = Vector2Subtract(bCenter, p1Center);
    b->vel = Vector2Scale(Vector2Normalize(b->vel), bSpeed);
}

bool CheckPlayerScored(Player *p, Ball *b)
{
    switch (p->e)
    {
    case PLAYER_ONE:
        return b->rect.x < p->rect.x + p->rect.width - 2;
    case PLAYER_TWO:
        return b->rect.x + b->rect.width > p->rect.x + 2;
    }

    return false;
}
