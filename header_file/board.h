#ifndef BOARD_H
#define BOARD_H

#include "allheader.h"
typedef struct{
    int grid[12][12];           
    int mineval;
    int height;
    int width;
}Board;

extern Board table;

void init_table(Board *table);
void placeMines(Board *table);
int countMine(Board *table,int x,int y);

#endif