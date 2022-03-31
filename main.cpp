#include "Ball.h"
#include "Palette.h"
#include "Window.h"
#include "LinkedList.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

//std::vector<Ball *> balls;
std::vector<std::thread> threads;
LinkedList balls;
Palette *palette;
bool running;

void handleBall()
{
    Ball *ball = new Ball();
    balls.add(ball);
    ball->ballLoop(*palette);
    balls.remove(ball);
}

void handlePalette()
{
    int x_limit, y_limit;
    getmaxyx(stdscr, y_limit, x_limit);

    while(running) {
        palette->paletteLoop(x_limit, y_limit);
    }
    free(palette);
}

void printLocation(Window w)
{
    while (getch() != 'q')
    {
        erase();
        printw("Q to quit");
        palette->printPalette();
        for (int i = 0; i < balls.length; i++)
            balls.get(i)->printBall();
        //usleep(w.getSleep());

        std::this_thread::sleep_for(std::chrono::milliseconds(w.getSleep()));
    }
    running = false;
}

void do_join(std::thread& t)
{
    t.join();
}

int main()
{
    running = true;
    initscr();
    nodelay(stdscr, TRUE);
    cbreak();
    curs_set(FALSE);
    start_color();
    use_default_colors();
    noecho();

    Window w = Window(20);
    w.initColorPairs();

    palette = new Palette();

    srand(time(NULL));

    threads.push_back(std::thread(printLocation, w));
    threads.push_back(std::thread(handlePalette));


    int latency;
    while(running)
    {
        threads.push_back(std::thread(handleBall));
        latency = rand() % 100 + 50;
        std::this_thread::sleep_for(std::chrono::milliseconds(latency));
    }

    erase();
    printw("Waiting for remaining threads...");
    refresh();

    std::for_each(threads.begin(), threads.end(), do_join);

    nodelay(stdscr, FALSE);
    nocbreak();
    endwin();
}