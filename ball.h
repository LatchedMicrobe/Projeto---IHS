#ifndef BALL_H
#define BALL_H

#include <iostream>
#include "raylib.h"



class Ball {
    public:
        int radius;
        Vector2 position;
        float vx;
        float vy;
        Color cirColor;
        bool canHitPlayer;
        bool canHitWall;
        

        Ball();
        Ball(int radius, Vector2 position, float vx, float vy);
        void updateBallPosition();
        void updateBallSpeed(Rectangle upperWall, Rectangle bottomWall, Rectangle leftPlayer_collisison, Rectangle rightPlayer_collision, Sound bonk);

};








#endif