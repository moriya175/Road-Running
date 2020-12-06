#include"Tree.h"
#include"Factory.h"
//-----------------------------------------------------------------
Tree::Tree():Collectables("tree")
{
}
//-----------------------------------------------------------------
bool Tree::m_registerit = Factory::Register("tree",
	[]()-> std::unique_ptr<Collectables>
	{
		return std::make_unique<Tree>();
	});