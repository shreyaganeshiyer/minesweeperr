#include "raylib.h"
#include<stdlib.h>
#include<stdbool.h>

int size = 12;

int main(){
    Vector2 click;
    int x = -1, y = -1;              // for left click highlight
    int valx = -1, valy = -1;        // temp for right click
    bool flagarr[12][12] = {false};  // store flags
    bool highlight[12][12]={false};

    InitWindow(50*12, 50*12, "Easylevel");

    Image img = LoadImage("1f6a9.png");
    ImageResize(&img, 48, 48);
    Texture2D flage = LoadTextureFromImage(img);
    UnloadImage(img);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // drawing the grid
        for(int ver = 0; ver < 12; ver++){
            for(int i = 0; i < 12; i++){
                DrawRectangle(i*50, ver*50, 48, 48, BLUE);

                if(flagarr[ver][i] == true){
                    DrawTexture(flage, i*50, ver*50, WHITE);
                }

                if(highlight[ver][i]==true){
                DrawRectangle(i*50,ver*50, 48,48, PINK);
                 }
        }
    }

        // left click highlight
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;

            highlight[row][col]=true;
            x = col * 50;
            y = row * 50;

        }

        // right click toggle flag
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;
            valx = col * 50;
            valy = row * 50;

            if(col >= 0 && col < 12 && row >= 0 && row < 12){
                flagarr[row][col] = !flagarr[row][col];
            }
        }
        
        EndDrawing();
    }
        
    UnloadTexture(flage);
    CloseWindow();
    }

    

