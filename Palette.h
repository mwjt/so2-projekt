#ifndef PALETTE_H
#define PALETTE_H

#include <ncurses.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <iostream>

class Palette
{
private:
    int x;
    int y;
    int bottom, top;
    int left, right;
    int width;
    int height;
    int speed_y;
    int direction;

public:
    Palette();

    bool checkIfHit(int, int);
    void movePalette(int, int);
    void paletteLoop(int, int);
    void printPalette();
    int getLeft();
    int getRight();
    int getTop();
    int getBottom();
};


#endif