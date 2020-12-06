#include "..\include\Signpost.h"
#include"Factory.h"
//-----------------------------------------------------------------
Signpost::Signpost()
{
	auto i = Resources::getinstance().m_picture.find("signpost")->second;
	m_kindOfSignpost = rand() % i.size();
	m_pictures.push_back(std::make_unique<sf::Texture>(i[m_kindOfSignpost]));
	if (m_pictures.size() == 0)
		throw std::exception("");
}
//-----------------------------------------------------------------
bool Signpost::m_registerit = Factory::Register("Signpost",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<Signpost>();
	});
