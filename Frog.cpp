#include "Frog.h"



Frog::Frog()
{
	texture.loadFromFile("cuteFrog.png");
	texture1.loadFromFile("frogJump.png");
	texture2.loadFromFile("frogBack.png");
	texture3.loadFromFile("frogLeft.png");
	texture4.loadFromFile("frogRight.png");
	for (int g = 0; g < 5; g++)
	{
		task_frog[g].setTexture(texture);
		task_frog[g].setScale(sf::Vector2f(2, 2));

	}
	buffer.loadFromFile("sound-frogger-hop.ogg");
	sound.setBuffer(buffer);
	frog.setTexture(texture);
	frog.setPosition(sf::Vector2f(225 - 16, 650 - 36));
	frog.setScale(sf::Vector2f(2, 2));
}


Frog::~Frog()
{
}

void Frog::Draw(sf::RenderWindow &window)
{
	window.draw(frog);
}

void Frog::Move(sf::Event event , int &b)
{
	if (sf::Keyboard::Key::Left == event.key.code)
	{
		if (frog.getPosition().x <= -1)
		{
			;
		}
		else {
			frog.setTexture(texture3);
			sound.play();
			frog.setScale(sf::Vector2f(2, 2));
			frog.move(-32, 0);
		}
	}
	else if (sf::Keyboard::Key::Right == event.key.code)
	{
		if (frog.getPosition().x >= 417)
		{
			;
		}
		else {
			frog.setTexture(texture4);
			sound.play();
			frog.setScale(sf::Vector2f(2, 2));
			frog.move(32, 0);
		}
	}
	else if (sf::Keyboard::Key::Up == event.key.code)
	{
		if (frog.getPosition().y <= 22 + 130)
		{
			;
		}
		else {
			frog.setTexture(texture1);
			sound.play();
			frog.setScale(sf::Vector2f(2, 2));
			frog.move(0, -33);
			b = b + 5;
		}
	}
	else if (sf::Keyboard::Key::Down == event.key.code)
	{
		if (frog.getPosition().y >= 484 + 130)
		{
			;
		}
		else {
			frog.setTexture(texture2);
			sound.play();
			frog.setScale(sf::Vector2f(2, 2));
			frog.move(0, 33);
			b = b - 5;
		}
	}
}

sf::Sprite Frog::GetShape()
{
	return frog;
}

sf::Vector2f Frog::GetPosition()
{
	return frog.getPosition();
}
void Frog::Move_with_wood(float a, float b)
{
	frog.move(b*a,0);
}

void Frog::Collide(sf::Sprite &background, sf::RenderWindow &window,int &c)
{
	background.setColor(sf::Color(255, 0, 0));
	window.clear();
	window.draw(background);
	window.draw(frog);
	window.display();
	Sleep(500);
	frog.setTexture(texture);
	background.setColor(sf::Color(255, 255, 255));
	frog.setPosition(sf::Vector2f(225 - 16, 650 - 36));
	c--;
}

void Frog::frog_task(sf::RenderWindow &window, int j)
{
	h = j;
	if (h == 0)
	{
		a = 0; b = 0; c = 0; d = 0; e = 0;
	}
	if (a == 1)
	{
			window.draw(task_frog[0]);
	}
	if (b == 1)
	{
		window.draw(task_frog[1]);
	}
	if (c == 1)
	{
		window.draw(task_frog[2]);
	}
	if (d == 1)
	{
		window.draw(task_frog[3]);
	}
	if (e == 1)
	{
		window.draw(task_frog[4]);
	}
	
}

void Frog::task_value( int &i, int &f, float &g)
{
		
	if (frog.getPosition().y == 152 || a==1 || b==1 || c==1 || d==1 ||e ==1)
	{

		if (frog.getPosition().x > 10 && frog.getPosition().x < 25 || a == 1)
		{
          task_frog[0].setPosition(sf::Vector2f(17,152));
		  a = 1;
		}
		if (frog.getPosition().x > 105 && frog.getPosition().x < 120 || b == 1)
		{
			task_frog[1].setPosition(sf::Vector2f(113, 152));
			b = 1;
		}
		if (frog.getPosition().x > 200 && frog.getPosition().x < 217 || c == 1)
		{
			task_frog[2].setPosition(sf::Vector2f(209, 152));
			c = 1;
		}
		if (frog.getPosition().x > 295 && frog.getPosition().x < 313 || d == 1)
		{
			task_frog[3].setPosition(sf::Vector2f(305, 152));
			d = 1;
		}
		if (frog.getPosition().x > 350 && frog.getPosition().x < 420 || e == 1)
		{
			task_frog[4].setPosition(sf::Vector2f(401, 152));
			e = 1;
		}
		
		if (a == 1 && b == 1 && c ==1 && d ==1 && e==1)
		{
			a = 0; b = 0; c = 0; d = 0; e = 0;
			f++;
			g = g + 1; //g=g+0.35
			i = 5;
		}
	}
	frog.setTexture(texture);
	frog.setPosition(sf::Vector2f(225 - 16, 650 - 36));
}