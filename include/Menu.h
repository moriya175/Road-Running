#pragma once
#include"Command.h"
#include"ExitButton.h"
#include"NewGameButton.h"
#include <SFML/Graphics.hpp>
class Menu
{
public:
	Menu(sf::RenderWindow& window, bool& startNewGame);//בנאי של הקונטרולר
	~Menu() = default;
	void open();
protected:
	void draw();
	std::vector<std::unique_ptr<Command>> m_act;
	sf::RenderWindow& m_window;
	sf::Sprite m_bgmenu;
};