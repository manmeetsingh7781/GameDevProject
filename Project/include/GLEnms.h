#ifndef GLENMS_H
#define GLENMS_H

#include<GLTexture.h>
#include<GL/gl.h>
#include<GLTimer.h>

class GLEnms
{
    public:
        GLEnms();
        virtual ~GLEnms();

        void drawEnemy();                      //Draw Objects
        void placeEnemy(float,float,float);    // Place Enemy
        void initEnemy(GLuint);
        void actions();                       //Movements and actions

        bool isEnemyLive;                      //Status of the Enemy
        GLuint EnemyTex;                       // Handle Texture

        float xPos, yPos, zPos;                 //Placement
        float xSize, ySize;                     //Scaling Factor

        float rotateX, rotateY, rotateZ;       //rotations

        int frames;                            // number of frames
        float xMove;                             // moving speed on x axis
        int action;                          //to make an action for enemy

        GLTimer *TE = new GLTimer();


    protected:

    private:
        float xMin,yMin,xMax,yMax;
};

#endif // GLENMS_H
