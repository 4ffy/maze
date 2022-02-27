/**
 * @file maze.c
 * @author 4ffy
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
#include <wchar.h>
#include "maze.h"



void shuffle(size_t length, int* list)
{
    int temp;
    int j;

    for (int i = length - 1; i >= 1; i--)
    {
        j = rand() % (i + 1);
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}


maze_t* initMaze(size_t width, size_t height)
{
    maze_t* maze = malloc(sizeof(maze_t));
    if (!maze) return NULL;

    maze->width = width;
    maze->height = height;

    maze->data = malloc(maze->width * sizeof(size_t*));
    if (!maze->data)
    {
        free(maze);
        return NULL;
    }

    for (size_t i = 0; i < maze->width; i++)
    {
        maze->data[i] = malloc(maze->height * sizeof(size_t));
        if (!maze->data[i])
        {
            for (size_t j = 0; j < i; j++)
                free(maze->data[i]);
            free(maze->data);
            free(maze);
            return NULL;
        }
    }

    clearMaze(maze);
    return maze;
}



void freeMaze(maze_t* maze)
{
    if (!maze) return;

    for (size_t i = 0; i < maze->width; i++)
        free(maze->data[i]);
    free(maze->data);

    free(maze);
}



void clearMaze(maze_t* maze)
{
    for (size_t i = 0; i < maze->width; i++)
    {
        for (size_t j = 0; j < maze->height; j++)
            maze->data[i][j] = 0;
    }
}



void walk(size_t x, size_t y, maze_t* maze)
{
    maze->data[x][y] |= VISIT_FLAG;

    int dirs[] = {0, 1, 2, 3};
    shuffle(4, dirs);

    for (int i = 0; i < 4; i++)
    {
        switch (dirs[i])
        {
            case 0:
            if (y > 0 && !(maze->data[x][y-1]))
            {
                maze->data[x][y] |= NORTH_FLAG;
                walk(x, y-1, maze);
            }
            break;

            case 1:
            if (y + 1 < maze->height && !(maze->data[x][y+1]))
            {
                maze->data[x][y+1] |= NORTH_FLAG;
                walk(x, y+1, maze);
            }
            break;

            case 2:
            if (x > 0 && !(maze->data[x-1][y]))
            {
                maze->data[x][y] |= WEST_FLAG;
                walk(x-1, y, maze);
            }
            break;

            case 3:
            if (x + 1 < maze->width && !(maze->data[x+1][y]))
            {
                maze->data[x+1][y] |= WEST_FLAG;
                walk(x+1, y, maze);
            }
            break;
        }
    }
}



void makeMaze(maze_t* maze)
{
    clearMaze(maze);
    size_t x = rand() % maze->width;
    size_t y = rand() % maze->height;
    walk(x, y, maze);
}



void printMaze(maze_t* maze)
{
    for (size_t j = 0; j < maze->height; j++)
    {
        for (size_t i = 0; i < maze->width; i++)
            maze->data[i][j] & NORTH_FLAG ? wprintf(L"██  ") : wprintf(L"████");
        wprintf(L"██\n");

        for (size_t i = 0; i < maze->width; i++)
        {
            maze->data[i][j] & WEST_FLAG ? wprintf(L"  ") : wprintf(L"██");
            wprintf(L"  ");
        }
        wprintf(L"██\n");
    }
    for (size_t i = 0; i < maze->width; i++)
        wprintf(L"████");
    wprintf(L"██\n");
}



void printDebug(maze_t * maze)
{
    for (size_t j = 0; j < maze->height; j++)
    {
        for (size_t i = 0; i < maze->width; i++)
            printf("%zu\t", maze->data[i][j]);
        printf("\n");
    }
}