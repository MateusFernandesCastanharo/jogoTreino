#include "game.h"
#include "AssetManager.h"
#include <iostream>	

SDL_Texture* playerTexture;
SDL_Rect origemRect, destinoRect;


game::game()
{}
game::~game()
{}

void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;
	}

	playerTexture = AssetManager::LoadTexture("E:/Java/Jogo/main/res/player/idle1.png", renderer);
}

void game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
}
void game::update() {
	
	destinoRect.w = 64;
	destinoRect.h = 64;

	/*while (SDL_PollEvent(&event)) {
		
		switch (event.type) {
			
		case SDL_QUIT:
			
			game::setRunning(false);
			break;

		case SDL_KEYDOWN:
			
			switch (event.key.keysym.sym) {
			
			case SDLK_UP:
				destinoRect.y += 5;
				
				break;
			case SDLK_DOWN:
				destinoRect.y = -5;
				std::cout << "awdaw";
				break;
			case SDLK_RIGHT:
				destinoRect.x += 5;
				
				break;
			case SDLK_LEFT:
				destinoRect.x = -5;
				
				break;
			};
			break;
		default:
			break;
		}
		
	}*/
}

void game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, &destinoRect);
	SDL_RenderPresent(renderer);
}
void game::clear() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void game::teste() {
	SDL_Event event;
	while (running())
	{
		
		// Process events
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {

			case SDL_QUIT:
				setRunning(false);
				break;

			case SDL_KEYDOWN:
				
				switch (event.key.keysym.sym) {
					std::cout << "awdaw";
				case SDLK_UP:
					destinoRect.y += 5;
					
					break;
				case SDLK_DOWN:
					destinoRect.y = -5;
					break;
				case SDLK_RIGHT:
					destinoRect.x += 5;
					break;
				case SDLK_LEFT:
					destinoRect.x = -5;
					break;
				}
				break;

			default:
				break;
			}

		}

		// Draw
		render();

	}
}
