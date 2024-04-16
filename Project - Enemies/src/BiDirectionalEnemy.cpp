#include "BiDirectionalEnemy.h"

BiDirectionalEnemy::BiDirectionalEnemy()
{
    //ctor
    action = MOVE_DIRECTIONAL;
}

BiDirectionalEnemy::~BiDirectionalEnemy()
{
    //dtor
}
void BiDirectionalEnemy::updateEnemyMove()
{
     // x axis
        if(enmPos.x<-2.0){
            xMove=0.01;
        }
        else if(enmPos.x>2.0){
           xMove=-0.01;
        }

        // y axis
        if(enmPos.y < -2.0){
            yMove=0.01;
        }
        else if(enmPos.y > 2.0){
            yMove=-0.01;
        }

        enmPos.x +=xMove;
        enmPos.y +=yMove;

}
