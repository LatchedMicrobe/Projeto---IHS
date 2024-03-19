#include "Skill.h"
#include <iostream>

Skill::Skill(int id, Player *p_aliado, Player *p_inimigo, Ball *ball, Sound gemidao) {
    this->id = id;
    this->p_aliado = p_aliado;
    this->p_inimigo = p_inimigo;
    this->ball = ball;
    this->isActive = false;
    this->gemidao = gemidao;

    
     if(id == 1) {
        this->skill_time = 180;
        this->cd = 15*60;
        this->timeremaining = 0;
     }
     else if(id == 2) {
        this->skill_time = 0;
        this->cd = 15*60;
        this->timeremaining = 0;
     }
     else if(id ==3) {

        this->skill_time = 180;
        this->cd = 15*60;
        this->timeremaining = 0;
     }
     else if(id == 69) {
        this->skill_time = 0;
        this->cd = 15*60;
        this->timeremaining = 0;
     }
}

void Skill::increaseSpeed() {
    p_aliado->recSpeed = MAX_REC_SPEED;
}

void Skill::changeDirection() {
    ball->vx = (ball->vx) * -1;
}

void Skill::changeEnemyControl() {
    p_inimigo->isControlInverted = true;
}

void Skill::playGemidao() {
    PlaySound(gemidao);
}

void Skill::updateSkill() {
    if(this->isActive) {
        switch (this->id) {
            case 1:
                increaseSpeed();
                break;
            case 2:
                changeDirection();
                break;
            case 3:
                changeEnemyControl();
                break;
            case 69:
                playGemidao();
                break;
            default:
                break;
        }
    }
    else {
        p_aliado->recSpeed = DEFAULT_REC_SPEED;
        p_inimigo->isControlInverted = false;
    }
    this->timeremaining--;
    if(this->cd - this->timeremaining >= this->skill_time) this->isActive = false;

    if(timeremaining <=0) timeremaining = 0;

}