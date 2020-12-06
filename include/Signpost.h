#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Collectables.h"
class Factory;
class Signpost :public Collectables
{
public:
	Signpost();
	virtual ~Signpost() = default;
private:
	int m_kindOfSignpost;
	static bool m_registerit;
};