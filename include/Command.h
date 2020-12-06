#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include"Resources.h"

using namespace sf;
class Command
{
public:
	Command(sf::RenderWindow& window,std::string str, const sf::Vector2f position);
	virtual ~Command() = default;
	virtual void execute() = 0;
	virtual void draw(sf::RenderWindow& window) { window.draw(m_sprite); };
	bool isInRect(sf::Vector2f possition)const { return(m_sprite.getGlobalBounds().contains(possition)); }
protected:
	sf::Sprite m_sprite;
	sf::RenderWindow& m_window;
};
