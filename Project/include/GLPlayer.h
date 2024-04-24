#ifndef GLPLAYER_H
#define GLPLAYER_H

#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>
#include <GLInputs.h>

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
       void drawPlayer(int mouseX, int mouseY, int screenWidth, int screenHeight); // Updated function declaration



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

        void rotatePlayerToMouse(int mouseX, int mouseY, int screenWidth, int screenHeight); // New private function declaration
};

#endif // GLPLAYER_H
