#include "EnemyMonoDirection.h"
EnemyMonoDirection::EnemyMonoDirection()
{
    //ctor
    yMove=0.01;
    action = MOVE_AXIS;
}

EnemyMonoDirection::~EnemyMonoDirection()
{
    //dtor
}

// set what axis enemy you want to move x or y only
// 0 for x
// 1 for y
void EnemyMonoDirection::setAxis(int value)
{

    if (value == 0) {
        axis = X_AXIS;
    }else {
        axis = Y_AXIS;
    }
}

void EnemyMonoDirection::updateEnemyMove()
{
    // x axis
    if (axis == X_AXIS) {
        if(xPos<-2.0){
            xMove=0.01;
        }
        else if(xPos>2.0){
           xMove=-0.01;
        }
        xPos +=xMove;
    }else {
        // y axis
        if(yPos < -2.0){
            yMove=0.01;
        }
        else if(yPos > 2.0){
            yMove=-0.01;
        }
        yPos +=yMove;
    }
}
