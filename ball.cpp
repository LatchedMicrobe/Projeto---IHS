#include "ball.h"
#include "math.h"
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
Ball::Ball(){
    //
}

Ball::Ball(int radius, Vector2 position, float vx, float vy){
this->radius = radius;
this->position = position;
this->vx = vx;
this->vy = vy;

}

void Ball::updateBallPosition(){
    this->position.x+=vx;
    this->position.y+=vy;
}

void Ball::updateBallSpeed(Rectangle upperWall, Rectangle bottomWall, Rectangle leftPlayer_collisison, Rectangle rightPlayer_collision, Sound bonk){
    // upperWall and bottomWall
    if((CheckCollisionCircleRec(this->position, this->radius, upperWall) || CheckCollisionCircleRec(this->position, this->radius, bottomWall)) && this->canHitWall == true ){
        this->canHitWall = false;
        this->vy *= -1;
        PlaySound(bonk);
    }
    if(!CheckCollisionCircleRec(this->position, this->radius, upperWall) && !CheckCollisionCircleRec(this->position, this->radius, bottomWall)) this->canHitWall = true;

    //leftPlayer collision
    if(CheckCollisionCircleRec(this->position, this->radius, leftPlayer_collisison) && this->canHitPlayer){
        this->canHitPlayer = false;
        Vector2 centerOfRec;
        centerOfRec.x = leftPlayer_collisison.x + leftPlayer_collisison.width/2;
        centerOfRec.y = leftPlayer_collisison.y + leftPlayer_collisison.height/2;
        Vector2 centerToBall; 
        centerToBall.x = this->position.x - centerOfRec.x;
        centerToBall.y = this->position.y - centerOfRec.y;
        double angle = atan2(centerToBall.y, centerToBall.x);
        double absoluteSpeed = sqrt(vx*vx + vy*vy);
        this->vx = absoluteSpeed*cos(angle)*1.10;
        this->vy = absoluteSpeed*sin(angle)*1.10;
        PlaySound(bonk);
        
    }
    if(CheckCollisionCircleRec(this->position, this->radius, rightPlayer_collision) && this->canHitPlayer){
        this->canHitPlayer = false;
        Vector2 centerOfRec;
        centerOfRec.x = rightPlayer_collision.x + rightPlayer_collision.width/2;          
        centerOfRec.y = rightPlayer_collision.y + rightPlayer_collision.height/2;
        Vector2 centerToBall; 
        centerToBall.x = this->position.x - centerOfRec.x;
        centerToBall.y = this->position.y - centerOfRec.y;
        double angle = atan2(centerToBall.y, centerToBall.x);
        double absoluteSpeed = sqrt(vx*vx + vy*vy);
        this->vx = absoluteSpeed*cos(angle);
        this->vy = absoluteSpeed*sin(angle);
        PlaySound(bonk);
    }
    if(!CheckCollisionCircleRec(this->position, this->radius, leftPlayer_collisison) && !CheckCollisionCircleRec(this->position, this->radius, rightPlayer_collision))  this->canHitPlayer = true;
}

