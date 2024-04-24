#ifndef GLSOUND_H
#define GLSOUND_H

#include<SNDS/irrKlang.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
using namespace irrklang;


class GLSound
{
    public:
        GLSound();
        virtual ~GLSound();

        ISoundEngine *engine = createIrrKlangDevice();

        void playMusic(char *);
        void playSound(char *);
        void pauseSound(char *);
        int initSounds();

    protected:

    private:
};

#endif // GLSOUND_H
