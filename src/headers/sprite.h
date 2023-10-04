#ifndef NEZ_SPRITE_H
#define NEZ_SPRITE_H

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



#ifndef MAX_ANIM_IMG_COUNT
	#define MAX_ANIM_IMG_COUNT 10 // default animation array length (avoid allocations)
#endif // !MAX_ANIM_IMG_COUNT

typedef struct{
	float image;        // used as timer (moduled to imageCount) and on drawing floored(cast as int)
	int imageCount;     // number of images in the animation
	int fps;            // time in seconds for each frame
	int id_list[MAX_ANIM_IMG_COUNT]; // array of sprite IDs
}SpriteAnimation;

#ifndef MAX_ANIM_COUNT
	#define MAX_ANIM_COUNT 5  // default animation array length (avoid allocations)
#endif // !MAX_ANIM_COUNT

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
	NEZ_VEC2_F image_pos_list[MAX_ANIM_COUNT * MAX_ANIM_IMG_COUNT];	// list of source x&y on the texture
	int current_animation;	// ID for current animation
	int animation_count;// animationList size
	SpriteAnimation animation_list[MAX_ANIM_COUNT];
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

NEZ_SPRITE_API void
SpriteInit(Sprite* sprite, int _w, int _h, int x_off, int y_off, int total_img_count, NEZ_VEC2_F img_pos[], int anim_count, SpriteAnimation anim[]);
NEZ_SPRITE_API void
SpritePlay(Sprite* sprite, int anim_id, float delta, NEZ_RECT_F* tex_rect, NEZ_RECT_F* sprite_rect);

#ifdef __cplusplus
}
#endif
#endif // NEZ_SPRITE_H

//----------------------------------------------------------------------------

#ifdef NEZ_SPRITE_IMPLEMENTATION
#undef NEZ_SPRITE_IMPLEMENTATION
float SpriteAbs(float x){return x>0.0 ? x : -x;}

void
SpriteInit(Sprite* sprite, int _w, int _h, int x_off, int y_off, int total_img_count, NEZ_VEC2_F img_pos[], int anim_count, SpriteAnimation anim[]) {
	sprite->w = _w;
	sprite->h = _h;
	sprite->x_offset = x_off;
	sprite->y_offset = y_off;
	sprite->image_count = total_img_count;
	sprite->animation_count = anim_count;
	for (int i = 0; i < total_img_count; i++) {
		sprite->image_pos_list[i] = img_pos[i];
	}
	for (int i = 0; i < anim_count; i++) {
		sprite->animation_list[i] = anim[i];
	}
}

void
SpritePlay(Sprite* sprite, int anim_id, float delta, NEZ_RECT_F *tex_rect, NEZ_RECT_F *sprite_rect) {
	NEZ_VEC2_F offset = (NEZ_VEC2_F){ sprite->x_offset * sprite->x_scale, sprite->y_offset * sprite->y_scale };

	float x = sprite->x - offset.x;
	float y = sprite->y - offset.y;
	float w = sprite->w * SpriteAbs(sprite->x_scale);
	float h = sprite->h * SpriteAbs(sprite->y_scale);


}

#endif // NEZ_SPRITE_IMPLEMENTATION


