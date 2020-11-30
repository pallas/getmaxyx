/*
 * getmaxy - find the maximum dimensions of a terminal
 * SPDX-License-Identifier: MIT
 * Author: Derrick Pallas
 *
 */
#include <ncurses.h>

#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
    WINDOW *w = initscr();
    int max =
#if defined(MAX_Y) && defined(MAX_X)
# error "Both MAX_Y and MAX_X defined!"
#elif defined(MAX_Y)
    getmaxy(w)
#elif defined(MAX_X)
    getmaxx(w)
#else
# error "Neither MAX_Y nor MAX_X defined!"
#endif
    ;
    if (OK != endwin())
        exit(EXIT_FAILURE);

    printf("%d\n", max);
    return EXIT_SUCCESS;
}
//
