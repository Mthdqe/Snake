#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "const.h"

Snake CreateSnake()
{
    Snake snake;
    
    snake.img[0] = IMG_Load("Images/snake_up.png");
    snake.img[1] = IMG_Load("Images/snake_right.png");
    snake.img[2] = IMG_Load("Images/snake_down.png");
    snake.img[3] = IMG_Load("Images/snake_left.png");
    snake.img[4] = IMG_Load("Images/snake_body.png");

    snake.length = 1;

    snake.pos[0].i = 0;
    snake.pos[0].j = 0;

    snake.dir = RIGHT;

    return snake;
}

void FreeSnake(Snake* snake)
{
    int i;

    for (i = 0; i < 5; i++)
        SDL_FreeSurface(snake->img[i]);
}

void PrintSnake(Snake snake, SDL_Surface* screen)
{
    int i;
    SDL_Rect pos;

    pos.y = snake.pos[0].i * CELL_SIZE;
    pos.x = snake.pos[0].j * CELL_SIZE;

    SDL_BlitSurface(snake.img[snake.dir], NULL, screen, &pos);

    for (i = 1; i < snake.length; i++)
    {
        pos.y = snake.pos[i].i * CELL_SIZE;
        pos.x = snake.pos[i].j * CELL_SIZE;

        SDL_BlitSurface(snake.img[4], NULL, screen, &pos);
    }
}

void MoveHead(Snake* snake)
{
    switch(snake->dir)
    {
        case UP:
            snake->pos[0].i -= 1;
            if (snake->pos[0].i < 0)
                snake->pos[0].i = GRID_HEIGHT - 1;
            break;

        case RIGHT:
            snake->pos[0].j += 1;
            if (snake->pos[0].j >= GRID_WIDTH)
                snake->pos[0].j = 0;
            break;

        case DOWN:
            snake->pos[0].i += 1;
            if (snake->pos[0].i >= GRID_HEIGHT)
                snake->pos[0].i = 0;
            break;

        case LEFT:
            snake->pos[0].j -= 1;
            if (snake->pos[0].j < 0)
                snake->pos[0].j = GRID_WIDTH - 1;
            break;
    }
}

void MoveBody(Snake* snake)
{
    int i;

    for (i = snake->length - 1; i > 0; i--)
        snake->pos[i] = snake->pos[i-1];
}

void UpgradeSnake(Snake* snake)
{
    if (snake->length < MAX_SNAKE_LENGTH)
    {
        snake->pos[snake->length] = snake->pos[0];
        snake->length++;
    }
}
