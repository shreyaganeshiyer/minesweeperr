
#include<stdio.h>
#include<stdlib.h>
#include "raylib.h"
#include "time.h"
#include<stdlib.h>
#include "allheader.h"

Board table;

void init_table(Board *table){
    table->mineval=1;
    table->height=12;
    table->width=12;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            table->grid[i][j]=0;
        }
    }
}
 

 // -------------------BOMB ASSISNMENT----------------------

void placeMines(Board *table){
    int count=15;
    int placed=0;
 while(placed<count){
        int r=rand()%12;
        int c=rand()%12;
        if(table->grid[r][c]>=0){
        table->grid[r][c]=-1;
        placed++;}


    }
}
int countMine(Board *table, int row, int col) {
    int freq = 0;
    for(int r = row-1; r <= row+1; r++) {
        for(int c = col-1; c <= col+1; c++) {
            if(r == row && c == col) continue;        // skip self
            if(r >= 0 && r < table->height &&
               c >= 0 && c < table->width) {
                if(table->grid[r][c]==-1) freq++;
            }
        }
    }
    return freq;
}



// int countMine(int x,int y, Board *table){
// int freq=0;
//             for(int col=x-1;col<=x+1;col++){
//                 for(int row=y-1;row<=y+1;row++){
//                     if(col==x && row==y) continue;
//                     if((col>=0 && col<12) && (row>=0 && row<12))  if(table->grid[row][col]==-1) freq++;
//             }
//     }
// return freq;
// }