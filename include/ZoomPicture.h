#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include"utilitiy.h"
#include"Coin.h"
#include"Resources.h"
#include"MagnetGift.h"
#include"Factory.h"
#include"CollisionHandling.h"
class Player;
class ZoomPicture
{
public:
    ~ZoomPicture() = default;
    ZoomPicture(int i);
    ZoomPicture()=default;
    float m_curve, m_clip;
    float X, Y, W; //screen coord
    void project(int camX, int camY, int camZ);
    void drawSprite(sf::RenderWindow& app);
    float getcentery()const;
    Behavior collides(Object& player, int difrent=250);
    void resetObj();
    void creatobj(int i);
    bool Deletedobj();  
    float getCenterZ()const;
protected:
    int getElapsedTime() const;
    bool IsDisappeared()const;
    std::string str;
    bool m_lessPosition;
    float m_destX;
    float m_destY;
    float m_destW;
    float m_destH;
    std::unique_ptr<Collectables>m_obj;
    float m_centerx, m_centery, m_centerz;
    sf::Clock m_clock;
    float m_spriteX, m_scale;
};


