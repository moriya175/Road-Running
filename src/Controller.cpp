#include "..\include\Controller.h"
//-----------------------------------------------------------------
Controller::Controller():m_window(VideoMode(width, height), " road runing!"), m_menu(m_window,m_startNewGame), m_startNewGame(false)
{
}
//-----------------------------------------------------------------
void Controller::run()
{
	while (m_window.isOpen())
	{
		m_menu.open();
		if (m_startNewGame)
		{
			Game game(m_window);
			game.run();
			m_startNewGame = false;
		}
	}
}
