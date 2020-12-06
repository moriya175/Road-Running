#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Gift.h"
class Factory;
class Heart :public Gift
{
public:
	Heart();
	virtual ~Heart() = default;
private:
	static bool m_registerit;

};