#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"DynamicObject.h"
#include"Sheet.h"
#include"Player.h"
class Factory;
class Policeman :public DynamicObject
{
public:
	Policeman();
	virtual ~Policeman() = default;
	virtual void move(sf::Time deltaTime)override;
	virtual void draw(sf::RenderWindow& app)override;
	void checkcolid(Player& player);
private:
	void creatSheet();
	void eraseSheet();
	sf::Clock m_creatsheet;
	float m_direction;
	std::vector<std::unique_ptr< Sheet>> m_sheet;
};