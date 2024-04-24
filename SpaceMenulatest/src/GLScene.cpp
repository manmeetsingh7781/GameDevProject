#include <GLScene.h>
#include<GLLight.h>
#include<GLTexture.h>
#include<GLModel.h>
#include<GLInputs.h>
#include<GLParallax.h>
#include<GLPlayer.h>
#include<GLEnms.h>
#include <EnemyMonoDirection.h>
#include <StaticEnemy.h>
#include<GLTimer.h>
#include <BiDirectionalEnemy.h>
#include<GLCheckCollision.h>

#include<GLSound.h>

GLInputs *KbMs = new GLInputs(); // keyboard and Mouse

// background
GLParallax *backgroundImage = new GLParallax(); // parallax

GLTexture *enemyTex = new GLTexture();
GLTexture *monoDirectionalTex = new GLTexture();
GLTexture *directionalTex = new GLTexture();

const int ENEMYCOUNT = 20;
const int ENEMIES_ON_SCENE = 5;
StaticEnemy static_enms[ENEMYCOUNT];
EnemyMonoDirection directional_enemies[ENEMYCOUNT];
BiDirectionalEnemy bi_directional_enemies[ENEMYCOUNT];

GLCheckCollision *collision = new GLCheckCollision();

// Player Mouse movement
GLPlayer *pl = new GLPlayer();   // Player class

int mouseX = 0;
int mouseY = 0;

GLParallax *Landing = new GLParallax();
GLParallax *Menu = new GLParallax();
GLParallax *Help = new GLParallax();
GLTexture *texpb = new GLTexture();
GLTexture *texhb = new GLTexture();
GLTexture *texeb = new GLTexture();
GLTexture *texyes = new GLTexture();
GLTexture *texno = new GLTexture();
GLTexture *texexitmessage = new GLTexture();
GLSound *snds = new GLSound();

double x,y;
int flag = 1;
bool pause = false;

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

    glEnable(GL_BLEND);             // Transparent effect of pngs
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);  //enable textures

    Landing->parallaxInit("images/latestback.png");
    Menu->parallaxInit("images/menupage.png");
    Help->parallaxInit("images/helpmenu.png");

    texpb->loadTexture("images/playy.png");
    texhb->loadTexture("images/optionn.png");
    texeb->loadTexture("images/exitt.png");
    texyes -> loadTexture("images/yes1.png");
    texno -> loadTexture("images/no1.png");
    texexitmessage -> loadTexture("images/exitMessage.jpg");

    enemyTex->loadTexture("images/PNG/1.png");
    monoDirectionalTex->loadTexture("images/PNG/18.png");
    //directionalTex->loadTexture("images/PNG/34.png");

    glEnable(GL_BLEND); // Transparent effect of pngs
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D); // enable textures

    // init objects here

    // init background image
    backgroundImage->parallaxInit("images/back.jpeg");

    // player init
    pl->initPlayer(1,4,"images/player.png");

    snds->initSounds();
    snds->playMusic("Sounds/mp.mp3");

    // enemies init
    for (int i = 0; i < ENEMYCOUNT; i++)
    {
        static_enms[i].initEnemy(enemyTex->tex);
        static_enms[i].placeEnemy((float)(rand() / float(RAND_MAX)) * i - 2.5, ((float)(rand() / float(RAND_MAX)) * -2.5 ) / 2.5, -2.5);
        static_enms[i].xSize = static_enms[i].ySize = float(0.05);


        directional_enemies[i].initEnemy(enemyTex->tex);
        directional_enemies[i].placeEnemy((float)(rand() / float(RAND_MAX)) * i - 2.5, ((float)(rand() / float(RAND_MAX)) * +2.5 ) / 2.5, -2.5);
        directional_enemies[i].xSize = directional_enemies[i].ySize = float(0.05);
        // set random value for x or y axis
        directional_enemies[i].setAxis(rand() % 2);

        bi_directional_enemies[i].initEnemy(enemyTex->tex);
        bi_directional_enemies[i].placeEnemy((float)(rand() / float(RAND_MAX)) * i - 2.5, ((float)(rand() / float(RAND_MAX)) * -2.5 ) / 2.5, -2.5);
        bi_directional_enemies[i].xSize = bi_directional_enemies[i].ySize = float(0.05);
    }
    return true;
}

GLint GLScene::drawScene()    // this function runs on a loop
                              // DO NOT ABUSE ME
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// clear bits in each itterration
   glLoadIdentity();

    POINT mousePos;
    GetCursorPos(&mousePos);
    x = mousePos.x;
    y = mousePos.y;

    if (flag == 1){
        glPushMatrix();
            glScalef(3.33,3.33,1.0);
            Landing->parallaxDraw(screenWidth,screenHeight);
        glPopMatrix();
    }else if(flag == 2){

        glPushMatrix();
            glScalef(3.33,3.33,1.0);
            Menu->parallaxDraw(screenWidth,screenHeight);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,0,-6);
        texpb->bindTexture();
        glBegin(GL_QUADS);
            glTexCoord2f(0,0); glVertex2f(-0.5, 0.2);
            glTexCoord2f(1,0); glVertex2f(0.5, 0.2);
            glTexCoord2f(1,1); glVertex2f(0.5, -0.2);
            glTexCoord2f(0,1); glVertex2f(-0.5, -0.2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,-0.5,-6);
        texhb->bindTexture();
        glBegin(GL_QUADS);
            glTexCoord2f(0,0); glVertex2f(-0.5, 0.2);
            glTexCoord2f(1,0); glVertex2f(0.5, 0.2);
            glTexCoord2f(1,1); glVertex2f(0.5, -0.2);
            glTexCoord2f(0,1); glVertex2f(-0.5, -0.2);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,-1,-6);
        texeb->bindTexture();
        glBegin(GL_QUADS);
            glTexCoord2f(0,0); glVertex2f(-0.5, 0.2);
            glTexCoord2f(1,0); glVertex2f(0.5, 0.2);
            glTexCoord2f(1,1); glVertex2f(0.5, -0.2);
            glTexCoord2f(0,1); glVertex2f(-0.5, -0.2);
        glEnd();
        glPopMatrix();

    } else if(flag == 3){
        glPushMatrix();
            glScaled(3.33, 3.33, 1.0);
            backgroundImage->parallaxDraw(screenWidth, screenHeight);
        glPopMatrix();
        //Play->parallaxDraw(screenWidth,screenHeight);
        // update background
        if(pause == true){
            glPushMatrix();
            glTranslatef(0,0.5,-6);
            texexitmessage->bindTexture();
            glBegin(GL_QUADS);
                glTexCoord2f(0,0); glVertex2f(-0.9, 0.2);
                glTexCoord2f(1,0); glVertex2f(0.9, 0.2);
                glTexCoord2f(1,1); glVertex2f(0.9, -0.2);
                glTexCoord2f(0,1); glVertex2f(-0.9, -0.2);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0,0,-6);
            texyes->bindTexture();
            glBegin(GL_QUADS);
                glTexCoord2f(0,0); glVertex2f(-0.5, 0.2);
                glTexCoord2f(1,0); glVertex2f(0.5, 0.2);
                glTexCoord2f(1,1); glVertex2f(0.5, -0.2);
                glTexCoord2f(0,1); glVertex2f(-0.5, -0.2);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0,-0.5,-6);
            texno->bindTexture();
            glBegin(GL_QUADS);
                glTexCoord2f(0,0); glVertex2f(-0.5, 0.2);
                glTexCoord2f(1,0); glVertex2f(0.5, 0.2);
                glTexCoord2f(1,1); glVertex2f(0.5, -0.2);
                glTexCoord2f(0,1); glVertex2f(-0.5, -0.2);
            glEnd();
            glPopMatrix();
        }

        else{
        // bind the enemy to screen
        glPushMatrix();
        enemyTex->bindTexture();
        glPopMatrix();

       // directionalTex->bindTexture();

        for (int i = 0; i < ENEMYCOUNT; i++)
        {
            string enemy_type[3] = {"Static", "MonoDirectional", "BiDirectional"};
            int random_index = rand() % 3;
            string random_enemy_type = enemy_type[random_index];

            // not moving enemy
            if (random_enemy_type == "Static")
            {



                // place enemy at random position
                static_enms[i].action = static_enms[i].STATIC;


            }
            else if (random_enemy_type == "MonoDirectional")
            {



                // moves either x or y axis
                directional_enemies[i].updateEnemyMove();


            }
            else
            {

                bi_directional_enemies[i].updateEnemyMove();


            }

            bool isCollided = collision->isRadialCollision(pl->plPosition, static_enms[i].enmPos,  static_enms[i].xSize,  static_enms[i].ySize, 0.2);
            bool isCollided1 = collision->isRadialCollision(pl->plPosition, bi_directional_enemies[i].enmPos,  bi_directional_enemies[i].xSize,  bi_directional_enemies[i].ySize, 0.2);
            bool isCollided2 = collision->isRadialCollision(pl->plPosition, directional_enemies[i].enmPos,  directional_enemies[i].xSize,  directional_enemies[i].ySize, 0.2);

           if(isCollided || isCollided1 || isCollided2)  {
            cout << "Collided" << endl;
           }

         static_enms[i].actions();
         bi_directional_enemies[i].actions();
         directional_enemies[i].actions();
        }

        // bind player
        pl->drawPlayer(mouseX, mouseY, screenWidth, screenHeight);
        }

    }else if(flag == 4){
        glPushMatrix();
            glScalef(3.33,3.33,1.0);
            Help->parallaxDraw(screenWidth,screenHeight);
        glPopMatrix();
    }

   return true;
}

GLvoid GLScene::resizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height; // keep track of the ratio
    glViewport(0,0,width,height); // adjusting the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspectRatio,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)   // check for inputs
    {
    case WM_KEYDOWN:
        KbMs->wParam = wParam;
        KbMs->keyBackground(backgroundImage, 0.005);
        switch(wParam){
        case 'P':
            if(flag == 2){
                flag = 3;
            }
            break;

        case 'O':
            if(flag == 2){
               flag = 4;
            }
            break;

        case 'E':
            if(flag == 2){
                exit(0);
            }
            break;

        case VK_ESCAPE:
            if(flag == 3 && pause == false){
                pause = true;
            }else if(flag == 3 && pause == true){
                pause = false;
            }else if(flag == 4){
                flag = 2;
            }
            break;

        case VK_RETURN:
            if(flag == 1){
                flag = 2;
            }else if(flag == 3 && pause == true){
                flag = 2;
            }
        }
        break;

    case WM_KEYUP:
        KbMs->wParam = wParam;
        KbMs->keyUP();
        break;

    case WM_LBUTTONDOWN:
        KbMs->wParam = wParam;
            // KbMs->mouseEventDown(teaPotModel,LOWORD(lParam),HIWORD(lParam));
        if(flag == 2){
            if(x <= 870 && x >= 690 && y <= 480 && y >= 410){
                flag = 3;
            }else if(x <= 870 && x >= 690  && y <= 565 && y >= 495){
                flag = 4;
            }else if(x <= 870 && x >= 690 && y <= 655 && y >= 585){
                exit(0);
            }
        }else if(flag == 1){
            flag = 2;
        }else if(flag == 3 && pause == true){
            if(x <= 870 && x >= 690 && y <= 480 && y >= 410){
                flag = 2;
                pause = false;
            }else if(x <= 870 && x >= 690  && y <= 565 && y >= 495){
                pause = false;
            }
        }
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
        if(pause == false){
            KbMs->wParam = wParam;
            mouseX = LOWORD(lParam);
            mouseY = HIWORD(lParam);
            UpdateBackgroundMovement(hWnd); // Pass hWnd to the function
        }
        break;

    case WM_MOUSEWHEEL:
        // KbMs->mouseWheel(teaPotModel, (double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;
    }
}

void GLScene::UpdateBackgroundMovement(HWND hWnd) {
    POINT mousePos;
    GetCursorPos(&mousePos);
    ScreenToClient(hWnd, &mousePos);
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    int deltaX = mousePos.x - centerX;
    int deltaY = mousePos.y - centerY;
    float speed = 0.000001f * sqrt(deltaX * deltaX + deltaY * deltaY);
    std::string dir;
    if (deltaX > 0)
        dir += "right";
    else if (deltaX < 0)
        dir += "left";
    if (deltaY > 0)
        dir += "down";
    else if (deltaY < 0)
        dir += "up";

    if(pause == true){
        backgroundImage->parallaxScroll(false, dir, speed);
    }else{
        backgroundImage->parallaxScroll(true, dir, speed);
    }
}
