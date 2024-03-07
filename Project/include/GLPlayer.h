#ifndef GLPLAYER_H
#define GLPLAYER_H

#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>

class GLPlayer
{
    public:
        GLPlayer();
        virtual ~GLPlayer();

        // stand = 0, walk = 1 ... Attack = 4
        enum {
            STAND, WALK, RUN, JUMP, ATTACK
        };


        GLTexture *texture = new GLTexture();
        GLTimer   *myTime = new GLTimer();

        void initPlayer(int, int, char* fileName);
        void drawPlayer();

        void actions();

        vec3 plPosition;
        vec3 plScale;

        vec3 verts[4];

        float xMax,xMin,yMax,yMin;

        int framesX;
        float framesY;

        // for load action
        int actionTrigger;

    protected:

    private:
};

#endif // GLPLAYER_H
