#ifndef STATICENEMY_H
#define STATICENEMY_H
#include "GLEnms.h"
#include<GLTexture.h>
#include<GL/gl.h>
#include<GLTimer.h>


class StaticEnemy: public GLEnms
{
    public:
        StaticEnemy();
        virtual ~StaticEnemy();
        void updateEnemyMove();
    protected:
    private:
};

#endif // STATICENEMY_H
