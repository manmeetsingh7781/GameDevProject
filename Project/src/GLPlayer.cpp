#include "GLPlayer.h"

GLPlayer::GLPlayer()
{
    //ctor
    verts[0].x = -0.5;
    verts[0].y = -0.5;
    verts[0].z = -1;

    verts[1].x = 0.5;
    verts[1].y = -0.5;
    verts[1].z = -1;


    verts[2].x = 0.5;
    verts[2].y = 0.5;
    verts[2].z = -1;

    verts[3].x = -0.5;
    verts[3].y = 0.5;
    verts[3].z = -1;


}

GLPlayer::~GLPlayer()
{
    //dtor
}
void GLPlayer::initPlayer(int x, int y, char* fileName){

    // initialize player position
    plPosition.x = 0.0;
    plPosition.y = 0.0;
    plPosition.z = -1.0;


    // initialize scale
    plScale.x = 1.0;
    plScale.y = 1.0;
    plScale.z = 1.0;

    // record number of frames
    framesX = x;
    framesY = y;

    // loading background, this will load player image
    texture->loadTexture(fileName);

    // change these values to get different spirit
    xMin = 0;
    yMin = 1.0/(float)framesY;

    xMax = 1.0/(float)framesX;
    yMax = 1;

    myTime->startTime = clock();

}

void GLPlayer::drawPlayer(){
    glTranslatef(plPosition.x, plPosition.y, plPosition.z);
    glScalef(plScale.x, plScale.y, plScale.z);

    glColor3f(1,1,1);
    texture->bindTexture();


    glBegin(GL_QUADS);

    glTexCoord2f(xMin, yMax);
    glVertex3f(verts[0].x, verts[0].y, verts[0].z);

    glTexCoord2f(xMax, yMax);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);

    glTexCoord2f(xMax, yMin);
    glVertex3f(verts[2].x, verts[2].y, verts[2].z);

    glTexCoord2f(xMin, yMin);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);

    glEnd();
}

void GLPlayer::actions(){


  if(clock() - myTime->startTime>100) {
    switch (actionTrigger) {

    case STAND:
        xMin = 0;
        xMax = 1.0/(float)framesX;
        break;

    case WALK:

            xMin += 1.0/(float)framesX;
            xMax += 1.0/(float)framesX;

        break;

    case RUN:
        break;

    case JUMP:
        break;

    case ATTACK:
        break;

    default:
        break;
    }

    myTime->startTime = clock();
 }
}
