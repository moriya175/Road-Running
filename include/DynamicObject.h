#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Collectables.h"
class DynamicObject :public Object
{
public:
	DynamicObject(const std::string& str);
	virtual ~DynamicObject() = default;
	virtual void move(sf::Time deltaTime)=0;
private:
};