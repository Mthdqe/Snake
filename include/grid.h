#ifndef GRID_H
#define GRID_H

Entity** CreateGrid();
void FreeGrid(Entity** grid);
void UpdateGrid(Entity** grid, Snake snake, Apple apple);
Event CheckGrid(Entity** grid, Snake snake);

#endif
