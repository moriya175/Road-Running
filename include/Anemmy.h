#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Collectables.h"
class Factory;

class Anemmy :public Collectables
{
public:
	Anemmy()=default;
	virtual ~Anemmy() = default;
	virtual bool isCollide(Object& object)override;
private:
	bool m_isCollid = false;
};