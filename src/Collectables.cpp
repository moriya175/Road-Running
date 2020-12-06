#include "..\include\Collectables.h"
//-----------------------------------------------------------------
Vector2f Collectables::getTextureRect()
{
	float w =	m_pictures[0]->getSize().x;
	float h=m_pictures[0]->getSize().y;
	return { w,h };
}
//-----------------------------------------------------------------
void Collectables::setTextureRect(IntRect rect)
{
	m_sprite.setTextureRect(rect);
}
//-----------------------------------------------------------------
Sprite Collectables::getsprite()
{
	m_sprite;
	return Sprite();
}
//-----------------------------------------------------------------
void Collectables::setScale(float w, float h)
{
	m_sprite.setScale(w,h);
}
//-----------------------------------------------------------------
void Collectables::setPosition(float x, float y)
{
	m_sprite.setPosition({ x,y });
}
//-----------------------------------------------------------------
Collectables::Collectables(const std::string&str):Object(str)
{
}
//-----------------------------------------------------------------