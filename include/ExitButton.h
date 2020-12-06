#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Command.h"
class ExitButton:public Command
{
public:
	virtual void execute()override ;
	ExitButton(sf::RenderWindow& window);
	virtual ~ExitButton() = default;
private:
};