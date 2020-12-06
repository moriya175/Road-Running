#include "..\include\Sheet.h"
//-----------------------------------------------------------------
Sheet::Sheet(const sf::Vector2f & p):DynamicObject("sheet"), m_isCollide(false)
{
	m_sprite.setPosition(sf::Vector2f(p.x, 650));
}
//-----------------------------------------------------------------
void Sheet::move(sf::Time deltaTime)
{
	m_sprite.move(sf::Vector2f(0, -0.5));
}

bool Sheet::isCenterY() const
{
	return (m_sprite.getPosition().y<520);
}
void Sheet::draw(sf::RenderWindow& app)
{
	if (m_isCollide)
		app.draw(m_boom);
	else Object::draw(app);
}
bool Sheet::isCollide(Object& object)
{
	if (m_isCollide) return false;
	return(m_isCollide = Object::isCollide(object));
}

void Sheet::colidePlayer()
{
	m_boom.setPosition(m_sprite.getPosition());
	m_boom.setTexture(Resources::getinstance().m_picture.find("18")->second[INDEXDEFULTE]);
}