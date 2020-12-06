#include "..\include\Board.h"
#include"Player.h"
//-----------------------------------------------------------------
void Board::setpos(int sp)
{
    m_pos += sp;
}
//-----------------------------------------------------------------
Board::Board():m_pos(0),m_H(1500),m_magnet(1)
{ 
    m_makeobj.restart();
    m_bg = Resources::getinstance().m_picture.find("bg")->second[INDEXDEFULTE];
    m_bg.setRepeated(true);
    m_sBackground.setTexture(m_bg);
    m_sBackground.setTextureRect(IntRect(0, 0, 5000, 411));
    m_sBackground.setPosition(-2000, 0);
    for (int i = m_lines.size(); i <= SIZELINE; i++)
    {
        m_lines.push_back(std::make_unique<ZoomPicture>(i));
    }
}
//-----------------------------------------------------------------
void Board::makeObject()
{
    if (m_makeobj.getElapsedTime().asSeconds() > 1)
    {
        for (int i = 0; i < SIZELINE; i++)
            if (m_lines[i]->Deletedobj())
            {
                m_lines[i] = move(std::make_unique<ZoomPicture>(i));
            }
        m_makeobj.restart();
    }
}
//-----------------------------------------------------------------
void Board::draw(sf::RenderWindow& window)
{
    while (m_pos >= m_lines.size() * segL) m_pos -= m_lines.size() * segL;
    while (m_pos < 0) m_pos += m_lines.size() * segL;
    window.clear(Color(105, 205, 4));
    window.draw(m_sBackground);
    m_startPos = m_pos / segL;
    int maxy = height;
    roaddraw(window);
    Treedraw(window);
}
//-----------------------------------------------------------------
void Board::drawQuad(RenderWindow& w, Color c, int x1, int y1, int w1, int x2, int y2, int w2)
{
    ConvexShape shape(4);
    shape.setFillColor(c);
    shape.setPoint(0, Vector2f(x1 - w1, y1));
    shape.setPoint(1, Vector2f(x2 - w2, y2));
    shape.setPoint(2, Vector2f(x2 + w2, y2));
    shape.setPoint(3, Vector2f(x1 + w1, y1));
    w.draw(shape);
}
//-----------------------------------------------------------------
void Board::checkcolide(Player& player)
{
    for (int n = 0; n < m_lines.size(); n++)
    {
        if (timeMagnet.getElapsedTime().asSeconds() < TIMEOFGIFT&& !m_magnet&&!player.isClear())
        {
            m_lines[n]->collides(m_movment,122);
            processCollision(player, m_movment);
        }
        Behavior b=m_lines[n]->collides(player);
        if (b == MAGNET)
        {
            m_magnet = 0;
            timeMagnet.restart();
            m_lines[n]->resetObj();
        }
         else if(b==DELETED)
        m_lines[n]->resetObj();
        
    }
}
//-----------------------------------------------------------------
void Board::roaddraw(sf::RenderWindow& window)
{
    int maxy = height;
    int camH = m_lines[m_startPos]->getcentery() + m_H;
    float x = 0, dx = 0;
    for (int n = m_startPos; n < m_startPos + SIZELINE; n++)
    {
        ZoomPicture* l = m_lines[n % m_lines.size()].get();
       l->project(100, camH, m_startPos * segL - (n >= m_lines.size() ? m_lines.size() * segL : 0));
        x += dx;
        dx += l->m_curve;
        l->m_clip = maxy;
        if (l->Y >= maxy) continue;
        maxy = l->Y;
        Color grass = (n / 3) % 2 ? Color(16, 200, 16) : Color(0, 154, 0);
        Color rumble = (n / 3) % 2 ? Color(255, 255, 255) : Color(0, 0, 0);
        Color road = (n / 3) % 2 ? Color(107, 107, 107) : Color(105, 105, 105);
        ZoomPicture* p = m_lines[(n - 1) % m_lines.size()].get(); //previous line
        drawQuad(window, grass, 0, p->Y, width, 0, l->Y, width);
        drawQuad(window, rumble, p->X, p->Y, p->W * 1.2, l->X, l->Y, l->W * 1.2);
        drawQuad(window, road, p->X, p->Y, p->W, l->X, l->Y, l->W);
    }
}
//-----------------------------------------------------------------
void Board::Treedraw(sf::RenderWindow& window)
{
    for (int n = m_lines.size(); n >0 ; n--)
        m_lines[n-1]->drawSprite(window);
}