#include "assets.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define TILE_HEIGHT 50
#define TILE_WIDTH 50
int size = 12;

int main(){
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Minesweeper");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        GameUpdate();
    }
    return 0;
}

typedef enum{
    STATE_MAIN_MENU, 
    STATE_OPTIONS_MENU,
    STATE_PLAYING,
    STATE_LOSE,
    STATE_WIN
}GameState;

GameState PlayerState;

void GameUpdate(){
    UpdateMusicStream(GameMusic);

    switch (PlayerState) {

    case STATE_MAIN_MENU:
        if (IsKeyPressed(KEY_N)) {
            GamePlaySound(Click);
            GameReset(); }
        
         else if (IsKeyPressed(KEY_O)) {
            PlayerState = STATE_OPTIONS_MENU;
            GamePlaySound(Click);
        }
        break;

    case STATE_OPTIONS_MENU:
        if (IsKeyPressed(KEY_ENTER)) {
            PlayerState = STATE_MAIN_MENU;
            GamePlaySound(Click); }
            
        if (IsKeyPressed(KEY_S)) {
            isSoundEnabled = !isSoundEnabled;
           // don't play click sounds
        }

        if (IsKeyPressed(KEY_M)) {
            isMusicEnabled = !isMusicEnabled;
            PlayMusicStream(GameMusic);

        if (isMusicEnabled) {
                StopMusicStream(music[MUSIC_ONE]);
                PlayMusicStream(music[MUSIC_ONE]);
            } 
        else StopMusicStream(music[MUSIC_ONE]);
        }
        break;

    case STATE_PLAYING:
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mp = GetMousePosition();
            int col = (int)(mp.x / TILE_WIDTH);
            int row = (int)(mp.y / TILE_HEIGHT);
            if (IsTileIndexValid(col, row)) {
                RevealTile(grid[col][row]);
                GamePlaySound(SOUND_ONE);
            }
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Vector2 mp = GetMousePosition();
            int col = (int)(mp.x / TILE_WIDTH);
            int row = (int)(mp.y / TILE_HEIGHT);
            if (IsTileIndexValid(col, row)) {
                FlagTile(grid[col][row]);
            }

        }

    }
}

}
