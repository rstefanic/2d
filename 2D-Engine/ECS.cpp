#include "ECS.h"

void Entity::Update() {
	for (auto& component : components)
		component->update();

	for (auto& component : components)
		component->draw();
}

void Entity::Draw() {
}

bool Entity::IsActive() const {
	return active;
}

void Entity::Destory() {
	active = false;
}
