 #include "Factory.h"
//-----------------------------------------------------------------
Factory::Factory()
{
}
//=====================================================================================
std::unique_ptr<Collectables> Factory::create(const std::string& name) {
    auto it = getMap().find(name);
    if (it == getMap().end())
        return nullptr;
    return it->second();
}

//-------------------------------------------------------------------------
bool Factory::Register(const std::string& name, std::unique_ptr<Collectables>(*func)())
 {
    getMap().emplace(name, func);
    return true;
}
//-----------------------------------------------------------------
bool RegisterCoin(const std::string& name, std::unique_ptr<Object>(*func)(sf::Vector2f, const float, const float))
{
    return false;
}