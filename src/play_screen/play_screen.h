#ifndef PONG_HEADER
#define PONG_HEADER
#include "raylib.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

// Play Screen Definitions -----

void initPlayScreen();
void updatePlayScreen();
void drawPlayScreen();

// -----------------------------

// Player Definitions ---------

typedef enum PlayerE
{
    PLAYER_ONE,
    PLAYER_TWO
} PlayerE;

typedef struct Player
{
    Rectangle rect;
    PlayerE e;
} Player;

void initPlayer(Player *);
void initPlayerOne(Player *);
void initPlayerTwo(Player *);
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
    int fontSize;
    Vector2 textSize;
} Score;

void initScore(Score *);
void updateScoreText(Score *);
void drawScore(Score *);

// --------------------------

// Driver Functions ----------

void bounceBall(Ball *, Player *);
void initGame(Player *, Player *, Ball *, Score *);
bool CheckRoundResetting();
void resetRound(Player *, Player *, Ball *);
void updateReset();
void drawResetRoundCounter();
bool CheckPlayerScored(Player *, Ball *);

// -------------------------

// Enemy Functions ----------

void updateEnemy(Player *, Ball *);

// --------------------------

// ---------------------------
#endif // PONG_HEADER