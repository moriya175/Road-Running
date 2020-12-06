#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include"Board.h"
#include"Coin.h"
#include "DisplayData.h"
#include"Player.h"
#include"FinishMessage.h"
#include"Observer.h"
using namespace sf;
class Game:public Observer
{
public:
	Game(sf::RenderWindow& window);
	virtual ~Game() = default;
	void run();
	virtual void Update(int coins, int live)override;
private:
	void mangeEvent();
	void draw();
	void move();
	Player m_player;
	DisplayData m_displayData;
	sf::RenderWindow& m_window;
	sf::Clock m_clockOfmoving;
	Board m_board;
	int totalLive;
	int totalScore;
	Policeman m_police;

};