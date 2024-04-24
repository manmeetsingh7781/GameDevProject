#include "EnemyMonoDirection.h"
EnemyMonoDirection::EnemyMonoDirection()
{
    enmPos.x = enmPos.y = 0.0;
    enmPos.z = -4.0;

    xSize = 1.0;
    ySize = 1.0;

    rotateX = rotateY = rotateZ = 0.0;
    //frames = 1;

    xMin = yMin = 0.0;
    xMax = 1.0 ;
    yMax = 1.0;


    xMove = 0.01;
    yMove = 0.01;
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


    //frames = 1;



    // x axis
    if (axis == X_AXIS) {
        if(enmPos.x<-2.0){
            xMove=0.01;
        }
        else if(enmPos.x>2.0){
           xMove=-0.01;
        }
        enmPos.x +=xMove;
    }else {
        // y axis
        if(enmPos.y < -2.0){
            yMove=0.01;
        }
        else if(enmPos.y > 2.0){
            yMove=-0.01;
        }
        enmPos.y +=yMove;
    }
}
