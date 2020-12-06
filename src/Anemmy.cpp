#include "..\include\Anemmy.h"
//-----------------------------------------------------------------
bool Anemmy::isCollide(Object& object)
{
	if (m_isCollid) return false;
	return(m_isCollid = Object::isCollide(object));
}