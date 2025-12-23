#include "allheader.h"

int main(){
    InitWindow(12*50,12*50,"Minesweeper");
    LoadGameAssets();
    SetTargetFPS(60);
    init_table(&table);
    placeMines(&table); 

    PlayMusicStream(GameMusic);
    SetMusicVolume(GameMusic,0.15f);

    srand(time(NULL));
    
    while(!WindowShouldClose()){
    BeginDrawing();
    UpdateMusicStream(GameMusic);
    ClearBackground(RAYWHITE);

            switch(PlayerState){
                case menu: UpdateDrawMenu(); break;
                case opt: UpdateDrawOption(); break;
                case playin:UpdateDrawPlay(); break;
                case youlost: UpdateDrawLOSE();break;
                }

    EndDrawing();
    }
    
    UnloadGameAssets();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}






