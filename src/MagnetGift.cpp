#include "..\include\MagnetGift.h"
#include"Factory.h"
//-----------------------------------------------------------------
MagnetGift::MagnetGift():Gift("magmet")
{
}
//-----------------------------------------------------------------
bool MagnetGift::m_registerit = Factory::Register("magmet",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<MagnetGift>();
	});