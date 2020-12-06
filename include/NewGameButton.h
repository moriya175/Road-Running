#pragma once
#include <SFML/Graphics.hpp>
#include"Command.h"
#include"Game.h"

using namespace sf;
class NewGameButton:public Command
{
public:
	virtual void execute()override ;
	NewGameButton(sf::RenderWindow& window, bool & startNewGame);
	virtual ~NewGameButton() = default;
private:
	bool & m_startNewGame;
};