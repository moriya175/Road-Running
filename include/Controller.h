#pragma once
#include <Resources.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

class Controller
{
public:
	Controller();//בנאי של הקונטרולר
	~Controller() = default;
	void run();
protected:
	bool m_startNewGame;
	sf::RenderWindow m_window;//החלון
	Menu m_menu;
};