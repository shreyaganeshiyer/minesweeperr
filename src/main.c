#include "allheader.h"

int main(){
    InitWindow(12*50,12*50,"Minesweeper");
    SetTargetFPS(60);
    init_table(&table);
    placeMines(&table); 
    srand(time(NULL)); 
    LoadGameAssets();

    while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RAYWHITE);

            switch(PlayerState){
                case menu: UpdateDrawMenu(); break;
                case opt: UpdateDrawOption(); break;
                case playin:UpdateDrawPlay(); break;
                }

    EndDrawing();
    }
    UnloadGameAssets();
    CloseWindow();
    return 0;
}






