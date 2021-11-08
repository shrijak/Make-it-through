#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>

class Obstacle
{
public:
	Obstacle(sf::Sprite &,float,float,int);
	~Obstacle();
	void Draw(sf::RenderWindow &window);
	void Move(sf::Vector2u,float &);
	void SetPosition();
	sf::Sprite GetShape();

private:
	sf::Sprite obstacle;
	int dir;
	float posY,posX;
};

