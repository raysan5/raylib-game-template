

#include "raylib.h"
#include "screens.h"
#include <stdio.h>

#define NEZ_VEC2_F Vector2
#define NEZ_RECT_F Rectangle
#include "sprite.h"


//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------
Sprite plumber_sprite;
SpriteAnimation plumber_idle;
SpriteAnimation plumber_walk;
Vector2 plumber_images[] = { {0.0f,0.0f}, { 16.0f,0.0f }, { 32.0f,0.0f }, { 48.0f,0.0f }, { 64.0f,0.0f }, { 80.0f,0.0f }, { 96.0f,0.0f } };
int plumber_idle_IDs[] = { 0 };
int plumber_walk_IDs[] = { 1,2,3,4,5,6 };
SpriteAnimation plumber_animations[2];
Rectangle plumber_image_rect = { 0 };
Rectangle plumber_rect = { 0 };

float delta_time = 0.016f;

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    plumber_idle = SpriteAnimationCreate(1, 12, plumber_idle_IDs);
    plumber_walk = SpriteAnimationCreate(6, 12, plumber_walk_IDs);
    plumber_animations[0] = plumber_idle;
    plumber_animations[1] = plumber_walk;
    plumber_sprite = SpriteCreate(16, 16, -8, -16, 7, plumber_images, 1, plumber_animations);
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
    Vector2 pos = { 20, 10 };
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, MAROON);

    Vector2 origin = (Vector2){ 0.0f,  0.0f };
    float rotation = 0.0f;

    DrawLine(200, 170, 200, 230, PINK);
    DrawLine(170, 200, 230, 200, PINK);

    plumber_sprite.y = 200;
    plumber_sprite.current_animation = 1;

    plumber_sprite.x = 200;
    plumber_sprite.x_scale = 2.f;
    plumber_sprite.y_scale = 2.f;
    SpritePlay(&plumber_sprite, GetFrameTime());
    DrawRectangleLinesEx(plumber_rect, 1.f, BLACK);
    DrawTexturePro(plumber_texture, plumber_sprite.img_rect, plumber_sprite.spr_rect, origin, rotation, WHITE);

    plumber_sprite.x = 200;
    plumber_sprite.x_scale = -4.f;
    plumber_sprite.y_scale = -4.f;
    SpritePlay(&plumber_sprite, 0.f);
    DrawRectangleLinesEx(plumber_rect, 1.f, BLACK);
    DrawTexturePro(plumber_texture, plumber_sprite.img_rect, plumber_sprite.spr_rect, origin, rotation, WHITE);
}


// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}