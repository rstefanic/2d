#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

Game::Game()
{
}

void Game::init(const char *title, int x, int y, 
	int width, int height, bool fullscreen) 
{

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Game initialized." << std::endl;

		this->window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (this->window) { 
			std::cout << "Window created." << std::endl;
		}

		this->renderer = SDL_CreateRenderer(this->window, -1, 0);

		if (this->renderer) {
			SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
			std::cout << "Renderer created." << std::endl;
		}

		this->isRunning = true;
	}
	else {
		this->isRunning = false;
	}

	SDL_Surface* tmpSurface = IMG_Load("Assets/happy.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Game::update() 
{
	this->counter++;
	destR.h = 64;
	destR.w = 64;
	destR.x = counter / 4;

	std::cout << counter << std::endl;
}

void Game::render()
{
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(this->renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			this->isRunning = false;
			break;

		default:
			break;
	}

}

bool Game::running()
{
	return this->isRunning;
}

Game::~Game()
{
}
