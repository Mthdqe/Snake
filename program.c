#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
              
#include "const.h"
#include "play.h"

int main()
{
    SDL_Surface* screen = NULL;
    SDL_Surface* menu = NULL;
    SDL_Rect menuPos;
    SDL_Event event;
    int leave = 0;
    time_t t;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    screen = SDL_SetVideoMode(W, H, 32, SDL_HWSURFACE); 
    menu = IMG_Load("Images/menu.png");
    
    srand((unsigned) time(&t));

    while (!leave)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                        Play(screen);
                        break;
                    
                    case SDLK_2:
                        leave = 1;
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
        
        menuPos.x = -110;
        menuPos.y = 0;

        SDL_BlitSurface(menu, NULL, screen, &menuPos);
        SDL_Flip(screen);
    }
    
    SDL_FreeSurface(screen); 
    SDL_FreeSurface(menu);
    
    SDL_Quit();

    return 0;
}
