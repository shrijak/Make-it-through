#include "Obstacle.h"
#include<iostream>
Obstacle::Obstacle(sf::Sprite &obstacle,float posX, float posY,int dir)
{
	this->dir = dir;
	
	if (dir == 1)
	{
		obstacle.setPosition(sf::Vector2f(posX, posY));
		obstacle.setScale(sf::Vector2f(2, 2));
		this->obstacle = obstacle;
		this->posY = posY;
		this->posX = posX;
	}
	else if (dir == -1)
	{
		obstacle.setPosition(sf::Vector2f(450-posX, posY));
		obstacle.setScale(sf::Vector2f(2, 2));
		this->obstacle = obstacle;
		this->posY = posY;
		this->posX = posX;
	}
}
Obstacle::~Obstacle()
{
}

void Obstacle::Draw(sf::RenderWindow &window)
{
	window.draw(obstacle);
}

void Obstacle::Move(sf::Vector2u size,float &d)
{
	int a = 2 * (obstacle.getTexture()->getSize().x);
	if (dir == 1)
	{
		
		if (obstacle.getPosition().x > size.x)
		{
			obstacle.setPosition(sf::Vector2f(-a, posY));
		}
		else
		{
			obstacle.move(d*0.3*0.1, 0);
		}
	}
	else if (dir == -1)
	{
		
		if (obstacle.getPosition().x <-a)
		{
			obstacle.setPosition(sf::Vector2f(size.x+a,posY));
		}
		else
		{
			obstacle.move(-d*0.3*0.1, 0);
		}
	}
}

sf::Sprite Obstacle::GetShape()
{
	return obstacle;
}

void Obstacle::SetPosition()
{
	obstacle.setPosition(sf::Vector2f(0, 580));
}