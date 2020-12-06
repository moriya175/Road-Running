#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"DynamicObject.h"
class Factory;
class Sheet :public DynamicObject
{
public:
	Sheet(const sf::Vector2f& p);
	virtual void move(sf::Time deltaTime)override;
	virtual ~Sheet() = default;
	bool isCenterY()const;
	virtual void draw(sf::RenderWindow& app)override;
	virtual bool isCollide(Object& object)override;
	void colidePlayer();
private:
	sf::Sprite m_boom;
	bool m_isCollide;
};