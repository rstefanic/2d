#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "SDL_image.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, 
		int width, int height, bool fullscreen);

	void update(); // Update all game objects
	void render(); // Render the view
	void clean();  // Manage Memory
	void handleEvents();

	bool running();

private:
	int counter = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

