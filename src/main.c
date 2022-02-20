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
