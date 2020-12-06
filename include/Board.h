#pragma once
#include <SFML/Graphics.hpp>
#include"ZoomPicture.h"
#include"utilitiy.h"
#include"CurrencyMovement.h"
#include"Policeman.h"
#include"Sheet.h"

class Player;
using namespace sf;
class Board
{

public:
	void setpos(int sp = speed);
	Board();
	void makeObject();
	~Board()=default;
	void draw(sf::RenderWindow& window);
	void checkcolide(Player& player);
private:
	bool m_magnet ;
	void drawQuad(RenderWindow& w, Color c, int x1, int y1, int w1, int x2, int y2, int w2);
	sf::Clock m_makeobj;
	sf::Clock timeMagnet;
	CurrencyMovement m_movment;
	void roaddraw(sf::RenderWindow& window);
	void Treedraw(sf::RenderWindow& window);
	int m_pos;
	int m_H, m_startPos;
	Texture m_bg;
	Sprite m_sBackground;
	std::vector<std::unique_ptr<ZoomPicture>>m_lines;
};