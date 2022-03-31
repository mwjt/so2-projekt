#ifndef BALL_H
#define BALL_H

#include "Palette.h"

#include <ncurses.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <iostream>

class Ball
{
private:
    double x;
    double y;
    double speed_x;
    double speed_y;
    int hitcount;
    int color;
    std::thread::id thread_id;

public:
    Ball();

    void moveBall(int, int, Palette);
    void ballLoop(Palette);
    double getX();
    double getY();
    void printBall();
    void horizontalBounce();
    void verticalBounce();
};


#endif