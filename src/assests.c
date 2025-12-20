#include "assets.h"

Texture2D texMine;
Texture2D texFlag;
Sound Click;
Sound Blast;
Music GameMusic;
void LoadGameAssets(void)
{
    texMine = LoadTexture("assets/BOMB.png");
    texFlag = LoadTexture("assets/1f6a9.png");
    Click  = LoadSound("assets/assets_click.wav");
    Blast = LoadSound("assets/assets_explosion.wav");
    GameMusic = LoadMusicStream("assets/assets_game_music.mp3");

}

void UnloadGameAssets(void)
{
    UnloadTexture(texMine);
    UnloadTexture(texFlag);
    UnloadSound(Click);
    UnloadSound(Blast);
    UnloadMusicStream(GameMusic);

}