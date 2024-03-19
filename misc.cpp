#include "misc.h"

void updateScore(Player *p1, Player *p2, Ball *ball, int *updateFlag) {
    if(p1->playerWon(*ball) && *updateFlag == 0) {
        (p1->score)++;
        *updateFlag = 1;
    } 
    if(p2->playerWon(*ball) && *updateFlag == 0) {
        (p2->score)++;
        *updateFlag = 1;
    }
    // o reset desse uptadeFlag deve estar no reset ball(que vou fazer jaja)


}

void resetBall(Player *p1, Player *p2, Ball *ball, int *updateFlag, int ballSpeed) {
    if(p1->playerWon(*ball) || p2->playerWon(*ball)) {
        if(p1->playerWon(*ball)) {
            ball ->vx = ballSpeed - 2;
            ball -> vy = 0;
        }
        if(p2->playerWon(*ball)) {
            ball->vx = (ballSpeed - 2) * -1;
            ball->vy = 0;
        }
        ball->position.x = SCREEN_WIDTH/2;
        ball->position.y = SCREEN_HEIGHT/2;
        *updateFlag = 0;
    }

}

