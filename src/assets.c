#include "assets.h"
#include "raylib.h"

void LoadAssets() {
    textures[TEXTURE_FLAG] = LoadTexture("assets/flag.png");
    sounds[SOUND_ONE] = LoadSound("assets/assets_click.wav");
    sounds[SOUND_TWO] = LoadSound("assets/assets_explosion.wav");
    music[MUSIC_ONE] = LoadMusicStream("assets/gamemusic.mp3");
}
