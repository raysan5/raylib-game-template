#include "play_screen.h"

static Player p1, p2;
static Ball b;
static Score s;

void initPlayScreen()
{
    initGame(&p1, &p2, &b, &s);
}

void updatePlayScreen()
{
    // Quick Reset Logic --------
    if (IsKeyPressed(KEY_SPACE))
    {
        initBall(&b);
    }
    // ------------------------
    // Ball Collision Logic -----
    // TODO: there is an issue with ball collision logic
    //  NOTE: sometimes the ball hits the player and it counts it as a score
    //  NOTE: i think the issue is the velocity of the ball at every frame
    if (CheckPlayerScored(&p1, &b))
    {
        resetRound(&p1, &p2, &b);
        s.p1Score++;
    }
    else if (CheckPlayerScored(&p2, &b))
    {
        resetRound(&p1, &p2, &b);
        s.p2Score++;
    }
    else if (CheckCollisionRecs(b.rect, p1.rect))
        bounceBall(&b, &p1);
    else if (CheckCollisionRecs(b.rect, p2.rect))
        bounceBall(&b, &p2);
    // -------------------------
    // Update Logic -----------
    if (CheckRoundResetting())
        updateReset();
    else
    {
        updatePlayer(&p1);
        updateEnemy(&p2, &b);
        updateBall(&b);
    }
    updateScoreText(&s);
    // ------------------------
}

void drawPlayScreen()
{

    ClearBackground(BLACK);

    drawPlayer(&p1);
    drawPlayer(&p2);
    drawScore(&s);
    drawBall(&b);

    if (CheckRoundResetting())
        drawResetRoundCounter();
}