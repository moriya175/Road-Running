#include "..\include\Game.h"
#include <fstream>
//-----------------------------------------------------------------
Game::Game(sf::RenderWindow& window):m_window(window),m_player({ POSX_PLAYER,POSY_PLAYER }),m_displayData(&m_player)
{
    m_player.RegisterObserver(this);
}
//---------------------------------------------------------------
//הלולאה המרכזית של המשחק
void Game::run()
{
    while (m_window.isOpen())
    {
        if(Resources::getinstance().m_gameMusic.getStatus()==sf::SoundSource::Status::Stopped)
            Resources::getinstance().m_gameMusic.play();
        draw();
        mangeEvent();
        m_board.checkcolide(m_player);
        m_police.checkcolid(m_player);
        m_player.checkState();
        m_board.makeObject();
        m_window.display();
        m_window.clear();
        move();
        if (totalLive== 0)
            break;
    }
    Resources::getinstance().m_gameMusic.stop();
    FinishMessage finishmsg;
    finishmsg.winOrLost(m_window, totalScore);
}
//---------------------------------------------------------------
//מנהלת ארועי מקלדת
void Game::mangeEvent()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            throw std::exception("");
        case sf::Event::KeyPressed:
            m_player.setDirection(event.key.code);
        default:
            break;
        }
}
//---------------------------------------------------------------
//עדכון מס החיים
void Game::Update(int coins, int live)
{
    totalLive = live;
    totalScore = coins;
}
//-----------------------------------------------------------------
void Game::draw()
{
    m_board.setpos();
    m_board.draw(m_window);
    m_player.draw(m_window);
    m_police.draw(m_window);
    m_displayData.displayState(m_window);
}
//-----------------------------------------------------------------
void Game::move()
{
    auto deltatime = m_clockOfmoving.restart();
    m_player.move(deltatime);
    m_police.move(deltatime);
}
//-----------------------------------------------------------------
