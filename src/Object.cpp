#include "..\include\Object.h"
//-----------------------------------------------------------------
Object::Object(const std::string& str) :m_index(0), m_counter(0), m_lessPosition({ 0,0 })
{ 
    for(auto &i: Resources::getinstance().m_picture.find(str)->second)
    m_pictures.push_back(std::make_unique<sf::Texture>(i));
    if (m_pictures.size()==0)
        throw std::exception("");
    m_sprite.setTexture(*m_pictures[0]);
}
//-----------------------------------------------------------------
const sf::Vector2f& Object::getPosition() const
{
    return m_sprite.getPosition();
}
//-----------------------------------------------------------------
void  Object::draw(sf::RenderWindow& app)
{
    auto i = m_sprite.getPosition();
    m_sprite.setTexture(*(m_pictures[m_index % m_pictures.size()].get()));
       app.draw(m_sprite);
          m_counter++;

           if (m_counter == ITARATION_P)
           {
               m_index++;
               m_counter = 0;
           }
   m_lessPosition = sf::Vector2f(0, 0);
}
//-----------------------------------------------------------------
bool Object::isCollide(Object& object)
{
    return m_sprite.getGlobalBounds().intersects(object.m_sprite.getGlobalBounds());
}
//-----------------------------------------------------------------
const Vector2f& Object::getlessPosition()const
{
    return m_lessPosition;
}
