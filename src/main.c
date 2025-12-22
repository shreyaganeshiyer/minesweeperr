#include "allheader.h"

int main(){
    InitWindow(12*50,12*50,"Minesweeper");
    InitAudioDevice();
    LoadGameAssets();
    SetTargetFPS(60);
    init_table(&table);
    placeMines(&table); 
    srand(time(NULL)); 
  
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
    CloseAudioDevice();
    CloseWindow();
    return 0;
}






