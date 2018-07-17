#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentId = std::size_t;

inline ComponentId getComponentTypeId() {
	static ComponentId lastId = 0;
	return lastId++;
}

template <typename T> inline ComponentId getComponentId() noexcept
{
	static ComponentId typeId = getComponentTypeId();
	return typeId;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}
};

class Entity {
public:
	void Update();
	void Draw();
	bool IsActive() const;
	void Destory();

	template <typename T> bool HasComponent() const;

	template <typename T, typename... TArgs>
		T& addComponent(TArgs&&...mArgs);

	template <typename T> T& getComponent() const;

private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
};

template<typename T>
inline bool Entity::HasComponent() const {
	return componentBitSet[getComponentId<T>];
}

template<typename T, typename ...TArgs>
inline T & Entity::addComponent(TArgs && ...mArgs){
	T* c(new T(std::forward<TArgs>(mArgs)...));
	c->Entity = this;
	std::unique_ptr<Component> uPtr{ c };
	components.emplace_back(std::move(uPtr));
	
	componentArray[getComponentTypeId<T>()] = c;
	componentBitSet[getComponentTypeId<T>()] = true;

	c->init();
	return *c;
}

template<typename T>
inline T & Entity::getComponent() const {
	auto ptr(componentArray[getComponentTypeId<T>()]);
	return *static_cast<T*>(ptr);
}
