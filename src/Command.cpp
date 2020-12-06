#include "..\include\Command.h"
//-----------------------------------------------------------------
Command::Command(sf::RenderWindow& window,std::string str, const sf::Vector2f position):m_window(window)
{
    auto it = Resources::getinstance().m_picture.find(str);
    if (it == Resources::getinstance().m_picture.end())
        throw std::exception("");
auto& vec = it->second;
     m_sprite = sf::Sprite(vec[0]);
     m_sprite.setPosition(position);
}
