#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Anemmy.h"
class Factory;
class Obstacle :public Anemmy
{
public:
	Obstacle();
	virtual ~Obstacle() = default;
private:
	int m_kindOfObstacle;
	static bool m_registerit;
};