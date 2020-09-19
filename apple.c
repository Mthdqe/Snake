#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "const.h"

void PosApple(Apple* apple, Entity** grid)
{
    Pos pos;

    do
    {
        pos.i = rand() % GRID_HEIGHT;
        pos.j = rand() % GRID_WIDTH;
    } while (grid[pos.i][pos.j] == SNAKE);

    apple->pos = pos;
}


Apple CreateApple()
{
    Apple apple;
    
    apple.img = IMG_Load("Images/apple.png");

    return apple;
}

void FreeApple(Apple* apple)
{
    SDL_FreeSurface(apple->img);
}

void PrintApple(Apple apple, SDL_Surface* screen)
{
    SDL_Rect pos;

    pos.y = apple.pos.i * CELL_SIZE;
    pos.x = apple.pos.j * CELL_SIZE;

    SDL_BlitSurface(apple.img, NULL, screen, &pos);
}
