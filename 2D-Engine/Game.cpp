#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* p;
GameObject* p2;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

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

	p = new GameObject("assets/happy.png", 0, 0);
	p2 = new GameObject("assets/happy.png", 50, 50);
	map = new Map();
}

void Game::update() 
{
	p->Update();
	p2->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	p->Render();
	p2->Render();
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
