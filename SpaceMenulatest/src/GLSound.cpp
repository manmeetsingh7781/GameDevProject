#include "GLSound.h"

GLSound::GLSound()
{
    //ctor
}

GLSound::~GLSound()
{
    //dtor
    engine->drop();
}
void GLSound::playMusic(char* File)
{
    engine->play2D(File,true);
}

void GLSound::playSound(char*File)
{
    engine->play2D(File,false,false);
}

void GLSound::pauseSound(char* File)
{
     if (!engine->isCurrentlyPlaying(File))
     engine->play2D(File,true,false);
}

int GLSound::initSounds()
{
    if(!engine){cout<<"The Sound Engine did not startup\n";
       return 0;
    }
}
