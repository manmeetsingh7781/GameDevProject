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
        if(xPos<-2.0){
            xMove=0.01;
        }
        else if(xPos>2.0){
           xMove=-0.01;
        }

        // y axis
        if(yPos < -2.0){
            yMove=0.01;
        }
        else if(yPos > 2.0){
            yMove=-0.01;
        }

        xPos +=xMove;
        yPos +=yMove;

}
