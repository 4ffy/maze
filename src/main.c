/**
 * @file main.c
 * @author 4ffy
 * @version 1.0.0
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022 4ffy
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "maze.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    size_t w = 0;
    size_t h = 0;
    if (argc == 3)
    {
        w = atol(argv[1]);
        h = atoi(argv[2]);
    }
    if (!w || !h)
    {
        fprintf(stderr, "Usage: %s width height\n\n", argv[0]);
        return EXIT_FAILURE;
    }

    maze_t* maze = initMaze(w, h);
    if (!maze)
    {
        fprintf(stderr, "Error: couldn't initialize maze.\n\n");
        return EXIT_FAILURE;
    }

    makeMaze(maze);
    printMaze(maze);
    printf("\n");

    freeMaze(maze);
    return EXIT_SUCCESS;
}
