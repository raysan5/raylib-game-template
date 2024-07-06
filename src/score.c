#include "pong.h"
#include "raylib.h"
#include "stdio.h"
#include "string.h"

void initScore(Score *s)
{
    s->p1Score = 0;
    s->p2Score = 0;
    updateScoreText(s);
}

void updateScore(Score *s, PlayerE pE)
{
    switch (pE)
    {
    case PLAYER_ONE:
        s->p1Score++;
        break;
    case PLAYER_TWO:
        s->p2Score++;
        break;
    }
}

void updateScoreText(Score *s)
{
    sprintf(s->text, SCORE_TEMPLATE, s->p1Score, s->p2Score);
    s->textWidth = MeasureText(s->text, SCORE_FONT_SIZE);
}

void drawScore(Score *s)
{

    DrawText(s->text, SCREEN_WIDTH / 2 - s->textWidth / 2, 10, 25, RAYWHITE);
}