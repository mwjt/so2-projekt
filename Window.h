#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

class Window
{
private:
    int width;
    int height;
    int sleep_time;
public:
    Window(int);
    int getWidth();
    int getHeight();
    int getSleep();
    void initColorPairs();
};

#endif