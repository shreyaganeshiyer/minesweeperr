#include "allheader.h"

int main(){
    InitWindow(12*50,12*50,"Minesweeper");
    InitAudioDevice();
    
    LoadGameAssets();
    SetTargetFPS(60);
    init_table(&table);
    placeMines(&table); 
    
    PlayMusicStream(GameMusic);
    

    srand(time(NULL));
    
    while(!WindowShouldClose()){
    BeginDrawing();
    UpdateMusicStream(GameMusic);

    if (isMusicEnabled) SetMusicVolume(GameMusic, 0.1f);
    else SetMusicVolume(GameMusic, 0.0f);
    if(isSoundEnabled && GetKeyPressed()!=0) PlaySound(ClickSound);

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






