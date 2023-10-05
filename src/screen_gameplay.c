

#include "raylib.h"
#include "screens.h"
#include <stdio.h>
#include "sprite.h"


//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------
Sprite plumber_sprite = { 0 };
SpriteAnimation plumber_idle = { 0 };
Vector2 plumber_images[] = { {0.0f,0.0f}, { 16.0f,0.0f }, { 32.0f,0.0f }, { 48.0f,0.0f }, { 64.0f,0.0f }, { 80.0f,0.0f }, { 96.0f,0.0f } };
int plumber_idle_IDs[] = { 0 };
SpriteAnimation plumber_animations[1];
Rectangle plumber_image_rect = { 0 };
Rectangle plumber_rect = { 0 };

float delta_time = 0.f;

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    plumber_animations[0] = plumber_idle;
    // TODO: Initialize GAMEPLAY screen variables here!
    plumber_idle = SpriteAnimationCreate(1, 12, plumber_idle_IDs);
    plumber_sprite = SpriteCreate(16, 16, -8, -16, 7, plumber_images, 1, plumber_animations);

    plumber_sprite.x = 200;
    plumber_sprite.y = 200;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    SpritePlay(&plumber_sprite, 0, delta_time, &plumber_image_rect, &plumber_rect);
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
    Vector2 pos = { 20, 10 };
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, MAROON);

    Vector2 origin = (Vector2){ 0.0f,  0.0f };
    float rotation = 0.0f;
    DrawTexturePro(plumber_texture, plumber_image_rect, plumber_rect, origin, rotation, WHITE);
}


// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}