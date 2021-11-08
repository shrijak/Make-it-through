#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>


class Frog
{
	
public:
	Frog();
	~Frog();
    void Draw(sf::RenderWindow &);
	void frog_task(sf::RenderWindow &,int);
	void task_value(int &,int &,float &);
	void Move(sf::Event,int &);
	void Move_with_wood(float, float);
	void Collide(sf::Sprite &, sf::RenderWindow &,int &);
	sf::Sprite GetShape();
	sf::Vector2f GetPosition();

private:
	sf::Texture texture, texture1, texture2, texture3, texture4;
	sf::Sprite frog,task_frog[5];
	sf::SoundBuffer buffer;
	sf::Sound sound;
	int a = 0, b = 0, c = 0, d = 0, e = 0,h=0;
};

