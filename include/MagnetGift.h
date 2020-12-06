#pragma once
#include <SFML/Graphics.hpp>
#include"Gift.h"
using namespace sf;
class MagnetGift:public Gift
{
public:
	MagnetGift();
	virtual ~MagnetGift() = default;
private:
	static bool m_registerit;

};
