#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <math.h> 
using namespace sf;
#include "Collectables.h"
class Factory;
class Coin:public Collectables
{
public:
	Coin();
	void draw(sf::RenderWindow& app);
	void move(sf::Vector2f p);
	~Coin() = default;
protected:
	float m_moveY;
	static bool m_registerit;
};