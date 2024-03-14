#include "GLScene.h"
#include<GLLight.h>
#include<GLTexture.h>
#include<GLModel.h>
#include<GLInputs.h>
#include<GLParallax.h>
#include <GLPlayer.h>
#include<GLEnms.h>
#include <EnemyMonoDirection.h>
#include <StaticEnemy.h>
#include <BiDirectionalEnemy.h>

GLInputs *KbMs       = new GLInputs();   // keyboard and Mouse

// background
GLParallax *backgroundImage      = new GLParallax(); // parallax

GLTexture *enmsTex = new GLTexture();
StaticEnemy static_enms[20];
EnemyMonoDirection directional_enemies[20];
BiDirectionalEnemy bi_directional_enemies[20];


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

    enmsTex->loadTexture("images/monster.png");


    glEnable(GL_BLEND);             // Transparent effect of pngs
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);  //enable textures

    // init objects here


    // init background image
    backgroundImage->parallaxInit("images/background.png");

    for (int i=0; i<20;i++)
    {
        static_enms[i].initEnemy(enmsTex->tex);
        static_enms[i].placeEnemy((float)(rand()/float(RAND_MAX))*5-2.5,-0.2, -2.5);
        static_enms[i].xSize= static_enms[i].ySize = float(rand()%12)/85.0;

        directional_enemies[i].initEnemy(enmsTex->tex);
        directional_enemies[i].placeEnemy((float)(rand()/float(RAND_MAX))*5-2.5,-0.2, -2.5);
        directional_enemies[i].xSize= directional_enemies[i].ySize = float(rand()%12)/85.0;
        // set random value for x or y axis
        directional_enemies[i].setAxis(rand() % 2);



        bi_directional_enemies[i].initEnemy(enmsTex->tex);
        bi_directional_enemies[i].placeEnemy((float)(rand()/float(RAND_MAX))*5-2.5,-0.2, -2.5);
        bi_directional_enemies[i].xSize= bi_directional_enemies[i].ySize = float(rand()%12)/85.0;



    }

    return true;
}

GLint GLScene::drawScene()    // this function runs on a loop
                              // DO NOT ABUSE ME
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// clear bits in each itterration
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);     //color the object red

    glPushMatrix(); //group object

    glScaled(3.33,3.33,1.0);
    glDisable(GL_LIGHTING);

    // objects that need to update

    // update background
    backgroundImage->parallaxDraw(screenWidth,screenHeight);

    // bind the enemy to screen
    enmsTex->bindTexture();

   for(int i =0; i<20 ; i++){
        string enemy_type[3] = {"Static", "MonoDirectional", "BiDirectional"};
        int random_index = rand() % 3;
        string random_enemy_type = enemy_type[random_index];

        // not moving enemy
        if (random_enemy_type == "Static") {
            // place enemy at random position
            static_enms[i].action = static_enms[i].STATIC;
        }else if (random_enemy_type == "MonoDirectional"){
            // moves either x or y axis
            directional_enemies[i].updateEnemyMove();
        }
        else {
            bi_directional_enemies[i].updateEnemyMove();
        }
            static_enms[i].actions();
            directional_enemies[i].actions();
            bi_directional_enemies[i].actions();

        }


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


