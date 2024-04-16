#ifndef GLENMS_H
#define GLENMS_H

#include <GLTexture.h>
#include <GL/gl.h>
#include <GLTimer.h>

class GLEnms
{
public:
    GLEnms();
    virtual ~GLEnms();

    void drawEnemy();                     // Draw Objects
    void placeEnemy(float, float, float); // Place Enemy
    void initEnemy(GLuint);
    enum
    {
        STATIC,
        MOVE_AXIS,
        MOVE_DIRECTIONAL
    };
    void actions(); // Movements and actions

    bool isEnemyLive; // Status of the Enemy
    GLuint EnemyTex;  // Handle Texture

    vec3 enmPos;
    //vec3 xPos, yPos, zPos; // Placement
    float xSize, ySize;     // Scaling Factor

    float rotateX, rotateY, rotateZ; // rotations

    int frames;  // number of frames
    float xMove; // moving speed on x axis
    float yMove; // moving speed on y axis
    int action;  // to make an action for enemy

    GLTimer *TE = new GLTimer();
 float xMin, yMin, xMax, yMax;
protected:
private:

};

#endif // GLENMS_H
