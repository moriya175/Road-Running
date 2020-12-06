#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include<vector>
#include"Resources.h"
#include"utilitiy.h"

class FinishMessage 
{
public:
	~FinishMessage() = default;
	void winOrLost(sf::RenderWindow & app, int totalScore);
private:
};