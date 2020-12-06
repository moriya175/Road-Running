#include"DisplayData.h"
#include"utilitiy.h"
#include <fstream>
//-----------------------------------------------------------------
DisplayData::DisplayData(Player* player)
{
	for (auto& i : Resources::getinstance().m_picture.find("display")->second)
		m_display.push_back(std::make_unique<sf::Texture>(i));
	player->RegisterObserver(this);
}
//-------------------------------------------------------------------------
//הפונקציה מציגה מידע אודות מספר החיים והניקוד
void DisplayData::displayState(sf::RenderWindow& app)
{
	std::ifstream in;
	int c;

	auto text = sf::Text(std::to_string(total_live), Resources::getinstance().m_font);
	sf::Sprite sprite;
	float posx= TEXT_SIZE;
	sf::Vector2f location({ posx,0 });
	for (int i = 0; i < m_display.size(); i++) {
		sprite.setTexture(*m_display[i].get());	
		app.draw(sprite);	
		text.setPosition({sprite.getPosition().x+70,sprite.getPosition().y});
		text.setFillColor(sf::Color::Black);
		text.setCharacterSize(TEXT_SIZE);
		app.draw(text);
		sprite.setPosition({ posx += SPACE_TEXT,0 });
		text = sf::Text(std::to_string(total_coins), Resources::getinstance().m_font);
	}
	in.open("MaxScore.txt");
	if (!in.is_open())
		throw std::exception("Cant open file");
	in >> c;
	if (total_coins > c)
		c = total_coins;
	text = sf::Text("max score" + std::to_string(c), Resources::getinstance().m_font);
	text.setPosition({ sprite.getPosition().x + 140,sprite.getPosition().y });
	text.setFillColor(sf::Color::Black);
	app.draw(text);
	in.close();
}
//-----------------------------------------------------------------
void DisplayData::Update(int coins,int live)
{
	total_coins = coins;
	total_live = live;
}
