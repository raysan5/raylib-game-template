
#ifndef SCREENS_H
#define SCREENS_H

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { UNKNOWN = -1, LOGO = 0, GAMEPLAY, TITLE, OPTIONS, ENDING } GameScreen;

typedef struct {
    void(*Enter)();
    void(*Exit)();
    void(*Update)();
    void(*Draw)();
}GameScreenState;

//----------------------------------------------------------------------------------
// Global Variables Declaration (shared by several modules)
//----------------------------------------------------------------------------------
//extern GameScreenState screen_state_array[];
extern GameScreen currentScreen;
extern Font font;
extern Music music;
extern Sound fxCoin;
extern Texture2D plumber_texture;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Logo Screen Functions Declaration
//----------------------------------------------------------------------------------
/*
*/
void InitLogoScreen(void);
void UnloadLogoScreen(void);
void UpdateLogoScreen(void);
void DrawLogoScreen(void);


void InitGameplayScreen(void);
void UnloadGameplayScreen(void);
void UpdateGameplayScreen(void);
void DrawGameplayScreen(void);

#ifdef __cplusplus
}
#endif

#endif // SCREENS_H