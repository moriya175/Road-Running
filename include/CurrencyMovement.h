#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <memory>
using namespace sf;
#include "Collectables.h"
class Factory;
class CurrencyMovement :public Collectables
{
public:
	CurrencyMovement();
	~CurrencyMovement() = default;
	virtual void draw(sf::RenderWindow& app);
	sf::Vector2f m_position;
protected:
};