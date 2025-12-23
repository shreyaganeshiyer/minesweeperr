#include "allheader.h"
#include "dsa.h"

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

    ClickSound  = LoadSound("assets/assets_click.wav");
    Blast = LoadSound("assets/explosion.mp3");

    SetSoundVolume(ClickSound, 0.25f);
    SetSoundVolume(Blast, 1.0f);

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

            if(row>=0 && row<12 && col>=0 && col<12){
                if(table.grid[row][col]==-1){
                isRevelead[row][col]==true;
                PlayerState=youlost;
            }
                if(!isRevelead[row][col]){  // init false -->true
                    if(countMine(&table,row,col)==0){
                    bfsReveal(&table,isRevelead,row,col); // isRevelead is sent as false
                }
                else{
                    isRevelead[row][col]=true;
                }
            }
        }
    }
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            click = GetMousePosition();
            
            int col = click.x / 50;
            int row = click.y / 50;
         
            if(col >= 0 && col < 12 && row >= 0 && row < 12)//initially false
                flagarr[row][col] = !flagarr[row][col]; // true->false or false->true
        }
}

void UpdateDrawLOSE(){
DrawText("HAHA YOU LOST DUMB",90,100,30,RED);
DrawText("Press Enter to Play AGAIN",90,150,30,BLUE);
DrawText("Press ESC to QUIT THE GAME",90,200,30,BLUE);
    if(IsKeyPressed(KEY_ENTER)) {
        PlayerState=menu;
        NewGame();
    }
}

void NewGame(){
    init_table(&table);
    placeMines(&table);
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            flagarr[i][j]=false;  // reset every goddamn thing that uses this play
            isRevelead[i][j]=false;
            isMine[i][j]=false;
        }
    }
}

void UnloadGameAssets(void)
{
    UnloadTexture(Mine);
    UnloadTexture(Flag);
    UnloadSound(ClickSound);
    UnloadSound(Blast);
    UnloadMusicStream(GameMusic);
}