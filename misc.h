#ifndef MISC_H
#define MISC_H

#include "raylib.h"
#include "Player.h"
#include "ball.h"

void updateScore(Player *p1, Player *p2, Ball *ball, int *updateFlag);

void resetBall(Player *p1, Player *p2, Ball *ball, int *updateFlag, int ballSpeed);




#endif