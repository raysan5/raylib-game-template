

#include "raylib.h"
#include "screens.h"
#include <stdio.h>

#define NEZ_VEC2_F Vector2
#define NEZ_RECT_F Rectangle
#include "sprite_rect.h"


//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------
Sprite plumber_sprite_1;
Sprite plumber_sprite_2;
Vector2 plumber_images[] = { {0.0f,0.0f}, { 16.0f,0.0f }, { 32.0f,0.0f }, { 48.0f,0.0f }, { 64.0f,0.0f }, { 80.0f,0.0f }, { 96.0f,0.0f } };
SpriteAnimation plumber_animations[2];

int plumber_idle_IDs[] = { 0 };
int plumber_walk_IDs[] = { 1,2,3,4,5,6 };
Rectangle plumber_image_rect = { 0 };
Rectangle plumber_rect = { 0 };

float delta_time = 0.016f;

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    plumber_animations[0] = SpriteAnimationCreate(1, 12, plumber_idle_IDs);
    plumber_animations[1] = SpriteAnimationCreate(6, 12, plumber_walk_IDs);
    plumber_sprite_1 = SpriteCreate(16, 16, -8, -16, 7, plumber_images);
    plumber_sprite_2 = plumber_sprite_1;
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

    plumber_sprite_1.y = 200;
    plumber_sprite_2.y = 200;
    bool is_finished = false;

    plumber_sprite_1.x = 200;
    plumber_sprite_1.x_scale = 2.f;
    plumber_sprite_1.y_scale = 2.f;
    SpritePlay(&plumber_sprite_1, &plumber_animations[1], GetFrameTime(), true, &is_finished);
    DrawRectangleLinesEx(plumber_rect, 1.f, BLACK);
    DrawTexturePro(plumber_texture, plumber_sprite_1.img_rect, plumber_sprite_1.spr_rect, origin, rotation, WHITE);

    plumber_sprite_2.x = 200;
    plumber_sprite_2.x_scale = -4.f;
    plumber_sprite_2.y_scale = -4.f;
    SpritePlay(&plumber_sprite_2, &plumber_animations[0], GetFrameTime(), true, &is_finished);
    DrawRectangleLinesEx(plumber_rect, 1.f, BLACK);
    DrawTexturePro(plumber_texture, plumber_sprite_2.img_rect, plumber_sprite_2.spr_rect, origin, rotation, WHITE);
}


// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}