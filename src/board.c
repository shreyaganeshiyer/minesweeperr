#include<stdio.h>
#include "raylib.h"
#include "time.h"
#include<stdlib.h>
#include "assets.h"


int size = 12;

int main(){
    Vector2 click;
    bool flagarr[12][12] = {false};  // store flags
    bool highlight[12][12]={false};

// -------------------BOMB ASSISNMENT----------------------
    srand(time(NULL)); // seed once at start of the game
    bool isMine[12][12]={false};  // it is bool type lol

    int count=15;
    int placed=0;

    InitWindow(50*12, 50*12, "Easylevel");
      LoadGameAssets();
    while(placed<count){
        int r=rand()%12;
        int c=rand()%12;
        if(!isMine[r][c]){  
            isMine[r][c]=true;
            placed++;
        }

    }
    // -------------------------- IMPORTANT PART ---------------------
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

      
        // drawing the grid
        for(int ver = 0; ver < 12; ver++){
            for(int i = 0; i < 12; i++){
                DrawRectangle(i*50, ver*50, 48, 48, BLUE);

                if(flagarr[ver][i] == true){
                    DrawTexture(Flag, i*50, ver*50, WHITE);
                }

                if(highlight[ver][i]==true){
                DrawRectangle(i*50,ver*50, 48,48, PINK);
                
                 if(isMine[ver][i]==true){
                 DrawTexture(Mine,i*50, ver*50, WHITE);
                }
                 }

               
        }
    }

        //-------------------------- left click highlight--------------------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;

            highlight[row][col]=true;

        }

        //------------------------- right click toggle flag----------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;
         
            if(col >= 0 && col < 12 && row >= 0 && row < 12){
                flagarr[row][col] = !flagarr[row][col]; // true->false or false->true
                //initially false
            }
        }
        
        EndDrawing();
    }
    UnloadGameAssets();
    CloseWindow();
    }
