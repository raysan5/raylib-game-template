#ifndef PONG_HEADER
#define PONG_HEADER
#include "raylib.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

// Player Definitions ---------

typedef struct Player
{
    Rectangle rect;

} Player;

typedef enum PlayerE
{
    PLAYER_ONE,
    PLAYER_TWO
} PlayerE;

void initPlayer(Player *, PlayerE);
void updatePlayer(Player *);
void drawPlayer(Player *);

// ------------------------

// Ball Definitions ---------

typedef struct Ball
{
    Rectangle rect;
    Vector2 vel;
} Ball;

void initBall(Ball *);
void updateBall(Ball *);
void drawBall(Ball *);

// --------------------------

// Score Definitions --------
#define SCORE_TEMPLATE "%02d : %02d"
#define SCORE_FONT_SIZE 20

typedef struct Score
{
    int p1Score;
    int p2Score;
    char text[20];
    int textWidth;
} Score;

void initScore(Score *);
void updateScore(Score *, PlayerE);
void updateScoreText(Score *);
void drawScore(Score *);

// --------------------------

// Driver Functions ----------

void bounceBall(Ball *, Player *);

// ---------------------------
#endif // PONG_HEADER