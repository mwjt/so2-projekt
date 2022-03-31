#include "Palette.h"

Palette::Palette()
{
    width = getmaxx(stdscr) / 6;
    height = getmaxy(stdscr) / 3;
    x = getmaxx(stdscr) / 4;
    y = getmaxy(stdscr) / 2;
    direction = 1;
    speed_y = ((rand() % 5) + 1.0 ) * direction;

    left = x - width/2;
    right = x + width/2;
}

void Palette::paletteLoop(int x_limit, int y_limit)
{
    movePalette(x_limit, y_limit);
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}

void Palette::movePalette(int x_limit, int y_limit)
{
    y += speed_y;

    bottom = y - (height / 2);
    top = y + (height / 2);

    if (bottom < 0 || top > y_limit)
    {
        y -= speed_y;
        direction *= -1;
        speed_y = ((rand() % 5) + 1.0 ) * direction;
    }
}



void Palette::printPalette()
{
    mvhline(bottom, left, '-', width);
    mvhline(top, left, '-', width);
    mvvline(bottom, left, '|', height);
    mvvline(bottom, right, '|', height);
    move(0, 0);
}

int Palette::getLeft()
{
    return left;
}

int Palette::getRight()
{
    return right;
}

int Palette::getTop()
{
    return top;
}

int Palette::getBottom()
{
    return bottom;
}
