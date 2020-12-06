#pragma once
#include <SFML/Audio.hpp>

#include <SFML/Graphics.hpp>
#include <map>
class Resources
{
public:
	std::map<std::string, std::vector<sf::Texture>>m_picture;//וקטור של תמונות
	static Resources& getinstance();
	sf::Music m_coinMusic;
	sf::Music m_gameMusic;
	sf::Font m_font;
	sf::Music m_impactsound;
	sf::Music m_livetune;
	sf::Music m_gameOver;
	sf::Music m_winner;
	sf::Music m_boom;

protected:
	Resources();//בנאי של לינקר שקורא את התמונות
	void insertPicture();
};