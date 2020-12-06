#pragma once
#include <SFML/Graphics.hpp>
#include "Collectables.h"
using namespace sf;
class Factory;
class Tree:public Collectables
{
public:
	Tree();
	~Tree() = default;
private:
	static bool m_registerit;
};