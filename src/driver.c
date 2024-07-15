#include "play_screen/play_screen.h"
#include "intro_screen/intro_screen.h"

typedef enum SCREEN
{
    INTRO_SCREEN,
    MENU_SCREEN,
    PLAY_SCREEN
} SCREEN;

SCREEN currentScreen = INTRO_SCREEN;
SCREEN nextScreen = PLAY_SCREEN;
bool isScreenTransitioning = false;

void initScreen()
{
    switch (currentScreen)
    {
    case INTRO_SCREEN:
        initIntroScreen();
        break;
    case MENU_SCREEN:
        break;
    case PLAY_SCREEN:
        initPlayScreen();
    }
}

void updateScreen()
{
    switch (currentScreen)
    {
    case INTRO_SCREEN:
        updateIntroScreen();
        break;
    case MENU_SCREEN:
        break;
    case PLAY_SCREEN:
        updatePlayScreen();
        break;
    }
}

void drawScreen()
{
    switch (currentScreen)
    {
    case INTRO_SCREEN:
        drawIntroScreen();
        break;
    case MENU_SCREEN:
        break;
    case PLAY_SCREEN:
        drawPlayScreen();
        break;
    }
}