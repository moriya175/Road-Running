#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include"Collectables.h"
class Factory;

class Gift:public Collectables
{
public:
	Gift(const std::string& str);
	virtual ~Gift() = default;
private:
};