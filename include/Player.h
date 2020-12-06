#pragma once
#include <SFML/Graphics.hpp>
#include"DynamicObject.h"
#include <SFML\Graphics\Color.hpp>
using namespace sf;
#include"Subject.h"
#include"Observer.h"
class Player:public DynamicObject, Subject
{
public:
	Player(sf::Vector2f location);
	Player() = default;
	void setClear();
	void setMagnet();
	bool isClear()const;
	virtual void move(sf::Time deltaTime)override;
	void setDirection(sf::Keyboard::Key key);
	virtual ~Player() = default;
	void addScore(int score);
	void addLive(int live);
	void checkState();
	virtual void NotifyObservers()override;
	virtual void RegisterObserver(Observer* pObserver)override;
	virtual void RemoveObserver(Observer* pObserver)override;
private:
	int m_score;
	int m_live;
	bool m_isClear;
	bool m_isMagnet;
	sf::Vector2f m_direction = { 0,0 };
	sf::Clock m_GiftTime;
	std::vector<Observer*> vec_pObserver_;
};