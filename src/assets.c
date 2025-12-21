#include "assets.h"

Image flagi;
Image minei;

Texture2D Mine;
Texture2D Flag;

Sound Click;
Sound Blast;
Music GameMusic;

// ------------------ INITIALIZING VAR FOR MAIN----------------------------
bool isSoundEnabled={true};
bool isMusicEnabled={true};


void LoadGameAssets(void)
{
    minei = LoadImage("assets/BOMB.png");
    ImageResize(&minei, 48, 48);
    Mine = LoadTextureFromImage(minei);
    UnloadImage(minei);

<<<<<<< HEAD:src/assests.c
    flagi = LoadImage("C:/Users/shrey/Desktop/ds_project/minesweeperr/assets/1f6a9.png");
=======
      UnloadImage(minei);
    flagi = LoadImage("assets/1f6a9.png");
>>>>>>> 3f37a7100fe7b6e951fa2571750f7868e758766f:src/assets.c
    ImageResize(&flagi, 48, 48);
    Flag = LoadTextureFromImage(flagi);
    UnloadImage(flagi);

    Click  = LoadSound("assets/assets_click.wav");
    Blast = LoadSound("assets/assets_explosion.wav");
    GameMusic = LoadMusicStream("assets/assets_game_music.mp3");

}

void UnloadGameAssets(void)
{
    UnloadTexture(Mine);
    UnloadTexture(Flag);
    UnloadSound(Click);
    UnloadSound(Blast);
    UnloadMusicStream(GameMusic);
}