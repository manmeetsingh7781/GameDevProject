#include "GLScene.h"
#include<GLLight.h>
#include<GLTexture.h>
#include<GLModel.h>
#include<GLInputs.h>
#include<GLParallax.h>
#include <GLPlayer.h>

GLInputs *KbMs       = new GLInputs();   // keyboard and Mouse

// background
GLParallax *backgroundImage      = new GLParallax(); // parallax

GLParallax *spaceShip      = new GLParallax(); // parallax


GLScene::GLScene()
{
    //ctor

    screenWidth  = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH); // for smooth render
    glClearColor(0.0f,0.0f,0.0f,0.0f); // clear background to black
    glClearDepth(2.0f);            // depth test for layers
    glEnable(GL_DEPTH_TEST);       // activate depth test
    glDepthFunc(GL_LEQUAL);         // depth function type

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);


   // glEnable(GL_BLEND);             // Transparent effect of pngs
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);  //enable textures

    // init objects here


    // init background image
    backgroundImage->parallaxInit("images/background.png");
    spaceShip->parallaxInit("images/spaceShip3.png");


    return true;
}

GLint GLScene::drawScene()    // this function runs on a loop
                              // DO NOT ABUSE ME
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// clear bits in each iteration
    glLoadIdentity();

    glScaled(3.33, 3.33, 1);

    // objects that need to update
    glPushMatrix();

    // update background
    backgroundImage->parallaxDraw(screenWidth,screenHeight);

    glPopMatrix();

    glPushMatrix();

    spaceShip->parallaxDraw(10,10);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, 1.0, 0);
    glVertex3f(1.0, 1.0, 0);
    glVertex3f(1.0, -1.0, 0);
    glVertex3f(-1.0, -1.0, 0);
    glEnd();
    glPopMatrix();

    /*// player

    glPushMatrix(); //group object
    glBegin(GL_QUADS);
    glEnable(GL_LIGHTING);


   */






    return true;
}

GLvoid GLScene::resizeScene(GLsizei width, GLsizei height){
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height; // keep track of the ratio
    glViewport(0,0,width,height); // adjusting the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspectRatio,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// key mapping - Controller
int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)   // check for inputs
    {
    case WM_KEYDOWN:
         KbMs->wParam = wParam;
         KbMs->keyBackground(backgroundImage,0.005);
         break;

    case WM_KEYUP:
         KbMs->wParam = wParam;
         KbMs->keyUP();
         break;

    case WM_LBUTTONDOWN:
         KbMs->wParam = wParam;
         // KbMs->mouseEventDown(teaPotModel,LOWORD(lParam),HIWORD(lParam));
         break;

    case WM_RBUTTONDOWN:
         KbMs->wParam = wParam;
         // KbMs->mouseEventDown(teaPotModel,LOWORD(lParam),HIWORD(lParam));
         break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KbMs->mouseEventUp();
        break;

    case WM_MOUSEMOVE:
        KbMs->wParam = wParam;
       //  KbMs->mouseMove(teaPotModel,LOWORD(lParam),HIWORD(lParam));
         break;
    case WM_MOUSEWHEEL:
        //KbMs->mouseWheel(teaPotModel, (double)GET_WHEEL_DELTA_WPARAM(wParam));
       break;
    }
}


