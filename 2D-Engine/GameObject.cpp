#include "GameObject.h"

GameObject::GameObject(const char* texSheet, int x, int y) {
	objectTexture = TextureManager::LoadTexture(texSheet);
	xpos = x;
	ypos = y;
}

GameObject::~GameObject() {

}

void GameObject::Update() {

	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objectTexture, 
		&srcRect, &destRect);
}