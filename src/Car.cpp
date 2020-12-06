#include"Car.h"
#include"Factory.h"
//-----------------------------------------------------------------
Car::Car()
{
	auto i = Resources::getinstance().m_picture.find("car")->second;
	m_kindOfCar = rand ()% i.size();
		m_pictures.push_back(std::make_unique<sf::Texture>(i[m_kindOfCar]));
	if (m_pictures.size() == 0)
		throw std::exception("");
}
//-----------------------------------------------------------------
bool Car::m_registerit = Factory::Register("car",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<Car>();
	});
