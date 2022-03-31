#include "Window.h"

Window::Window(int sleep)
{
    sleep_time = sleep;
    getmaxyx(stdscr, height, width);
}

int Window::getHeight()
{
    return height;
}

int Window::getWidth()
{
    return width;
}

int Window::getSleep()
{
    return sleep_time;
}

void Window::initColorPairs()
{
    for (int i = 0; i < 8; i++)
    {
        init_pair(i+1, i, -1);
    }
}