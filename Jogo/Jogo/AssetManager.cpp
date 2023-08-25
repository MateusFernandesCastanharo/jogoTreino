#include "AssetManager.h"

SDL_Texture* AssetManager::LoadTexture(const char* texture, SDL_Renderer* rend) {
	SDL_Surface* surface = IMG_Load(texture);
	SDL_Texture* tx = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	return tx;
}