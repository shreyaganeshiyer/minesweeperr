#ifndef DSA_LOGIC_H
#define DSA_LOGIC_H

#include <stdbool.h>

#define N 12


// BFS function to reveal tiles
void bfsReveal(Board *board, bool isRevealed[N][N], int startRow, int startCol);

#endif
