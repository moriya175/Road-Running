#include"Player.h"
#include "Factory.h"
//-----------------------------------------------------------------
Player::Player(sf::Vector2f location) :DynamicObject("player"),m_score(0),m_live(LIVE), m_isClear(false)
{
	m_sprite.setPosition(location);
	NotifyObservers();
}
//-----------------------------------------------------------------
void Player::setClear()
{
	m_GiftTime.restart();
	m_isClear = true;
	m_pictures.clear();
	for (auto& i : Resources::getinstance().m_picture.find("menC")->second)
		m_pictures.push_back(std::make_unique<sf::Texture>(i));
}
//-----------------------------------------------------------------
void Player::setMagnet()
{
	m_GiftTime.restart();
	m_pictures.clear();
	for (auto& i : Resources::getinstance().m_picture.find("manM")->second)
		m_pictures.push_back(std::make_unique<sf::Texture>(i));
	m_isMagnet = true;
	m_isClear = false;
}
//-----------------------------------------------------------------
bool Player::isClear() const
{
	return m_isClear;
}
//-----------------------------------------------------------------
void Player::move(sf::Time deltaTime)
{
	m_sprite.move(((float)playerSpeed * m_direction) * deltaTime.asSeconds());
		m_direction = { 0,0 };
	if (m_sprite.getPosition().x > LIMRIGTH)
		m_sprite.setPosition({ LIMRIGTH ,m_sprite.getPosition().y });
	if (m_sprite.getPosition().x < LIMLEFT)
		m_sprite.setPosition({ LIMLEFT ,m_sprite.getPosition().y });
	NotifyObservers();

}
//-----------------------------------------------------------------
void Player::setDirection(sf::Keyboard::Key key)
{
	switch (key){
	case(sf::Keyboard::Left): m_direction = { -1,0 }; break;
	case(sf::Keyboard::Right):   m_direction = { 1,0 }; break;
	}
}
//-----------------------------------------------------------------
void Player::addScore(int score)
{
	m_score += score;
	NotifyObservers();
}
//-----------------------------------------------------------------
void Player::addLive(int live)
{
	m_live += live;
	NotifyObservers();
}
//-----------------------------------------------------------------
void Player::checkState()
{
	if (m_GiftTime.getElapsedTime().asSeconds() > TIMEOFGIFT && (m_isClear||m_isMagnet)) {
		m_pictures.clear();
		for (auto& i : Resources::getinstance().m_picture.find("player")->second)
			m_pictures.push_back(std::make_unique<sf::Texture>(i));
		m_isClear = false;
	}
}
//-----------------------------------------------------------------
void Player::RegisterObserver(Observer* pObserver)
{
	vec_pObserver_.push_back(pObserver);
}
//-----------------------------------------------------------------
void Player::RemoveObserver(Observer* pObserver)
{
	vec_pObserver_.erase(remove(vec_pObserver_.begin(), vec_pObserver_.end(), pObserver), vec_pObserver_.end());
}
//-----------------------------------------------------------------
void Player::NotifyObservers()
{
	std::vector<Observer*>::iterator iter;
	for (iter = vec_pObserver_.begin(); iter != vec_pObserver_.end(); ++iter)
	{
		(*iter)->Update(m_score,m_live);
	}
}