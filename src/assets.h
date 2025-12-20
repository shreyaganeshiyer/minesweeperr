#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"
#include<stdbool.h>

extern Image flagi;
extern Image minei;

extern Texture2D Mine;
extern Texture2D Flag;

extern Sound Click;
extern Sound Blast;

extern Music GameMusic;

//-------------- main.c Required Variabless------------------------
extern bool isSoundEnabled;
extern bool isMusicEnabled;

void LoadGameAssets();
void UnloadGameAssets();

#endif
