#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"
#include<stdbool.h>


extern Texture2D texMine;
extern Texture2D texFlag;

extern Sound Click;
extern Sound Blast;

extern Music GameMusic;
extern bool isSoundEnabled={true};
extern bool isMusicEnabled={true};

void LoadAssets();
void UnloadAssets();

#endif
