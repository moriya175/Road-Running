#include "..\include\Obstacle.h"
#include"Factory.h"
//-----------------------------------------------------------------
Obstacle::Obstacle()
{
	auto i = Resources::getinstance().m_picture.find("obstacle")->second;
	m_kindOfObstacle = rand() % i.size();
	m_pictures.push_back(std::make_unique<sf::Texture>(i[m_kindOfObstacle]));
	if (m_pictures.size() == 0)
		throw std::exception("");
}
//-----------------------------------------------------------------
bool Obstacle::m_registerit = Factory::Register("Obstacle",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<Obstacle>();
	});
