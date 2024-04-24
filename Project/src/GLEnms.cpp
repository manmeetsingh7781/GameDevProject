#include "GLEnms.h"

GLEnms::GLEnms()
{
    //ctor
    xPos=yPos = 0.0;
    zPos =-4.0;

    xSize = 1.0;
    ySize = 0.5;

    rotateX= rotateY= rotateZ= 0.0;
    frames =7;

    xMin=yMin=0.0;
    xMax=1.0/(float)frames;
    yMax=0.5;
    action=STATIC;

    xMove=0.01;
    yMove=0.01;



}

GLEnms::~GLEnms()
{
    //dtor
}
//GLEnms::~GLEnms()
//{
        //dtor
//}

void GLEnms::drawEnemy()
{
    glBindTexture(GL_TEXTURE_BINDING_2D,EnemyTex);

    glPushMatrix();
    glTranslatef(xPos, yPos, zPos);
    glRotatef(rotateX,1.0,0.0,0.0);
    glRotatef(rotateY,0.0,1.0,0.0);
    glRotatef(rotateZ,1.0,0.0,1.0);
    glScalef(xSize,ySize,1);


    glBegin(GL_POLYGON);
    glTexCoord2f(xMin,yMin);
    glVertex3f(1.0,1.0,0.0);

    glTexCoord2f(xMax,yMin);
    glVertex3f(-1.0,1.0,0.0);

    glTexCoord2f(xMax,yMax);
    glVertex3f(-1.0,-1.0,0.0);

    glTexCoord2f(xMin,yMax);
    glVertex3f(1.0,-1.0,0.0);
    glEnd();

    glPopMatrix();
}

void GLEnms::placeEnemy(float x, float y, float z)
{
    xPos =x;
    yPos =y;
    zPos =z;
}

void GLEnms::initEnemy(GLuint tex)
{
    EnemyTex = tex;
    TE->start();
}

void GLEnms::actions()
{
    switch(action){
    case STATIC:
          /*if(TE->getTicks()>60){
                xMin+=1.0/frames;
                xMax+=1.0/frames;
                yMin=0.5;
                yMax=1.0;

                if(xMax>=1){xMin=0;xMax=1.0/frames;}
                TE->reset();
            }*/
            drawEnemy();
          break;

    case MOVE_AXIS:
    case MOVE_DIRECTIONAL:
     if(TE->getTicks()>60){
            xMin+=1.0/frames;
            xMax+=1.0/frames;
            yMin=0.0;
            yMax=0.5;

            if(xMax>=1){xMin=0;xMax=1.0/frames;}
            TE->reset();
        }
        drawEnemy();
        break;
    }

}
