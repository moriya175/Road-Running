#pragma once
#include <SFML/Graphics.hpp>
#include "utilitiy.h"
#include"Resources.h"

using namespace sf;
class Object
{
public:
	const sf::Vector2f& getPosition()const;
	Object(const std::string& str);
	virtual void draw(sf::RenderWindow& app);
	virtual bool isCollide(Object& object);
	virtual ~Object() = default;
	Object() = default;
	const Vector2f& getlessPosition()const;
protected:
	Vector2f m_lessPosition;
	int m_index;
	int m_counter;
	std::vector<std::unique_ptr<sf::Texture>>m_pictures;
	sf::Sprite m_sprite;
	
};

