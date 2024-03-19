#include "Player.h"

Player::Player(){
    //
}

Player::Player(string name, bool side){
    this->name = name;
    this->side = side;
    Rectangle temp;
    temp.width = 20;
    temp.height = SCREEN_HEIGHT/8;
    temp.y = SCREEN_HEIGHT/2 - temp.height/2;
    temp.x = (this->side == LEFT_SIDE) ? 5 : SCREEN_WIDTH - 5 - temp.width;
    this->rec = temp;
    this->recColor = (this->side == LEFT_SIDE) ? BLUE : RED;
    this->score = 0;
    this->recSpeed = DEFAULT_REC_SPEED;
    this->isControlInverted = false;
}

void Player::inputHandler(Player *leftPlayer, Player *rightPlayer){
    // if(this->side == LEFT_SIDE){
    //     if(IsKeyDown(KEY_W) && this->rec.y>0){
    //         this->rec.y-=this->recSpeed;
    //         if(this->rec.y < 0) this->rec.y = 0;
    //     }
    //      if(IsKeyDown(KEY_S) && this->rec.y<768){
    //         this->rec.y+=this->recSpeed;
    //         if(this->rec.y > 768) this->rec.y = 768;
    //     }

    // }
    // else{
    //     if(IsKeyDown(KEY_UP) && this->rec.y>0){
    //         this->rec.y-=this->recSpeed;
    //         if(this->rec.y < 0) this->rec.y = 0;
    //     }
    //      if(IsKeyDown(KEY_DOWN) && this->rec.y<768){
    //         this->rec.y+=this->recSpeed;
    //         if(this->rec.y > 768) this->rec.y = 768;
    //     }

    // }

    // leftPlayer input handler
    if(!leftPlayer->isControlInverted) {

        if(IsKeyDown(KEY_W) && leftPlayer->rec.y>0){
            leftPlayer->rec.y-=leftPlayer->recSpeed;
            if(leftPlayer->rec.y < 0) leftPlayer->rec.y = 0;
        }
        if(IsKeyDown(KEY_S) && leftPlayer->rec.y<768){
            leftPlayer->rec.y+=leftPlayer->recSpeed;
            if(leftPlayer->rec.y > 768 - leftPlayer->rec.height) leftPlayer->rec.y = 768 - leftPlayer->rec.height;
        }
    }
    else {
        if(IsKeyDown(KEY_S) && leftPlayer->rec.y>0){
            leftPlayer->rec.y-=leftPlayer->recSpeed;
            if(leftPlayer->rec.y < 0) leftPlayer->rec.y = 0;
        }
        if(IsKeyDown(KEY_W) && leftPlayer->rec.y<768){
            leftPlayer->rec.y+=leftPlayer->recSpeed;
            if(leftPlayer->rec.y > 768 - leftPlayer->rec.height) leftPlayer->rec.y = 768 - leftPlayer->rec.height;
        }
    }
    

    //right player
    if(!rightPlayer->isControlInverted) {
        if(IsKeyDown(KEY_UP) && rightPlayer->rec.y>0){
            rightPlayer->rec.y-=rightPlayer->recSpeed;
            if(rightPlayer->rec.y < 0) rightPlayer->rec.y = 0;
        }
        if(IsKeyDown(KEY_DOWN) && rightPlayer->rec.y<768){
            rightPlayer->rec.y+=rightPlayer->recSpeed;
            if(rightPlayer->rec.y > 768 - rightPlayer->rec.height) rightPlayer->rec.y = 768 - rightPlayer->rec.height;
        }
    }
    else {
        if(IsKeyDown(KEY_DOWN) && rightPlayer->rec.y>0){
            rightPlayer->rec.y-=rightPlayer->recSpeed;
            if(rightPlayer->rec.y < 0) rightPlayer->rec.y = 0;
        }
        if(IsKeyDown(KEY_UP) && rightPlayer->rec.y<768){
            rightPlayer->rec.y+=rightPlayer->recSpeed;
            if(rightPlayer->rec.y > 768 - rightPlayer->rec.height) rightPlayer->rec.y = 768 - rightPlayer->rec.height;
        }
    }
    
}

bool Player::playerWon(Ball ball){
    if(this->side == RIGHT_SIDE){
        if(ball.position.x - ball.radius <= 0){
            return true;
        }
    }
    else{
        if(ball.position.x + ball.radius >= SCREEN_WIDTH){
            return true;
        }
    }
    return false;
}

void Player::resetWin(Player *p1, Player *p2) {
    p1->name.clear();
    p2->name.clear();
    p1-> score = 0;
    p2-> score = 0;
    p1->rec.y = SCREEN_HEIGHT/2 - SCREEN_HEIGHT/16;
    p2->rec.y = SCREEN_HEIGHT/2 - SCREEN_HEIGHT/16;
    p1->rec.height = SCREEN_HEIGHT/8;
    p2->rec.height = SCREEN_HEIGHT/8;
    p1->recSpeed = DEFAULT_REC_SPEED;
    p2->recSpeed = DEFAULT_REC_SPEED;
}