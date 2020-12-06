
#include"FinishMessage.h"
#include <fstream>
#include <iostream>

void FinishMessage::winOrLost(sf::RenderWindow& app, int totalScore)
{
    sf::Clock info;
    sf::Sprite sprite;
    std::ifstream in;
    in.open("MaxScore.txt");
    if (!in.is_open())
        throw std::exception("Cant open file");
    int i;
    in >> i;
    sf::Text text;
    std::cout <<i<<"\n";
    if (totalScore > i)
    {
        std::ofstream out;
        out.open("MaxScore.txt");
        if (!out.is_open())
            throw std::exception("Cant open file");
        out << totalScore;
        sprite.setTexture(Resources::getinstance().m_picture.find("won")->second[INDEXDEFULTE]);
        Resources::getinstance().m_winner.play();
        text = sf::Text(std::to_string(totalScore), Resources::getinstance().m_font);
        text.setPosition(POSITIONMAXCORE);
        text.setCharacterSize(SIZENMAXCORE);
        out.close();
    }
    else {
        sprite.setTexture(Resources::getinstance().m_picture.find("gameover")->second[INDEXDEFULTE]);
        Resources::getinstance().m_gameOver.play();
    }
    while (TIMEOFMASEGE - int(info.getElapsedTime().asSeconds()) >= 0)
    {
        app.draw(sprite);
        app.draw(text);
        app.display();
        app.clear();
    }
    Resources::getinstance().m_winner.stop();
    Resources::getinstance().m_gameOver.stop();
    in.close();
}
