#include "..\include\Menu.h"
//-----------------------------------------------------------------
Menu::Menu(sf::RenderWindow& window, bool& startNewGame):m_window(window)
{
	m_act.emplace_back(std::make_unique<ExitButton>(m_window));
	m_act.emplace_back(std::make_unique<NewGameButton>(m_window,startNewGame));
    auto it = Resources::getinstance().m_picture.find("menu");
    if (it == Resources::getinstance().m_picture.end())
		throw std::exception("");
	auto& vec = it->second;
    m_bgmenu = sf::Sprite(vec[0]);
}
//-----------------------------------------------------------------
void Menu::open()
{
	draw();
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				throw std::exception("");
			case sf::Event::MouseButtonPressed:
				sf::Vector2f vec;
				vec = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				for (size_t i = 0; i < m_act.size(); i++)
				{
					if (m_act[i]->isInRect(vec)) {
						m_act[i]->execute();
						return;
					}
				}
				break;
			}
		}
		m_window.clear();
		draw();
		m_window.display();
	}
}
//-----------------------------------------------------------------
void Menu::draw()
{
    m_window.draw(m_bgmenu);
    for (auto &i : m_act)
        i->draw(m_window);
}
