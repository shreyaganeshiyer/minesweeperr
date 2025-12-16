#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define TILE 40
#define MINES 15  

typedef enum {
    MAIN_MENU,
    PLAYING,
    GAME_OVER
} GameState;
GameState pendingState = -1; 
float stateTimer = 0.0f;
const float TRANSITION_DELAY = 1.0f; 


int main(void)
{
    InitWindow(COLS * TILE, ROWS * TILE, "Minesweeper");
    SetTargetFPS(60);

    Texture2D flag = LoadTexture("flag.png");
    Texture2D mine = LoadTexture("mine.png");

    GameState state = MAIN_MENU;

    bool revealed[ROWS][COLS] = {0};
    bool flagged[ROWS][COLS]  = {0};
    bool mines[ROWS][COLS]    = {0};

    srand(time(NULL));

   
    void resetGame(){
        for(int r=0;r<ROWS;r++)
            for(int c=0;c<COLS;c++){
                revealed[r][c]=false;
                flagged[r][c]=false;
                mines[r][c]=false;
            }
        int placed = 0;
        while(placed<MINES){
            int r = rand()%ROWS;
            int c = rand()%COLS;
            if(!mines[r][c]){
                mines[r][c]=true;
                placed++;
            }
        }
    }

    while(!WindowShouldClose()){
        Vector2 m = GetMousePosition();
        int col = (int)m.x / TILE;
        int row = (int)m.y / TILE;

        
        if(state == MAIN_MENU){
            if(IsKeyPressed(KEY_ONE)){
                state = PLAYING;
                resetGame();
            }
            if(IsKeyPressed(KEY_TWO)){
                break; 
            }
        }
        else if(state == PLAYING){
            if(row>=0 && row<ROWS && col>=0 && col<COLS){
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !flagged[row][col]){
                    revealed[row][col]=true;
                    if(mines[row][col]){
                        pendingState=GAME_OVER;
                        stateTimer=TRANSITION_DELAY;
                        
                        for(int r=0;r<ROWS;r++)
                            for(int c=0;c<COLS;c++)
                                if(mines[r][c]) revealed[r][c]=true;
                    }
                }
                if(IsKeyPressed(KEY_F) && !revealed[row][col]){
                    flagged[row][col]=!flagged[row][col];
                }
            }
        }
        float dt = GetFrameTime(); // seconds since last frame
        if(pendingState != -1){
        stateTimer -= dt;
        if(stateTimer <= 0){
        state = pendingState;
        pendingState = -1;
    }
}

        else if(state == GAME_OVER){
            if(IsKeyPressed(KEY_ENTER)){
                state = PLAYING;
                resetGame();
            }
        }

       
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(state == MAIN_MENU){
            ClearBackground(WHITE);
            DrawText("MINESWEEPER", 80, 100, 40, BLACK);
            DrawText("Press 1 to Play", 100, 200, 20, DARKGREEN);
            DrawText("Press 2 to Exit", 100, 240, 20, RED);
        }
        else if(state == PLAYING){
            for(int r=0;r<ROWS;r++){
                for(int c=0;c<COLS;c++){
                    Color tileColor = revealed[r][c]?GRAY:BLUE;
                    DrawRectangle(c*TILE,r*TILE,TILE,TILE,tileColor);
                    DrawRectangleLines(c*TILE,r*TILE,TILE,TILE,BLACK);

                    if(revealed[r][c] && mines[r][c]){
                        DrawTexturePro(mine,
                            (Rectangle){0,0,mine.width,mine.height},
                            (Rectangle){c*TILE,r*TILE,TILE,TILE},
                            (Vector2){0,0},0,WHITE);
                    }
                    if(flagged[r][c]){
                        DrawTexturePro(flag,
                            (Rectangle){0,0,flag.width,flag.height},
                            (Rectangle){c*TILE,r*TILE,TILE,TILE},
                            (Vector2){0,0},0,WHITE);
                    }
                }
            }
        }
        else if(state == GAME_OVER){
            ClearBackground(WHITE);
            DrawText("GAME OVER!", 100, 180, 40, RED);
            DrawText("Press ENTER to Play Again", 50, 240, 20, DARKBLUE);
        }

        EndDrawing();
    }

    UnloadTexture(flag);
    UnloadTexture(mine);
    CloseWindow();
    return 0;
}
