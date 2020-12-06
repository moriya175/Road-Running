#pragma once
#include <SFML/Graphics.hpp>
#include"Gift.h"
using namespace sf;
class TransparencyGift :public Gift
{
public:
	TransparencyGift();
	virtual ~TransparencyGift() = default;
private:
	static bool m_registerit;

};