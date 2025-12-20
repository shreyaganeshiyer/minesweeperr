#include<stdio.h>
#include<stdlib.h>
#include "raylib.h"
#include "time.h"
<<<<<<< HEAD
=======
#include<stdlib.h>
>>>>>>> f1267efe8e24c1fd0a47650e1c8ae3ed18342e7a


int size = 12;

int main(){
    Vector2 click;
    int x = -1, y = -1;              // for left click highlight
    int valx = -1, valy = -1;        // temp for right click
    bool flagarr[12][12] = {false};  // store flags
    bool highlight[12][12]={false};

// -------------------BOMB ASSISNMENT----------------------
    srand(time(NULL)); // seed once at start of the game
    bool isMine[12][12]={false};  // it is bool type lol

    int count=15;
    int placed=0;

    InitWindow(50*12, 50*12, "Easylevel");

    while(placed<count){
        int r=rand()%12;
        int c=rand()%12;
        if(!isMine[r][c]){  
            isMine[r][c]=true;
            placed++;
        }

    }

    Image img = LoadImage("1f6a9.png");
    ImageResize(&img, 48, 48);
    Texture2D flage = LoadTextureFromImage(img);
    UnloadImage(img);

    Image bom = LoadImage("BOMB.png"); ///cpu
    ImageResize(&bom, 48, 48);
    Texture2D bomb_tex = LoadTextureFromImage(bom);
    UnloadImage(bom);

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
                
                 if(isMine[ver][i]==true){
                 DrawTexture(bomb_tex, i*50, ver*50, WHITE);
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
            x = col * 50;
            y = row * 50;

        }

        //------------------------- right click toggle flag----------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;
            valx = col * 50;
            valy = row * 50;

            if(col >= 0 && col < 12 && row >= 0 && row < 12){
                flagarr[row][col] = !flagarr[row][col]; // true->false or false->true
                //initially false
            }
        }
        
        EndDrawing();
    }
        
    UnloadTexture(flage);
    CloseWindow();
    }
