#ifndef ASSETS_H
#define ASSETS_H

#include "allheader.h"

extern Image flagi;
extern Image minei;

extern Texture2D Mine;
extern Texture2D Flag;

extern Sound Click;
extern Sound Blast;

extern Music GameMusic;

//-------------- main.c Required Variabless------------------------
extern bool isSoundEnabled;
extern bool isMusicEnabled;

extern Vector2 click;
extern int value,number; 
extern int pixrow,pixcol;
extern bool flagarr[12][12];  // store flags
extern bool highlight[12][12];

typedef struct{
    int grid[12][12];           
    int mineval;
    int height;
    int width;
}Board;

typedef enum{
    menu, //0
    opt,  //1
    playin, //2
}GameState;

extern Board table;
extern GameState PlayerState;


void init_table(Board *table);
void placeMines(Board *table);
int countMine(Board *table,int x,int y);


void UpdateDrawMenu();
void UpdateDrawOption();
void UpdateDrawPlay();


void UnloadGameAssets();

#endif
