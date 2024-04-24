#include "GLParallax.h"

GLParallax::GLParallax()
{
    //ctor
    xMax=1.0;
    xMin=0.0;
    yMax =0.0;
    yMin = 1.0;
}

GLParallax::~GLParallax()
{
    //dtor
}

void GLParallax::parallaxInit(char* fileName)
{

    background->loadTexture(fileName); //loading my background
    myTime->startTime = clock();
}

void GLParallax::parallaxScroll(bool Auto, std::string dir, float speed)
{
    if (Auto)
    {
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
    }
}


void GLParallax::parallaxDraw(float width, float height)
{
    glColor3f(1.0,1.0,1.0); //white rectangle
    background->bindTexture();    //binding my background
    glBegin(GL_POLYGON);
        glTexCoord2f(xMin,yMin);
        glVertex3f(-width/height,-1,-8.0);

        glTexCoord2f(xMax,yMin);
        glVertex3f( width/height,-1,-8.0);

        glTexCoord2f(xMax,yMax);
        glVertex3f( width/height,1,-8.0);

        glTexCoord2f(xMin,yMax);
        glVertex3f(-width/height,1,-8.0);
    glEnd();

}
