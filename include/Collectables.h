#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Object.h"
#include "utilitiy.h"
#include<memory>
class Collectables :public Object
{
public:
	virtual Vector2f getTextureRect();
	void setTextureRect(IntRect rect);
	Sprite getsprite();
	void setScale(float w, float h);
	void setPosition(float w, float h);
	Collectables(const std::string& str);
	~Collectables() = default;
	Collectables() = default;
protected:

};