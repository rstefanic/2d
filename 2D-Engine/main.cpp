#include "Game.h"
#undef main

Game* g = nullptr;

int main(int argc, char* argv) 
{
	g = new Game();

	g->init("2D Engine", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (g->running()) {
		g->handleEvents();
		g->update();
		g->render();
	}

	g->clean();
	return EXIT_SUCCESS;
}