#pragma once
#include "Frog.h"
#include "Obstacle.h"
#include <iostream> 
#include <fstream>

class Game
{
public:
	Game();
	~Game();

	void Loop();

private:
	sf::RenderWindow *window;
	Frog *frog;
	Obstacle *car,*car1,*car2,*tractor,*truck,*snake,*wood[3], *wood1[3], *wood2[3], *wood3[3], *wood4[3], *wood5[3];
	sf::Texture texture,texture1,texture2,texture3,texture4,texture5,texture6,texture7,texture8,texture9;
	sf::Sprite obstacle,obstacle1, obstacle2, obstacle3, obstacle4,obstacle5,background,woodsprite,start,extra;
	sf::SoundBuffer buffer, buffer1,buffer2;
	sf::Sound sound, sound1,sound2;
	sf::Font font;
	sf::Text score, score1, life, life1,level,level1,over,high,high1;
	int a =0; //start menu loop control
	int b =0; //score
	int c =5; //life
	float d =1.5;  //d=1.5 speed
	int e = 1; //level
	int highscore;
	int rx;
	int ry;
	std::ifstream ifile;
	std::ofstream ofile;
};