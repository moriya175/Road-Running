#include"Coin.h"
#include "Factory.h"
#include"utilitiy.h"
//-----------------------------------------------------------------
Coin::Coin():Collectables("coin"),m_moveY(-50)
{
}
//-----------------------------------------------------------------
bool Coin::m_registerit = Factory::Register("coin",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<Coin>();
	});
//-----------------------------------------------------------------
void  Coin::draw(sf::RenderWindow& app)
{
    auto i = m_sprite.getPosition();
    m_sprite.setTexture(*(m_pictures[m_index % m_pictures.size()].get()));
    app.draw(m_sprite);
    m_counter++;
    if (m_counter == ITARATION)
    {
        m_index++;
        m_counter = 0;
    }
}
//-----------------------------------------------------------------
void Coin::move(sf::Vector2f p)
{
    m_lessPosition = { p.x - m_sprite.getPosition().x,m_moveY };
}