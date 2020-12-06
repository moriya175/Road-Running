#include "..\include\Resources.h"
//-------------------------------------------------------
//הבנאי שאחראי לזימון טעינת התמונות וסוג הטקסטים
Resources::Resources()
{
	insertPicture();
	m_font.loadFromFile("C:/Windows/Fonts/Forte.ttf");
	m_coinMusic.openFromFile("coin.wav");
	m_gameMusic.openFromFile("tune.wav");
	m_impactsound.openFromFile("impactsound.wav");
	m_livetune.openFromFile("livetune.wav");
	m_gameOver.openFromFile("gameover.wav");
	m_winner.openFromFile("won.wav");
	m_boom.openFromFile("boommusic.wav");

}
//-------------------------------------------------------
//טעינת התמונות
void Resources::insertPicture()
{
	sf::Texture texture;
	std::vector<sf::Texture> vec;
	texture.loadFromFile("bg.png");
	vec.push_back(texture);
	m_picture.emplace("bg", vec);
	vec.clear();
	//coin
	texture.loadFromFile("coin1.png");
	vec.emplace_back(texture);
	texture.loadFromFile("coin2.png");
	vec.emplace_back(texture);
	texture.loadFromFile("coin3.png");
	vec.emplace_back(texture);
	texture.loadFromFile("coin4.png");
	vec.emplace_back(texture);
	texture.loadFromFile("coin5.png");
	vec.emplace_back(texture);
	texture.loadFromFile("coin6.png");
	vec.emplace_back(texture);
	m_picture.emplace("coin", vec);
	vec.clear();
	texture.loadFromFile("men1.png");
	vec.emplace_back(texture);
	texture.loadFromFile("men2.png");
	vec.emplace_back(texture);
	texture.loadFromFile("men3.png");
	vec.emplace_back(texture);
	m_picture.emplace("player", vec);
	vec.clear();
	texture.loadFromFile("menu.png");
	vec.emplace_back(texture);
	m_picture.emplace("menu", vec);
	vec.clear();
	texture.loadFromFile("start.png");
	vec.emplace_back(texture);
	m_picture.emplace("buttengame", vec);
	vec.clear();
	texture.loadFromFile("quit.png");
	vec.emplace_back(texture);
	m_picture.emplace("buttenexit", vec);
	vec.clear();
	texture.loadFromFile("1.png");
	vec.emplace_back(texture);
	m_picture.emplace("tree", vec);
	vec.clear();
	texture.loadFromFile("8.png");
	vec.emplace_back(texture);
	
	texture.loadFromFile("car.png");
	vec.emplace_back(texture);
	m_picture.emplace("car", vec);
	vec.clear();
	texture.loadFromFile("heart1.png");
	vec.emplace_back(texture);
	m_picture.emplace("heart", vec);
	vec.clear();
	texture.loadFromFile("displayLive.png");
	vec.emplace_back(texture);
	texture.loadFromFile("displayScore.png");
	vec.emplace_back(texture);
	m_picture.emplace("display", vec);
	vec.clear();
	texture.loadFromFile("magmet.png");
	vec.emplace_back(texture);
	m_picture.emplace("magmet", vec);
	vec.clear();
	texture.loadFromFile("fire.png");
	vec.emplace_back(texture);
	m_picture.emplace("fire", vec);
	vec.clear();
	texture.loadFromFile("Clear.PNG");
	vec.emplace_back(texture);
	m_picture.emplace("clear", vec);
	vec.clear();
	texture.loadFromFile("menC1.png");
	vec.emplace_back(texture);
	texture.loadFromFile("menC2.png");
	vec.emplace_back(texture);
	texture.loadFromFile("menC3.png");
	vec.emplace_back(texture);
	m_picture.emplace("menC", vec);
	vec.clear();
	texture.loadFromFile("manM1.png");
	vec.emplace_back(texture);
	texture.loadFromFile("manM2.png");
	vec.emplace_back(texture);
	texture.loadFromFile("manM3.png");
	vec.emplace_back(texture);
	m_picture.emplace("manM", vec);
	vec.clear();
	texture.loadFromFile("10.png");
	vec.emplace_back(texture);
	texture.loadFromFile("11.png");
	vec.emplace_back(texture); 
	texture.loadFromFile("12.png");
	vec.emplace_back(texture);
	m_picture.emplace("obstacle", vec);
	vec.clear();
	texture.loadFromFile("5.png");
	vec.emplace_back(texture);
	texture.loadFromFile("6.png");
	vec.emplace_back(texture);
	m_picture.emplace("signpost", vec);
	vec.clear();
	texture.loadFromFile("enemy3.png");
	vec.emplace_back(texture);
	texture.loadFromFile("enemy1.png");
	vec.emplace_back(texture);
	texture.loadFromFile("enemy6.png");
	vec.emplace_back(texture);
	m_picture.emplace("policeman", vec);
	vec.clear();
	texture.loadFromFile("sheet.png");
	vec.emplace_back(texture);
	m_picture.emplace("sheet", vec);
	vec.clear();
	texture.loadFromFile("winner.PNG");
	vec.emplace_back(texture);
	m_picture.emplace("won", vec);
	vec.clear();
	texture.loadFromFile("gameover.PNG");
	vec.emplace_back(texture);
	m_picture.emplace("gameover", vec);
	vec.clear();
	texture.loadFromFile("18.png");
	vec.emplace_back(texture);
	m_picture.emplace("18", vec);
	vec.clear();
}
//-------------------------------------------------------
//פונקציה סטטית לצורך תבנית עיצוב של סינגלטון 
Resources& Resources::getinstance()
{
	static Resources m_instence;
	return m_instence;
}
//-------------------------------------------------------