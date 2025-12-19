#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

extern Texture2D textures[];
extern Sound sounds[];
extern Music music[];

void LoadAssets();
void UnloadAssets();

#endif
