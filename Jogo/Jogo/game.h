#ifndef game_h
#define game_h

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

class game
{
public:
	game();
	~game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clear();

	bool running() { 
		return isRunning; 
	};

	void setRunning(bool Running) {
		isRunning = Running;
	}
	
	void teste();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif