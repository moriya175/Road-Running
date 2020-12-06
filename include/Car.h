#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Anemmy.h"
class Factory;
class Car:public Anemmy
{
public:
	Car();
	~Car() = default;
private:
	static bool m_registerit;
	int m_kindOfCar;

};