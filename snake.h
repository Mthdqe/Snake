#ifndef SNAKE_H
#define SNAKE_H

Snake CreateSnake();
void FreeSnake(Snake* snake);
void PrintSnake(Snake snake, SDL_Surface* screen);
void MoveHead(Snake* snake);
void MoveBody(Snake* snake);
void UpgradeSnake(Snake* snake);

#endif
