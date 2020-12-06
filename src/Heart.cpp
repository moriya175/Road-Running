#include "..\include\Heart.h"
#include"Factory.h"
//-----------------------------------------------------------------
Heart::Heart():Gift("heart")
{}
//-----------------------------------------------------------------
bool Heart::m_registerit = Factory::Register("Heart",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<Heart>();
	});
