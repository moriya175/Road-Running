#pragma once
#include <iostream>
#include "Collectables.h"
#include <map>
#include <sfml/Graphics.hpp>
#include <functional>
#include <algorithm>
typedef std::map<std::string, std::unique_ptr<Collectables>(*)()> myMap;
class Factory
{
protected:
	static myMap& getMap()
	{
		static myMap  m_creationOptions;
		return m_creationOptions;
	}
	Factory();
public:
	static std::unique_ptr<Collectables> create(const std::string& name);
	static bool Register(const std::string& name, std::unique_ptr<Collectables>(*func)());
}; 
