#ifndef GLTIMER_H
#define GLTIMER_H

#include<common.h>

class GLTimer
{
    public:
        GLTimer();
        virtual ~GLTimer();

        //clock_t startTime;
        clock_t startAt;
        clock_t pauseAt;

        bool started;
        bool paused;

        bool isStarted();
        bool isStoped();
        bool isSpaused();

        void pause();
        void resume();
        void start();
        void stop();
        void reset();

        clock_t getTicks();

    protected:

    private:
};

#endif // GLTIMER_H
