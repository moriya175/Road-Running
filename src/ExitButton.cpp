#include "..\include\ExitButton.h"
//-----------------------------------------------------------------
void ExitButton::execute()
{
	m_window.close();
}
//-----------------------------------------------------------------
ExitButton::ExitButton(sf::RenderWindow& window) :Command(window,"buttenexit", {70,550})
{
}


