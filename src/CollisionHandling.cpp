#pragma once
#include "CollisionHandling.h"
#include "Player.h"
#include "Coin.h"
#include "Heart.h"
#include "utilitiy.h"
#include <iostream>
#include <map>
#include <typeinfo> 
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Car.h"
#include "Tree.h"
#include"CurrencyMovement.h"
#include"TransparencyGift.h"
#include"MagnetGift.h"
#include "Obstacle.h"
#include "Signpost.h"
#include"Sheet.h"
namespace {
    //----------------------------------------------------------------------------------------
    Behavior playerCoin(Object& player, Object& coin)
    {
        Resources::getinstance().m_coinMusic.stop();
        Player& ast = dynamic_cast<Player&>(player);
        ast.addScore(COIN_ADDITON);
        Resources::getinstance().m_coinMusic.play();
        return DELETED;
    }
    //-----------------------------------------------------------------
    Behavior playerClear(Object& player, Object& clear)
    {
        Player& ast = dynamic_cast<Player&>(player);
        ast.setClear();
        return DELETED;
    }
    //-----------------------------------------------------------------
    Behavior playerMagnet(Object& player, Object& magnet)
    {
        Player& ast = dynamic_cast<Player&>(player);
        ast.setMagnet();
        return MAGNET;
    }
    //-----------------------------------------------------------------
    Behavior playerLive(Object& player, Object& live)
    {
        Resources::getinstance().m_livetune.stop();
        Player& ast = dynamic_cast<Player&>(player);
        ast.addLive(LIVE_ADDITON);
        Resources::getinstance().m_livetune.play();
        return DELETED;
    }
    //-----------------------------------------------------------------
    Behavior playerCar(Object& player, Object& car)
    {
        Player& ast = dynamic_cast<Player&>(player);
        if(!(ast.isClear())){
            Resources::getinstance().m_impactsound.stop();
            ast.addLive(LIVE_REDUSE);
            Resources::getinstance().m_impactsound.play();
        }
        return NOTHING;
    }
    //-----------------------------------------------------------------
    Behavior playerFire(Object& player, Object& fire)
    {
        Player& ast = dynamic_cast<Player&>(player);
        if (!(ast.isClear())) {
            ast.addLive(LIVE_REDUSE);
        }
        return NOTHING;
    }
    //-----------------------------------------------------------------
    Behavior colidenothing(Object& player, Object& tree)
    {
        return NOTHING;
    }
    //-----------------------------------------------------------------
    Behavior MovementCoin(Object& Movement, Object& coin)
    {
         CurrencyMovement& movecoin = dynamic_cast<CurrencyMovement&>(Movement);
         Coin& c = dynamic_cast<Coin&>(coin);
         c.move(movecoin.m_position);
         return NOTHING;
    }
    Behavior playerSheet(Object& player, Object& sheet)
    {
        Player& ast = dynamic_cast<Player&>(player);
        if (!(ast.isClear())) {
            Resources::getinstance().m_boom.stop();
            ast.addLive(LIVE_REDUSE);
            Resources::getinstance().m_boom.play();
            Sheet& s = dynamic_cast<Sheet&>(sheet);
            s.colidePlayer();
        }
        return NOTHING;
    }
    //-----------------------------------------------------------------
    Behavior playerMovement(Object& player, Object& Movement)
    {
        Player& ast = dynamic_cast<Player&>(player);
        CurrencyMovement& movecoin = dynamic_cast<CurrencyMovement&>(Movement);
        movecoin.m_position = ast.getPosition();
        return NOTHING;
    }
    //---------------------------------------------------------------------------------------
    using HitFunctionPtr = Behavior(*)(Object&, Object&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;
    //--------------------------------------------------------------------------------------------------
    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(Sheet))] = &playerSheet;
        phm[Key(typeid(Player), typeid(Coin))] = &playerCoin;
        phm[Key(typeid(Player), typeid(Heart))] = &playerLive;
        phm[Key(typeid(Player), typeid(Car))] = &playerCar;
        phm[Key(typeid(Player), typeid(Tree))] = &colidenothing;
        phm[Key(typeid(Player), typeid(Obstacle))] = &playerCar;
        phm[Key(typeid(Player), typeid(TransparencyGift))] = &playerClear;
        phm[Key(typeid(Player), typeid(MagnetGift))] = &playerMagnet;
        phm[Key(typeid(Player), typeid(CurrencyMovement))] = &playerMovement;
        phm[Key(typeid(CurrencyMovement), typeid(Coin))] = &MovementCoin;
        phm[Key(typeid(CurrencyMovement), typeid(Heart))] = &colidenothing;
        phm[Key(typeid(CurrencyMovement), typeid(Car))] = &colidenothing;
        phm[Key(typeid(CurrencyMovement), typeid(Tree))] = &colidenothing;
        phm[Key(typeid(CurrencyMovement), typeid(Obstacle))] = &colidenothing;
        phm[Key(typeid(CurrencyMovement), typeid(MagnetGift))] = &colidenothing;
        phm[Key(typeid(CurrencyMovement), typeid(TransparencyGift))] = &colidenothing;
        phm[Key(typeid(CurrencyMovement), typeid(Signpost))] = &colidenothing;
        phm[Key(typeid(Player), typeid(Signpost))] = &colidenothing;
        return phm;
    }
    //-------------------------------------------------------------------------------------------------------
    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }
} // end namespace
//------------------------------------------------------------------------------------------------------
Behavior processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    else return phf(object1, object2);
}