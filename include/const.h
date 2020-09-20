#ifndef CONST_H
#define CONST_H

#define W 600
#define H 600

#define CELL_SIZE 40 

#define GRID_WIDTH W / CELL_SIZE 
#define GRID_HEIGHT H / CELL_SIZE

#define FPS 100 

#define MAX_SNAKE_LENGTH 50

typedef struct Pos Pos;
struct Pos 
{
    int i;
    int j;
};

typedef enum Dir Dir;
enum Dir
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef enum Event Event;
enum Event
{
    DIE,
    EAT,
    MOVE 
};

typedef struct Snake Snake;
struct Snake
{
    SDL_Surface* img[5];
    Pos pos[MAX_SNAKE_LENGTH];
    Dir dir;
    int length;
};

typedef struct Apple Apple;
struct Apple
{
    SDL_Surface* img;
    Pos pos;
};

typedef enum Entity Entity;
enum Entity
{
    SNAKE,
    APPLE,
    NONE
};



#endif
