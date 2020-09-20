#ifndef APPLE_H
#define APPLE_H

void PosApple(Apple* apple, Entity** grid);
Apple CreateApple();
void FreeApple(Apple* apple);
void PrintApple(Apple apple, SDL_Surface* screen);

#endif
