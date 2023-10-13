#ifndef NEZ_SPRITE_RECT_H
#define NEZ_SPRITE_RECT_H

/*
#ifndef MEM_ALLOC
	#include "stdlib.h"
	#define MEM_ALLOC(x) maloc(x)
	
	#ifndef MEM_FREE
		#define MEM_FREE(x) free(x)
	#endif // !MEM_FREE

#endif // !MEM_ALLOC
*/


#ifndef NEZ_VEC2_F
	#define NEZ_VEC2_F NezVec2_f
// Vector2, 2 components
typedef struct NezVec2_f {
	float x;                // Vector x component
	float y;                // Vector y component
} NezVec2_f;
#endif // !NEZ_VEC2_F

#ifndef NEZ_RECT_F
	#define NEZ_RECT_F NezRect_f
// Rectangle, 4 components
typedef struct NezRect_f {
	float x;                // Rectangle top-left corner position x
	float y;                // Rectangle top-left corner position y
	float width;            // Rectangle width
	float height;           // Rectangle height
} NezRect_f;
#endif // !NEZ_RECT_F


// Struct for each animation. User needs to provide an array of IDs for image rect positions used in an animation.
typedef struct{
	int image_count;     // number of images in the animation
	int fps;            // time in seconds for each frame
	int *id_list;		// array of sprite image rect position IDs
}SpriteAnimation;


// TODO: Include rectangles for image and position
typedef struct{
	int x;				// origin x
	int y;				// origin y
	int w;              // sprite image width
	int h;              // sprite image height
	int x_offset;		// rectangle x offset from origin
	int y_offset;		// rectangle y offset from origin
	float x_scale;		// scale output rectangle width depending on origin x position
	float y_scale;		// scale output rectangle height depending on origin y position
	int image_count;	// number of all frames
	NEZ_RECT_F img_rect;	// rectangle for image location on texture
	NEZ_RECT_F spr_rect;	// rectangle for drawing on screen
	float time;			// used as timer (moduled to imageCount)
	NEZ_VEC2_F *image_pos_list;	// list of source x&y on the texture
}Sprite;

#ifndef NEZ_SPRITE_API
    #ifdef NEZ_SPRITE_STATIC
        #define NEZ_SPRITE_API static
    #else
        #define NEZ_SPRITE_API extern
    #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Initialize a sprite
// User needs to provide arrays for image rect positions and array of SpriteAnimations
NEZ_SPRITE_API Sprite
SpriteCreate(int _w, int _h, int x_off, int y_off, int total_img_count, NEZ_VEC2_F img_pos[]);

// Create sprite animation
// User needs to provide an array of IDs for image rect positions used in an animation
NEZ_SPRITE_API SpriteAnimation
SpriteAnimationCreate(int image_count, int fps, int id_list[]);

// Switches animation and resets timer
NEZ_SPRITE_API void
SpriteResetAnimation(Sprite* sprite);

// Handles logic of providing rectangle from texture and it's location in game with scaling
NEZ_SPRITE_API void
SpritePlay(Sprite *sprite, SpriteAnimation* sprite_anim, float delta, bool loop, bool* is_finished);

#ifdef __cplusplus
}
#endif
#endif // NEZ_SPRITE_H

//----------------------------------------------------------------------------

#ifdef NEZ_SPRITE_RECT_IMPLEMENTATION
#undef NEZ_SPRITE_RECT_IMPLEMENTATION
float SpriteAbs(float x){return x>0.0 ? x : -x;}
int SpriteSign(float x) { return x < 0.0 ? -1 : 1; }

Sprite
SpriteCreate(int _w, int _h, int x_off, int y_off, int total_img_count, NEZ_VEC2_F img_pos[]) {
	Sprite sprite = { 0 };
	sprite.w = _w;
	sprite.h = _h;
	sprite.x_offset = x_off;
	sprite.y_offset = y_off;
	sprite.image_count = total_img_count;
	sprite.image_pos_list = img_pos;
	return sprite;
}

SpriteAnimation
SpriteAnimationCreate(int image_count, int fps, int id_list[]) {
	SpriteAnimation anim = { 0 };
	anim.image_count = image_count;
	anim.fps = fps;
	anim.id_list = id_list;
	return anim;
}

void
SpriteResetAnimation(Sprite* sprite) {
	sprite->time = 0.f;
}

void
SpritePlay(Sprite* sprite, SpriteAnimation* sprite_anim, float delta, bool loop, bool *is_finished) {

	// SpriteAnimation *sprite_anim = &sprite->animation_list[sprite->current_animation];
	// advance timer
	sprite->time += delta * sprite_anim->fps;
	if (sprite->time >= sprite_anim->image_count) {
		*is_finished = true; // mark as finished
		if (loop) {
			sprite->time -= sprite_anim->image_count;
		}
		else {
			sprite->time = (float)(sprite_anim->image_count -1);
		}
	}

	//printf("%f \n", sprite->time);

	int image_index = (int)(sprite->time) % sprite_anim->image_count;
	int img_ID = sprite_anim->id_list[image_index];
	NEZ_VEC2_F image_pos = sprite->image_pos_list[img_ID];
	//printf("%d \n", image_index);

	sprite->img_rect.x = image_pos.x;
	sprite->img_rect.y = image_pos.y;
	sprite->img_rect.width = sprite->w;
	sprite->img_rect.height = sprite->h;

	// flip texture rectangle if negative
	if (sprite->x_scale < 0.0) {
		sprite->img_rect.width *= -1;
		//sprite->img_rect->x += sprite->w; // If required to have X offset for negative scale
	}

	if (sprite->y_scale < 0.0) {
		sprite->img_rect.height *= -1;
		//sprite->img_rect->y += sprite->h; // If required to have y offset for negative scale
	}


	float abs_x_scale = SpriteAbs(sprite->x_scale);
	float abs_y_scale = SpriteAbs(sprite->y_scale);

	float x = sprite->x + sprite->x_offset * abs_x_scale;
	float y = sprite->y + sprite->y_offset * abs_y_scale;

	if (sprite->y_scale < 0.f) {
		y += sprite->y_offset * sprite->y_scale;
	}

	float w = sprite->w * abs_x_scale;
	float h = sprite->h * abs_y_scale;
	// TODO: use scaling
	sprite->spr_rect.x = x;
	sprite->spr_rect.y = y;
	sprite->spr_rect.width = w;
	sprite->spr_rect.height = h;
}


#endif // NEZ_SPRITE_IMPLEMENTATION


