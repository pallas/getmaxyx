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
    if (!newterm(getenv("TERM"), stdin, stderr))
        exit(EXIT_FAILURE);

    int max =
#if defined(MAX_Y) && defined(MAX_X)
# error "Both MAX_Y and MAX_X defined!"
#elif defined(MAX_Y)
    getmaxy(stdscr)
#elif defined(MAX_X)
    getmaxx(stdscr)
#else
# error "Neither MAX_Y nor MAX_X defined!"
#endif
    ;

    fprintf(stdout, "%d\n", max);

    if (OK != endwin())
        exit(EXIT_FAILURE);

    return EXIT_SUCCESS;
}
//
