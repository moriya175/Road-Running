#include "..\include\NewGameButton.h"
//-----------------------------------------------------------------
void NewGameButton::execute()
{
	m_startNewGame = true;
}
//-----------------------------------------------------------------
NewGameButton::NewGameButton(sf::RenderWindow& window, bool &startNewGame) :Command(window,"buttengame", {650,550}),m_startNewGame(startNewGame)
{
}