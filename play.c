#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "const.h"
#include "snake.h"
#include "grid.h"
#include "apple.h"

void Play(SDL_Surface* screen)
{
    Uint32 bgColor;
    SDL_Event event;

    int ctn = 1;
    int ticks, timeLaps = 0;

    Snake snake;
    Apple apple;
    Entity** grid = NULL;

    bgColor = SDL_MapRGB(screen->format, 0, 0 ,0);
        
    snake = CreateSnake();
    grid = CreateGrid();
    apple = CreateApple();
    PosApple(&apple, grid);

    while (ctn)
    {
        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        ctn = 0;
                        break;
                    
                    case SDLK_w:
                    case SDLK_UP:
                        if (snake.dir != DOWN)
                            snake.dir = UP;
                        break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        if (snake.dir != LEFT)
                            snake.dir = RIGHT;
                        break;

                    case SDLK_s:
                    case SDLK_DOWN:
                        if (snake.dir != UP)
                            snake.dir = DOWN;
                        break;

                    case SDLK_a:
                    case SDLK_LEFT:
                        if (snake.dir != RIGHT)
                            snake.dir = LEFT;
                        break;

                    default:
                        break;
                }
                break;
        }
        
        ticks = SDL_GetTicks();
        
        if (ticks - timeLaps >= FPS)
        {
            MoveBody(&snake);
            UpdateGrid(grid, snake, apple);
            MoveHead(&snake);

            switch(CheckGrid(grid, snake))
            {
                case DIE:
                    ctn = 0;
                    printf("Score: %d\n", snake.length - 1);
                    SDL_Delay(1000);
                    break;

                case EAT:
                    UpgradeSnake(&snake);
                    PosApple(&apple, grid);
                    break;

                default:
                    break;
            }

            timeLaps = ticks;
        } 

        else
            SDL_Delay(FPS - (ticks - timeLaps));

        SDL_FillRect(screen, NULL, bgColor);
        PrintSnake(snake, screen);
        PrintApple(apple, screen);
        SDL_Flip(screen);
    }

    FreeSnake(&snake);
    FreeGrid(grid);
}
