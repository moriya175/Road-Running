#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include<vector>
#include"Resources.h"
#include"Player.h"
#include"Observer.h"
class DisplayData:public Observer
{
public:
	DisplayData(Player* player);
	virtual ~DisplayData() = default;
	void displayState(sf::RenderWindow& app);
	virtual void Update(int coins, int live)override;
private:
	std::vector<std::unique_ptr<sf::Texture>>m_display;
	int total_coins;
	int total_live;
};