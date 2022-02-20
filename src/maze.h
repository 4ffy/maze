/**
 * @file maze.h
 * @author Cameron Norton (cameron.norton@gmail.com)
 * @brief Depth-first maze generation algorithms.
 * @version 1.0
 * @date 2022-02-17
 * @copyright Copyright (c) 2022 Cameron Norton
 * 
 */

#include <stdlib.h>

#ifndef MAZE_H
#define MAZE_H

#define VISIT_FLAG 1 /**< Flag if cell has been visited. */
#define NORTH_FLAG 2 /**< Flag if cell has a passage to the north. */
#define WEST_FLAG  4 /**< Flag if cell has a passage to the west. */



typedef struct maze maze_t;
struct maze {
    size_t** data; /**< Array of cells. */
    size_t width;  /**< Width of array. */
    size_t height; /**< Height of array. */
};



/**
 * @brief Shuffle a list of integers in-place.
 * 
 * @param length    The length of the list to be sorted.
 * @param list      Pointer to a list of integers.
 */
void shuffle(size_t length, int* list);



/**
 * @brief Allocate memory for a maze.
 * 
 * @param width       Width of the maze in cells.
 * @param height      Height of the maze in cells.
 * @return maze_t*    Pointer to the initialized maze, or NULL if
 *                    initialization fails.
 */
maze_t* initMaze(size_t width, size_t height);



/**
 * @brief Free a maze from memory.
 * 
 * @param maze Pointer to the maze to be freed.
 */
void freeMaze(maze_t* maze);



/**
 * @brief Perform a random depth-first walk from a starting position.
 *
 * Given a cell, this algorithm marks the cell as visited. Then, for each of
 * the 4 cardinal directions (in a random order) it checks whether the
 * neighboring cell has been visited. If not, we connect the two cells and
 * call walk() on the neighboring cell. Repeat until the maze is filled.xxx
 *
 * @param x       x position of the working cell.
 * @param y       y position of the working cell.
 * @param maze    The maze being generated..
 */
void walk(size_t x, size_t y, maze_t* maze);



/**
 * @brief Choose a random starting point and generate a maze.
 * 
 * @param maze The maze to be generated.
 */
void makeMaze(maze_t* maze);



/**
 * @brief Clear a maze to its default state.
 * 
 * @param maze   The maze to be cleared.
 */
void clearMaze(maze_t* maze);



/**
 * @brief Print a maze to stdout.
 * 
 * @param maze    The maze to be printed.
 */
void printMaze(maze_t* maze);



/**
 * @brief Print the values of the maze array as integers, for debugging.
 * 
 * @param maze    The maze to be printed.
 */
void printDebug(maze_t* maze);

#endif