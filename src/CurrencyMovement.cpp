#include "CurrencyMovement.h"
//-----------------------------------------------------------------
CurrencyMovement::CurrencyMovement():m_position({450,500})
{
	m_sprite.setPosition({ 180,500 });
	m_sprite.setTexture((Resources::getinstance().m_picture.find("bg")->second[0]));

}
//-----------------------------------------------------------------
void CurrencyMovement::draw(sf::RenderWindow& app)
{
	app.draw(m_sprite);
}
