#include "raylib.h"
#include "raymath.h"
#include "stdio.h"

static int frameCounter;
static float textFade;
char *introText = "Dong";

void initIntroScreen()
{
    frameCounter = 0;
    textFade = 0;
}

void updateIntroScreen()
{

    if (textFade > 1)
        return;

    if (frameCounter % 2 == 0)
    {
        textFade += 0.05;
    }
    frameCounter++;
}

void drawIntroScreen()
{

    ClearBackground(BLACK);
    Color textColor = Fade(WHITE, textFade);
    Vector2 textSize = MeasureTextEx(GetFontDefault(), introText, 40, 1);
    DrawText(introText, GetScreenWidth() / 2 - textSize.x / 2,
             GetScreenHeight() / 2 - textSize.y / 2, 40, textColor);
}

bool checkIntroScreenDone()
{
    return textFade > 1;
}