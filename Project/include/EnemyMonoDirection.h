#ifndef ENEMYMONODIRECTION_H
#define ENEMYMONODIRECTION_H
#include <GLEnms.h>
#include "common.h"

class EnemyMonoDirection: public GLEnms{
    public:
        EnemyMonoDirection();
        enum {X_AXIS, Y_AXIS};
        int axis;
        virtual ~EnemyMonoDirection();
        void setAxis(int);
        void updateEnemyMove();
    protected:
    private:
};

#endif // ENEMYMONODIRECTION_H
