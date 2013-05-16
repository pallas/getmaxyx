/*
 * getmaxy - find the maximum dimensions of a terminal
 * Author: Derrick Pallas
 *
 */
#include <ncurses.h>

#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
    WINDOW *w = initscr();
    int maxY, maxX;
    getmaxyx(w, maxY, maxX);
    if (OK != endwin())
        exit(EXIT_FAILURE);

printf("%d\n",
#if defined(MAX_Y) && defined(MAX_X)
# error "Both MAX_Y and MAX_X defined!"
    -1
#elif defined(MAX_Y)
    maxY
#elif defined(MAX_X)
    maxX
#else
# error "Neither MAX_Y nor MAX_X defined!"
    -1
#endif
    );

    return EXIT_SUCCESS;
}
//
