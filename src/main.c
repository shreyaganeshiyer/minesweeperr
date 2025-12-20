#include "raylib.h"
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
int size = 12;

int main(){
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Minesweeper");
    SetTargetFPS(60);
    return 0;
}


