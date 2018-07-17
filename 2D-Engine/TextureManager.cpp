#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* img) {
	SDL_Surface* surface = IMG_Load(img);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);
	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}