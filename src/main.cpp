#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Controller.h"
#include <memory>
//-----------------------------------------------------------------
int main()
{
    try {
        Controller c;
        c.run();
        return 0;
    }
    catch (std::exception& e)
    {
        exit(0);
    }
}