#include "GLParallax.h"

GLParallax::GLParallax()
{
    // ctor
    xMax = 1.0;
    xMin = 0.0;
    yMax = 0.0;
    yMin = 1.0;
}

GLParallax::~GLParallax()
{
    // dtor
}

void GLParallax::parallaxInit(char *fileName)
{

    background->loadTexture(fileName); // loading my background
    myTime->startAt = clock();
}


void GLParallax::parallaxScroll(bool Auto, std::string dir, float speed)
{
    if (Auto)
    {
        //if(clock() - myTime->start>15)
        //{

        if (dir.find("up") != std::string::npos)
        {

            yMin -= speed;
            yMax -= speed;
        }
        if (dir.find("down") != std::string::npos)
        {

            yMin += speed;
            yMax += speed;
        }
        if (dir.find("left") != std::string::npos)
        {

            xMin -= speed;
            xMax -= speed;
        }
        if (dir.find("right") != std::string::npos)
        {

            xMin += speed;
            xMax += speed;
        }

        //myTime->startTime =clock();
        //}
    }
}

/*
OLDER VERSION - ENEMIES - Manmeet Singh
void GLParallax::parallaxScroll(bool Auto, string dir, float speed)
{
    if (Auto)
    {
        // if(clock() - myTime->start>15)
        //{

        if (dir == "up")
        {
            yMin -= speed;
            yMax -= speed;
        }
        if (dir == "down")
        {
            yMin += speed;
            yMax += speed;
        }
        if (dir == "left")
        {
            xMin -= speed;
            xMax -= speed;
        }
        if (dir == "right")
        {
            xMin += speed;
            xMax += speed;
        }

        // myTime->startTime =clock();
        // }
    }
}
*/
void GLParallax::parallaxDraw(float width, float height)
{
    glColor3f(1.0, 1.0, 1.0);  // white rectangle
    background->bindTexture(); // binding my background
    glBegin(GL_POLYGON);
    glTexCoord2f(xMin, yMin);
    glVertex3f(-width / height, -1, -8.0);

    glTexCoord2f(xMax, yMin);
    glVertex3f(width / height, -1, -8.0);

    glTexCoord2f(xMax, yMax);
    glVertex3f(width / height, 1, -8.0);

    glTexCoord2f(xMin, yMax);
    glVertex3f(-width / height, 1, -8.0);
    glEnd();
}
