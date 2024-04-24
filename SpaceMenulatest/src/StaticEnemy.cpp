#include "StaticEnemy.h"

StaticEnemy::StaticEnemy()
{
    //ctor
    action = STATIC;
}

StaticEnemy::~StaticEnemy()
{
    //dtor
}

void StaticEnemy::updateEnemyMove()
{
    placeEnemy((float)(rand()/float(RAND_MAX))*5-2.5,-0.2, -2.5);
}


