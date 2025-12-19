#include "raylib.h"
#include<stdlib.h>

int size=12;

int main(){
InitWindow(50*12,50*12,"Easylevel");

while(!WindowShouldClose()){

    BeginDrawing();
    ClearBackground(RAYWHITE);

for(int ver=0;ver<12;ver++){
    for(int i=0;i<12;i++){
        DrawRectangle(i*50,ver*50,48,48,BLUE);
    }
}

    EndDrawing();
}


CloseWindow();
}