#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "const.h"
#include "grid.h"
#include "apple.h"
#include "snake.h"

Entity** CreateGrid()
{
    int i, j;
    Entity** grid = NULL;

    grid = malloc( sizeof(Entity*) * GRID_HEIGHT);

    for (i = 0; i < GRID_HEIGHT; i++)
    {
        grid[i] = malloc( sizeof(Entity) * GRID_WIDTH);
        for (j = 0; j < GRID_WIDTH; j++)
            grid[i][j] = NONE;
    }
    
    return grid;    
}

void FreeGrid(Entity** grid)
{
    int i;

    for (i = 0; i < GRID_HEIGHT; i++)
        free(grid[i]);

    free(grid);
}

void UpdateGrid(Entity** grid, Snake snake, Apple apple)
{
    int i, j;

    for (i = 0; i < GRID_HEIGHT; i++)
    {
        for (j = 0; j < GRID_WIDTH; j++)
            grid[i][j] = NONE;
    }

    for (i = 0; i < snake.length; i++)
        grid[snake.pos[i].i][snake.pos[i].j] = SNAKE;

    grid[apple.pos.i][apple.pos.j] = APPLE;
}

Event CheckGrid(Entity** grid, Snake snake)
{
    Event event;
    
    switch(grid[snake.pos[0].i][snake.pos[0].j])
    {
        case SNAKE:
            event = DIE;
            break;

        case APPLE:
            event = EAT;
            break;

        default:
            event = MOVE;
            break;
    }

    return event;
}

    
