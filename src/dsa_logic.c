#include<stdio.h>
#include<stdbool.h>




void GameRender(){
    int seconds=0;
    switch(gameState){
        case STATE_MAIN_MENU:
            DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,DARKBLUE);
            DrawText("MINESWEEPER",20,20,30,WHITE);
            DrawText("[N]ew Game",120,220,30,WHITE);
            DrawText("[O]ptions",120,220,30,WHITE);
            DrawText("Esc to Quit",120,220,30,WHITE);
            DrawText("Copyright 2025 @Ananya_Shreya",120,500,20,WHITE);
            break;

        case STATE_OPTIONS_MENU:
            DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,DARKBLUE);
            DrawText("Minesweeper Options",20,20,40,WHITE);
            DrawText("[S]ound",120,220,40,WHITE);
            DrawText(isSoundEnabled? "ON":"OFF",280,220,20, isSoundEnabled? YELLOW:WHITE);
            DrawText("[M]usic",120,220,40,WHITE);
            DrawText(isMusicEnabled? "ON":"OFF",280,220,20, isMusicEnabled? YELLOW:WHITE);
            DrawText(labelEnter,120,400,20,WHITE);
            break;

    }
}

