#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(450, 650), "Make It Through");
	texture.loadFromFile("car.png");
	obstacle.setTexture(texture);
	texture1.loadFromFile("car1.png");
	obstacle1.setTexture(texture1);
	texture2.loadFromFile("tractor.png");
	obstacle2.setTexture(texture2);
	texture3.loadFromFile("car2.png");
	obstacle3.setTexture(texture3);
	texture4.loadFromFile("truck.png");
	obstacle4.setTexture(texture4);
	texture5.loadFromFile("snake.png");
	obstacle5.setTexture(texture5);
    texture6.loadFromFile("background.png");
	background.setTexture(texture6);
	background.move(0, 130);
	texture7.loadFromFile("wood.png");
	woodsprite.setTexture(texture7);
	texture8.loadFromFile("start_page.jpg");
	start.setTexture(texture8);
	texture9.loadFromFile("life.png");
	extra.setTexture(texture9);
	buffer.loadFromFile("sound-frogger-squash.wav");
	sound.setBuffer(buffer);
	buffer1.loadFromFile("sound-frogger-plunk.wav");
	sound1.setBuffer(buffer1);
	buffer2.loadFromFile("sound-frogger-hop.ogg");
	sound2.setBuffer(buffer2);
	font.loadFromFile("Abduction.ttf");
	score.setFont(font);
	score.setString("SCORE");
	score.setCharacterSize(40);
	score.move(10, 0);
	score1.setFont(font);
	score1.setCharacterSize(40);
	score1.move(10, 60);
	life.setFont(font);
	life.setString("LIFE LEFT");
	life.setCharacterSize(40);
	life.move(240, 0);
	life1.setFont(font);
	life1.setCharacterSize(40);
	life1.move(340, 60);
	level.setFont(font);
	level.setString("LEVEl");
	level.setCharacterSize(20);
	level.move(155, 0);
	level1.setFont(font);
	level1.setCharacterSize(20);
	level1.move(175, 30);
	high.setFont(font);
	high.setString("High Score");
	high.setCharacterSize(40);
	high.move(210, 0);
	high1.setFont(font);
	high1.setCharacterSize(40);
	high1.move(340, 60);
	over.setFont(font);
	over.setString("GAME OVER");
	over.setCharacterSize(75);
	over.move(10, 200);
	ifile.open("Highscore.txt");
	if (ifile.is_open())
	{
		while (!ifile.eof())
		{
			ifile >> highscore;
		}
	}
	ifile.close();
	frog = new Frog;
    car = new Obstacle(obstacle,0,580,1);
	car1 = new Obstacle(obstacle1,100,550,-1);
	tractor = new Obstacle(obstacle2,150,520, 1);
	car2 = new Obstacle(obstacle3,205,490, -1);
	truck = new Obstacle(obstacle4,275, 460, 1);
	snake = new Obstacle(obstacle5, 112, 430, -1);
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		wood[i] = new Obstacle(woodsprite, 0 + j, 350, 1);
		j = j + 160;
	}
	int j1 = 0;
	for (int i1 = 0; i1 < 3; i1++)
	{
		wood1[i1] = new Obstacle(woodsprite, 100 + j1, 320, -1);
		j1 = j1 + 160;
	}
	int j2 = 0;
	for (int i2 = 0; i2 < 3; i2++)
	{
		wood2[i2] = new Obstacle(woodsprite, 150 + j2, 290, 1);
		j2 = j2 + 160;
	}
	int j3 = 0;
	for (int i3 = 0; i3 < 3; i3++)
	{
		wood3[i3] = new Obstacle(woodsprite, 200 + j3, 260, -1);
		j3 = j3 + 160;
	}
	int j4 = 0;
	for (int i = 0; i < 3; i++)
	{
		wood4[i] = new Obstacle(woodsprite, 150 + j4, 230, 1);
		j4 = j4 + 160;
	}
	int j5 = 0;
	for (int i5 = 0; i5 < 3; i5++)
	{
		wood5[i5] = new Obstacle(woodsprite, 250 + j5, 200, -1);
		j5 = j5 + 160;
	}
}


Game::~Game()
{
}

void Game::Loop()
{
	while (window->isOpen())
	{
		while (a == 0)
		{
			window->clear();
			window->draw(start);
			window->display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				sound2.play();
				Sleep(500);
				a = 1;
			}
		}
		sf::Event event;
        while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				close:
				window->close();
				break;

			case sf::Event::KeyReleased:

				frog->Move(event,b);

				break;

			default:
				break;
			}
		}
		while (c == 0)
		{
			ofile.open("Highscore.txt");
			if (ofile.is_open())
			{
				if (b > highscore)
				{
					highscore = b;
				}
				ofile << highscore;
			}
			ofile.close();
			high1.setString(std::to_string(highscore));
			window->clear();
			window->draw(over);
			window->draw(score);
			window->draw(score1);
			window->draw(high);
			window->draw(high1);
			window->display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				sound2.play();
				Sleep(500);
				a = 0;
				b = 0;
				c = 5;
				d = 1.5;
				e = 1;
			}
		}
		score1.setString(std::to_string(b));
		life1.setString(std::to_string(c));
		level1.setString(std::to_string(e));
		car->Move(window->getSize(),d);
		car1->Move(window->getSize(),d);
		tractor->Move(window->getSize(),d);
		car2->Move(window->getSize(),d);
		truck->Move(window->getSize(),d);
		snake->Move(window->getSize(),d);
		rx = (std::rand() % 15) + 40;
		ry = (std::rand() % 15) + 40;
		for (int l = 0; l < 3; l++)
		{
			wood[l]->Move(window->getSize(),d);

		}
		for (int l1 = 0; l1 < 3; l1++)
		{
			wood1[l1]->Move(window->getSize(),d);

		}
		for (int l2 = 0; l2 < 3; l2++)
		{
			wood2[l2]->Move(window->getSize(),d);

		}
		for (int l3 = 0; l3 < 3; l3++)
		{
			wood3[l3]->Move(window->getSize(),d);

		}
		for (int l4 = 0; l4 < 3; l4++)
		{
			wood4[l4]->Move(window->getSize(),d);

		}
		for (int l5 = 0; l5 < 3; l5++)
		{
			wood5[l5]->Move(window->getSize(),d);

		}
		if (frog->GetShape().getGlobalBounds().intersects(car->GetShape().getGlobalBounds()))
		{
			if (frog->GetPosition().y >= 614 || frog->GetPosition().y <= 548) {
				;
			}
			else {
				sound.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetShape().getGlobalBounds().intersects(car1->GetShape().getGlobalBounds()))
		{
			if (frog->GetPosition().y >= 581 || frog->GetPosition().y <= 515) {
				;
			}
			else {
				sound.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetShape().getGlobalBounds().intersects(tractor->GetShape().getGlobalBounds()))
		{
			if (frog->GetPosition().y >= 548 || frog->GetPosition().y <= 482) {
				;
			}
			else {
				sound.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetShape().getGlobalBounds().intersects(car2->GetShape().getGlobalBounds()))
		{
			if (frog->GetPosition().y >= 515 || frog->GetPosition().y <= 449) {
				;
			}
			else {
				sound.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetShape().getGlobalBounds().intersects(truck->GetShape().getGlobalBounds()))
		{
			if (frog->GetPosition().y >= 482 || frog->GetPosition().y <= 416) {
				;
			}
			else {
				sound.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetShape().getGlobalBounds().intersects(snake->GetShape().getGlobalBounds()))
		{
			if (frog->GetPosition().y >= 449 || frog->GetPosition().y <= 383) {
				;
			}
			else {
				sound.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetPosition().y > 317 && frog->GetPosition().y < 383)
		{
			if (frog->GetShape().getGlobalBounds().intersects(wood[0]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood[1]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood[2]->GetShape().getGlobalBounds())) {
				frog->Move_with_wood(d*0.3*0.1, 1);
			}
			else
			{
				sound1.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetPosition().y > 284 && frog->GetPosition().y < 350)
		{
			if (frog->GetShape().getGlobalBounds().intersects(wood1[0]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood1[1]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood1[2]->GetShape().getGlobalBounds())) {
				frog->Move_with_wood(d*0.3*0.1, -1);
			}
			else
			{
				sound1.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetPosition().y > 251 && frog->GetPosition().y < 317)
		{
			if (frog->GetShape().getGlobalBounds().intersects(wood2[0]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood2[1]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood2[2]->GetShape().getGlobalBounds())) {
				frog->Move_with_wood(d*0.3*0.1, 1);
			}
			else
			{
				sound1.play();
				frog->Collide(background, *window,c);
				car->SetPosition();
			}
		}
		else if (frog->GetPosition().y >218  && frog->GetPosition().y < 284)
		{
		if (frog->GetShape().getGlobalBounds().intersects(wood3[0]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood3[1]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood3[2]->GetShape().getGlobalBounds())) {
			frog->Move_with_wood(d*0.3*0.1, -1);
		}
		else
		{
			sound1.play();
			frog->Collide(background, *window,c);
			car->SetPosition();
		}
		}
		else if (frog->GetPosition().y > 185 && frog->GetPosition().y < 251)
		{
		if (frog->GetShape().getGlobalBounds().intersects(wood4[0]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood4[1]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood4[2]->GetShape().getGlobalBounds())) {
			frog->Move_with_wood(d*0.3*0.1, 1);
		}
		else
		{
			sound1.play();
			frog->Collide(background, *window,c);
			car->SetPosition();
		}
		}
		else if (frog->GetPosition().y > 152 && frog->GetPosition().y < 218)
		{
		if (frog->GetShape().getGlobalBounds().intersects(wood5[0]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood5[1]->GetShape().getGlobalBounds()) || frog->GetShape().getGlobalBounds().intersects(wood5[2]->GetShape().getGlobalBounds())) {
			frog->Move_with_wood(d*0.3*0.1, -1);
		}
		else
		{
			sound1.play();
			frog->Collide(background, *window,c);
			car->SetPosition();
		}
		}
		else if (frog->GetPosition().y == 152)
		{
		if ((frog->GetPosition().x > 10 && frog->GetPosition().x < 25)|| (frog->GetPosition().x > 105 && frog->GetPosition().x < 120) || (frog->GetPosition().x > 200 && frog->GetPosition().x < 217) || (frog->GetPosition().x > 295 && frog->GetPosition().x < 313) || (frog->GetPosition().x > 350 && frog->GetPosition().x < 420))
		    {
			frog->task_value(c,e,d);
			}
		else
		{
			sound1.play();
			frog->Collide(background, *window, c);
			car->SetPosition();
		}
        }
		window->clear();
		window->draw(background);
		for (int k = 0; k < 3; k++)
		{
			wood[k]->Draw(*window);
		}
		for (int k1 = 0; k1 < 3; k1++)
		{
			wood1[k1]->Draw(*window);
		}
		for (int k2 = 0; k2 < 3; k2++)
		{
			wood2[k2]->Draw(*window);
		}
		for (int k3 = 0; k3 < 3; k3++)
		{
			wood3[k3]->Draw(*window);
		}
		for (int k4 = 0; k4 < 3; k4++)
		{
			wood4[k4]->Draw(*window);
		}
		for (int k5 = 0; k5 < 3; k5++)
		{
			wood5[k5]->Draw(*window);
		}
		frog->Draw(*window);
		frog->frog_task(*window,b);
		car->Draw(*window);
		car1->Draw(*window);
		tractor->Draw(*window);
		car2->Draw(*window);
		truck->Draw(*window);
		snake->Draw(*window);
		window->draw(score);
		window->draw(score1);
		window->draw(life);
		window->draw(life1);
		window->draw(level);
		window->draw(level1);
        window->display();
}
}