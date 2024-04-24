#ifndef BIDIRECTIONALENEMY_H
#define BIDIRECTIONALENEMY_H
#include <GLEnms.h>
#include "common.h"


class BiDirectionalEnemy: public GLEnms
{
    public:
        BiDirectionalEnemy();
        virtual ~BiDirectionalEnemy();

        void updateEnemyMove();
    protected:
    private:
};

#endif // BIDIRECTIONALENEMY_H
