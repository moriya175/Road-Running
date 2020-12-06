#include"Policeman.h"
#include <CollisionHandling.h>
//-----------------------------------------------------------------
Policeman::Policeman():DynamicObject("policeman"),m_direction(-1)
{
	m_sprite.setPosition(sf::Vector2f(450,670));
}
//-----------------------------------------------------------------
void Policeman::move(sf::Time deltaTime)
{
	eraseSheet();
	creatSheet();
	for (int sheet = 0; sheet < m_sheet.size(); sheet++)
		m_sheet[sheet]->move(deltaTime);
	if (m_sprite.getPosition().x >= LIMRIGTH)
		m_direction = (-1);
	else if (m_sprite.getPosition().x < LIMLEFT)
		m_direction = (1);
	m_sprite.move({ m_direction,0 });
}

void Policeman::draw(sf::RenderWindow& app)
{
	Object::draw(app);
	for (int i = 0; i < m_sheet.size(); i++)
		m_sheet[i]->draw(app);
}

void Policeman::creatSheet()
{
	if(int(m_creatsheet.getElapsedTime().asSeconds())==3)
	{
		m_creatsheet.restart();
		m_sheet.emplace_back(std::make_unique<Sheet>(m_sprite.getPosition()));
	}
}

void Policeman::eraseSheet()
{
	for (int i=0;i<m_sheet.size();i++)
		if(m_sheet[i]->isCenterY())
	m_sheet.erase(m_sheet.begin() + i);
}
void Policeman::checkcolid(Player& player)
{
	for (int i = 0; i < m_sheet.size(); i++)
		if (m_sheet[i]->isCollide(player))
			processCollision(player,*m_sheet[i]);
}