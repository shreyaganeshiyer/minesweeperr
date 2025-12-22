#include "allheader.h"

Image flagi;
Image minei;

Texture2D Mine;
Texture2D Flag;

Sound ClickSound;
Sound Blast;
Music GameMusic;

// ------------------ INITIALIZING VAR FOR MAIN----------------------------
bool isSoundEnabled={true};
bool isMusicEnabled={true};

Vector2 click;
int value=0,number; 
int pixrow=0,pixcol=0;
bool flagarr[12][12] = {false};  // store flags
bool isRevelead[12][12]={false};
bool isMine[12][12]={false}; 
GameState PlayerState =menu;

// --------------------- main()function definitions

void LoadGameAssets(void)
{
    minei = LoadImage("assets/BOMB.png");
    ImageResize(&minei, 48, 48);
    Mine = LoadTextureFromImage(minei);
    UnloadImage(minei);

    flagi = LoadImage("assets/1f6a9.png");
    ImageResize(&flagi, 48, 48);
    Flag = LoadTextureFromImage(flagi);
    UnloadImage(flagi);

    Click  = LoadSound("assets/assets_click.wav");
    Blast = LoadSound("assets/assets_explosion.wav");
    GameMusic = LoadMusicStream("assets/assets_game_music.mp3");
}

void UpdateDrawMenu(){
    if(IsKeyPressed(KEY_N)) PlayerState=playin;
    if(IsKeyPressed(KEY_O)) PlayerState= opt;

    ClearBackground(RAYWHITE);
    DrawText("MINESWEEPEER",130,100,50,BLACK);
    DrawText("Press N to start", 130, 250, 30, DARKGREEN);
    DrawText("Press O for Options", 130, 300, 30, DARKBLUE);
}

void UpdateDrawOption(){
    if(IsKeyPressed(KEY_M)) isMusicEnabled=!isMusicEnabled; // toggle
    if(IsKeyPressed(KEY_S)) isSoundEnabled=!isSoundEnabled;
   
}

void UpdateDrawPlay(){    
       for (int row = 0; row < 12; row++){
            for (int col = 0; col < 12; col++){
                pixcol = col * 50;   // convert row/col to pixel
                pixrow = row * 50;
                DrawRectangle(pixcol, pixrow, 48, 48, BLUE);

                if (flagarr[row][col])
                    DrawTexture(Flag, pixcol, pixrow, WHITE);

                if (isRevelead[row][col]){
                    DrawRectangle(pixcol, pixrow, 48, 48, PINK);

                    value=table.grid[row][col];
                    if(value==-1) DrawTexture(Mine, pixcol, pixrow, WHITE);

                    else{  // write number onto screen
                    number=countMine(&table,row,col); 
                    char buff[2];
                    buff[0]= '0'+number; buff[1]='\0';
                    DrawText(buff,pixcol+18,pixrow+10,30,BLACK); } 
                }
    }
}

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;
            isRevelead[row][col]=true;

            SetSoundVolume(ClickSound,1);
            PlaySound(ClickSound);
            if(table.grid[row][col]==-1){ 
                PlaySound(Blast);
                PlayerState=youlost;
            };
        }
       
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            click = GetMousePosition();
            PlaySound(Click);
            int col = click.x / 50;
            int row = click.y / 50;
         
            if(col >= 0 && col < 12 && row >= 0 && row < 12)//initially false
                flagarr[row][col] = !flagarr[row][col]; // true->false or false->true
        }
}

void UpdateDrawLOSE(){

DrawText("HAHA YOU LOST DUMB",130,100,50,BLUE);



}

void UnloadGameAssets(void)
{
    UnloadTexture(Mine);
    UnloadTexture(Flag);
    UnloadSound(Click);
    UnloadSound(Blast);
    UnloadMusicStream(GameMusic);
}