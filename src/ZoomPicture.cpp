
#include "ZoomPicture.h"
#include"Player.h"
//-----------------------------------------------------------------
ZoomPicture::ZoomPicture(int i) :m_obj(nullptr)
{
    creatobj(i);
}
//-----------------------------------------------------------------
void ZoomPicture::project(int camX, int camY, int camZ)
{
    m_scale = camD / (m_centerz - camZ);
    X = (1 + m_scale * (m_centerx - camX)) * width / 2;
    Y = (1 - m_scale * (m_centery - camY)) * height / 2;
    W = m_scale * roadW * width / 2;
}
//-----------------------------------------------------------------
void  ZoomPicture::drawSprite(sf::RenderWindow& app)
{
    if (W < 20)
        m_clock.restart();
    float divX = 0, DivY = 0;
    if (m_obj)
    {
        m_lessPosition = 1;
        int w = m_obj->getTextureRect().x;
        int h = m_obj->getTextureRect().y;
           // W += 100;
        m_destW = w * W / 100;
        m_destH = h * W / 100;
        m_destX = X + m_scale * m_spriteX * width / 2 +m_destW * m_spriteX+m_obj->getlessPosition().x ;
        m_destY = Y + 4 + (m_destH * (-1))+m_obj->getlessPosition().y;
        if (m_obj->getlessPosition().x != 0)
            m_destY += 5;
        float clipH = m_destY + m_destH - m_clip;
        if (clipH < 0) clipH = 0;
        if (clipH >= m_destH) return;
        m_obj->setTextureRect(sf::IntRect(0, 0, w, h - h * clipH / m_destH));
        m_obj->setScale(m_destW / w, m_destH / h);
        m_obj->setPosition(m_destX, m_destY);
        m_obj->draw(app);
    }
}
//-----------------------------------------------------------------
float ZoomPicture::getcentery()const
{
    return m_centery;
}
//-----------------------------------------------------------------
Behavior ZoomPicture::collides(Object& player, int difrent)
{
    if (m_obj)
    {
       // if (m_destX + 10 < player.getPosition().x || m_destX > player.getPosition().x + 10|| m_destY + 150 < player.getPosition().y || m_destY > player.getPosition().y + 150)
       if(W< difrent)
            return NOTHING;
        if (m_obj->isCollide(player))
        {
          return(  processCollision(player, *m_obj));
        }
    }
    return NOTHING;
}
//-----------------------------------------------------------------
int ZoomPicture::getElapsedTime()const
{
    return (int)m_clock.getElapsedTime().asSeconds();
}
//-----------------------------------------------------------------
void ZoomPicture::resetObj()
{
    m_obj = nullptr;
    m_clock.restart();
}
//-----------------------------------------------------------------
void ZoomPicture::creatobj(int i)
{
    if (!m_obj)
    {
         m_lessPosition = 0;
        m_spriteX = m_curve = m_centerx = m_centery = m_centerz = 0;
        m_centerz = i * segL;
        if (i > 300 && i < 700)m_curve = 0.5;    if (i > 1100) m_curve = 9;
        if (i % 7 == 0 && i/ 100 % 2 != 0) { m_spriteX = -0.3; str = "coin"; }
        if (i % 7 == 0 && i / 100 % 2 == 0) { m_spriteX = -4.0; str = "coin"; }
        if (i % 9 == 0 && i / 100 % 2 == 0) { m_spriteX = 3.8;  str = "coin"; }
        if (i % 20 == 0) { m_spriteX = -1.5; str = "tree"; }
        if (i % 17 == 0) { m_spriteX = 0.3; str = "tree"; }
        if (i % 61== 0) { m_spriteX = -0.8; str = "Obstacle"; }
        if (i % 271 == 0 ) { m_spriteX = -1;str = "Heart"; }
        if (i % 163 == 0 ) { int num = rand() % 2; if (num) { m_spriteX = -2; } else m_spriteX = 1.6; str = "Signpost"; }
        if (i % 7 == 0 && i / 100 % 2 != 0&&i%147==0) { m_spriteX = 2.2; str = "magmet"; }
        if (i % 157 == 0) { m_spriteX = -0.5; str = "clear"; }
        if (i % 103 == 0) { int num = rand() % 2; if (num) { m_spriteX = 0.8; } else m_spriteX = -1.4;  str = "car"; }
        if (i > 750) m_centery = sin(i / 30.0) * 1500;
        if (str.size() > 2)
        {
            m_obj = Factory::create(str);
        }
    }
}
//-----------------------------------------------------------------
bool ZoomPicture::Deletedobj()
{
    if ((getElapsedTime() == 10 && IsDisappeared() || W <15))
        return true;
        return false;
}
//-----------------------------------------------------------------
bool ZoomPicture::IsDisappeared()const
{
    return!(m_obj);
}
//-----------------------------------------------------------------
float ZoomPicture::getCenterZ()const
{
    return W;
}
