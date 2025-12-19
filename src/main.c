#include "raylib.h"
#include<stdlib.h>
#include<stdbool.h>

int size=12;

int main(){
Vector2 click; int x,y;

InitWindow(50*12,50*12,"Easylevel");

while(!WindowShouldClose()){

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        click=GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;
            x = col * 50;
            y = row * 50;
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
        click=GetMousePosition();
        int col = click.x / 50;
        int row = click.y / 50;

        





    }


    BeginDrawing();
    ClearBackground(RAYWHITE);

for(int ver=0;ver<12;ver++){
    for(int i=0;i<12;i++){
        DrawRectangle(i*50,ver*50,48,48,BLUE);
    }
    // MOUse clicking
    if(x>=0 &&y>=0)  DrawRectangle(x,y,48,48,PINK);
     
}
    EndDrawing();
}


CloseWindow();
}