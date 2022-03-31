#include "Ball.h"

Ball::Ball()
{
    x = getmaxx(stdscr) / 2;
    y = getmaxy(stdscr) - 1;
    hitcount = 0;
    speed_x = (rand() % 3) - 1;
    speed_y = (double) (rand() % 1000 / 1000.0 + 1.0) * -1.0;
    color = (rand() % 7) + 2;
    thread_id = std::this_thread::get_id();
}

void Ball::moveBall(int x_limit, int y_limit, Palette palette)
{
    x += speed_x;
    y += speed_y;

    if (x <= 0 || x >= x_limit)
    {
        verticalBounce();
        return;
    }

    if (y <= 0 || y >= y_limit)
    {
        horizontalBounce();
        return;
    }
}

void Ball::horizontalBounce()
{
    speed_y *= -1;
    y += speed_y;
    hitcount++;
}

void Ball::verticalBounce()
{
    speed_x *= -1;
    x += speed_x;
    hitcount++;
}

void Ball::ballLoop(Palette palette)
{
    int x_limit, y_limit;
    getmaxyx(stdscr, y_limit, x_limit);

    while (hitcount < 5)
    {
        moveBall(x_limit, y_limit, palette);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

double Ball::getX()
{
    return x;
}

double Ball::getY()
{
    return y;
}

void Ball::printBall()
{
    attron(COLOR_PAIR(color));
    mvprintw(y, x, "o");
    attroff(COLOR_PAIR(color));
    move(0, 0);
}

