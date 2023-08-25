#pragma once
#include "game.h"

class AssetManager {
public:
	static SDL_Texture* LoadTexture(const char* filePath, SDL_Renderer* rend);

};