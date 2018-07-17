#include "Game.h"
#undef main

Game* g = nullptr;

int main(int argc, char* argv) 
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	
	g = new Game();

	g->init("2D Engine", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (g->running()) {

		frameStart = SDL_GetTicks();

		g->handleEvents();
		g->update();
		g->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	g->clean();
	return EXIT_SUCCESS;
}