
#include "..\include\TransparencyGift.h"
#include"Factory.h"
//-----------------------------------------------------------------
TransparencyGift::TransparencyGift():Gift("clear")
{
}
//-----------------------------------------------------------------
bool TransparencyGift::m_registerit = Factory::Register("clear",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<TransparencyGift>();
	});