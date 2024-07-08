#include "play_screen.h"
#include "raylib.h"
#include "stdio.h"
#include "string.h"

void initScore(Score *s)
{
    s->p1Score = 0;
    s->p2Score = 0;
    s->fontSize = 25;
    updateScoreText(s);
}

void updateScoreText(Score *s)
{
    sprintf(s->text, SCORE_TEMPLATE, s->p1Score, s->p2Score);
    s->textSize = MeasureTextEx(GetFontDefault(), s->text, s->fontSize, 1);
}

void drawScore(Score *s)
{
    DrawText(s->text, SCREEN_WIDTH / 2 - s->textSize.x / 2,
             20 - s->textSize.y / 2, s->fontSize, RAYWHITE);
}