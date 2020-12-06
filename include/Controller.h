#pragma once
#include <Resources.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

class Controller
{
public:
	Controller();//���� �� ���������
	~Controller() = default;
	void run();
protected:
	bool m_startNewGame;
	sf::RenderWindow m_window;//�����
	Menu m_menu;
};