#include "GLTimer.h"

GLTimer::GLTimer()
{
    // ctor
    startAt = 0;
    pauseAt = 0;
    paused = false;
    started = false;
}

GLTimer::~GLTimer()
{
    // dtor
}
bool GLTimer::isStarted()
{
    return started;
}

bool GLTimer::isStoped()
{
    return !started;
}

bool GLTimer::isSpaused()
{
    return paused;
}

void GLTimer::pause()
{
    if (paused || !started)
        return;
    paused = true;
    pauseAt = clock();
}

void GLTimer::resume()
{
    if (!paused)
        return;
    paused = false;
    startAt += clock() - pauseAt;
}

void GLTimer::start()
{
    if (started)
        return;
    started = true;
    paused = false;
    startAt = clock();
}

void GLTimer::stop()
{
    started = false;
}

void GLTimer::reset()
{
    paused = false;
    startAt = clock();
}

clock_t GLTimer::getTicks()
{
    if (!started)
        return 0;
    if (paused)
        return pauseAt - startAt;
    return clock() - startAt;
}