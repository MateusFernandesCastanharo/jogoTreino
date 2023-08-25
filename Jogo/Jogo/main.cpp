#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "game.h"


int main(int argc, char* args[]) {

    const int fps = 60;
    const int fpsDelay = 1000 / fps;

    Uint32 frameStart;
    int frameTime;
    
    game* Game = new game();
    
    Game->init("JOGO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    while (Game->running()) {
        frameStart = SDL_GetTicks();

        Game->handleEvents();
        Game->update();
        Game->render();
        Game->teste();

        frameTime = SDL_GetTicks() - frameStart;

        if (fpsDelay > frameTime) {

            SDL_Delay(fpsDelay - frameTime);

        }
    }
    Game->clear();
    return 0;
}