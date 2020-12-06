#pragma once
const int width = 1024;
const int height = 768;
const int roadW = 2000;
const int segL = 200; //segment length
const float camD = 0.84; //camera depth
const int speed = 100;
const int COIN_ADDITON = 1;
const int LIVE_ADDITON = 1;
const int LIVE_REDUSE = -1;
const int LIVE = 6;
const float TIMEOFGIFT = 2;
const int TRACK_END = 250;
const int playerSpeed = 2000;
const auto POSX_PLAYER = 450;
const auto POSY_PLAYER = 500;
const auto TEXT_SIZE = 40;
const auto SPACE_TEXT = 130;
const auto LIMLEFT = 100;
const auto LIMRIGTH = 800;
const auto ITARATION = 15;
const auto ITARATION_P = 10;
const auto INDEXDEFULTE = 0;
const auto TIMEOFMASEGE = 7;
const sf::Vector2f POSITIONMAXCORE = { 200,600 };
const auto SIZENMAXCORE =100;
const auto SIZELINE = 300;
enum Behavior
{
	DELETED,
	MAGNET,
	NOTHING,
};