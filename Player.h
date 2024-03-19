#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "raylib.h"
#include "ball.h"

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define DEFAULT_REC_SPEED 7
#define DEFAULT_REC_XLR8 (14.0f/60.0f)
#define MAX_REC_SPEED 12
#define LEFT_SIDE false
#define RIGHT_SIDE true

using namespace std;

class Player{
    public:
        string name;
        bool side;
        int score;
        Rectangle rec;
        Color recColor;
        int recSpeed;
        bool isControlInverted;

        Player();

        Player(string name, bool side);

        bool playerWon(Ball ball);
        
        static void inputHandler(Player *p1, Player *p2);

        static void resetWin(Player *p1, Player *p2);

         
        

};

#endif