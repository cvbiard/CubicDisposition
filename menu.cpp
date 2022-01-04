#include "menu.h"

Menu::Menu()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
	this->initButton();
	this->initMouseBox();
	this->game.initText(this->window);
	this->game.initFlash(this->window->getSize().x, this->window->getSize().y);
	this->game.initWindowSize(this->window->getSize().x, this->window->getSize().y);
	this->game.initScore();


}
Menu::~Menu()
{
	delete this->window;
}

void Menu::initVariables()
{
	this->window = nullptr;
}
void Menu::initWindow()
{

	this->window = new RenderWindow(VideoMode(), "Cubic Disposition", Style::Fullscreen);

	this->window->setFramerateLimit(this->framerate);
	
}
void Menu::initFont()
{
	if (!this->font.loadFromFile("Resources/Fonts/EOG.otf"))
	{
		cout << "Couldn't Load" << endl;
	}
	else
	{
		cout << "Loaded" << endl;
	}
}
void Menu::initText()
{
	this->text.setFont(this->font);
	this->text.setCharacterSize(48);
	this->text.setFillColor(Color::White);
	this->text.setString("Play");
	this->text.setOrigin(this->text.getGlobalBounds().width/2, this->text.getGlobalBounds().height / 2);
	this->text.setPosition(Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));


	this->title.setFont(this->font);
	this->title.setCharacterSize(128);
	this->title.setFillColor(Color::White);
	this->title.setString("CUBIC DISPOSITION");
	this->title.setOrigin(this->title.getGlobalBounds().width / 2, this->title.getGlobalBounds().height / 2);
	this->title.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2)- (this->window->getSize().y / 4)));

	this->options.setFont(this->font);
	this->options.setCharacterSize(48);
	this->options.setFillColor(Color::White);
	this->options.setString("Options");
	this->options.setOrigin(this->options.getGlobalBounds().width / 2, this->options.getGlobalBounds().height / 2);
	this->options.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));

	this->exit.setFont(this->font);
	this->exit.setCharacterSize(48);
	this->exit.setFillColor(Color::White);
	this->exit.setString("Exit");
	this->exit.setOrigin(this->exit.getGlobalBounds().width / 2, this->exit.getGlobalBounds().height / 2);
	this->exit.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2) + 2*(this->window->getSize().y / 10)));
}

void Menu::update()
{

	this->game.updateFrameClock(this->framerate);
	//this->game.updateTimeClock();
	if (this->game.frameClock == 0 || this->game.frameClock == 30)
	{
		this->game.testBomb();
		this->game.testRange();
		this->game.testShield();
		this->game.testLife();
		this->game.testCollision();
	}
	

	switch (this->state)
	{
	case 0:
		if (this->game.Kick.getStatus() == Music::Playing)
		{
			this->game.KickTail.stop();
			this->game.Lead1Tail.stop();
			this->game.Lead2Tail.stop();
			this->game.Lead3Tail.stop();

			this->game.KickTail.setVolume(0.f);
			this->game.Lead1Tail.setVolume(0.f);
			this->game.Lead2Tail.setVolume(0.f);
			this->game.Lead3Tail.setVolume(0.f);

			this->game.BassSynth.stop();
			this->game.Lead1.stop();
			this->game.Lead2.stop();
			this->game.Lead3.stop();
			this->game.Pad.stop();
			this->game.Kick.stop();
		}
		this->game.life = 3;
		this->game.timeClock = 0;
		
		this->pollEvents();
		this->updateText();
		this->updateMouseBox();
		this->randomizeSpawns();
		break;
	case 1:
		
		this->pollEvents();
		this->updateRand();

		this->game.playTrack();
		this->game.updateBeatClock();
		this->game.enemyUpdate(this->window->getSize().x, this->window->getSize().y, this->reg);
		this->game.shieldUpdate(this->reg);
		this->game.updateFlash(this->reg);
		this->game.updateTimeClock();
		this->game.scoreUpdate(this->reg, this->framerate);
		this->game.collision();
		this->game.bomb.updateBomb(this->reg);

		if (this->game.life <= 0)
		{
			cout << "You're trast bro u lose" << endl;
			this->state = 0;
			for (int i = 0; i < this->game.basicCount; i++)
			{
				this->game.basic[i].isDrawn = false;
			}
			for (int i = 0; i < this->game.homingCount; i++)
			{
				this->game.homing[i].isDrawn = false;
			}
			for (int i = 0; i < this->game.healthCount; i++)
			{
				this->game.health[i].isDrawn = false;
			}
			for (int i = 0; i < this->game.areaCount; i++)
			{
				this->game.area[i].isDrawn = false;
			}
			for (int i = 0; i < this->game.shooterCount; i++)
			{
				this->game.shooter[i].isDrawn = false;
			}
			this->game.life = 3;
			this->game.score = 0;
			this->game.updateText();
		}
		
		this->updateText();
		break;

	}

}
void Menu::render()
{
	
	
	switch (this->state)
	{
	case 0:
		this->window->clear();
		//this->window->draw(this->button);
		this->window->draw(this->text);
		this->window->draw(this->title);
		this->window->draw(this->options);
		this->window->draw(this->exit);
		//this->window->draw(this->optionsButton);
		this->window->draw(this->mouseBox);
		break;
	case 1:
		this->window->clear();
		this->window->draw(this->game.flash);
		this->window->draw(this->game.character);
	
		this->window->draw(this->game.bomb.visual);
		this->window->draw(this->game.bomb.square1);
		this->window->draw(this->game.bomb.square2);
		this->window->draw(this->game.bomb.square3);
		
		
		if (this->game.life >= 3)
		{
			this->window->draw(this->game.tail1);
		}
		if (this->game.life >= 2)
		{
			this->window->draw(this->game.tail2);
		}
		if (this->game.life >= 1)
		{
			this->window->draw(this->game.tail3);
		}


		for (int i = 0; i < this->game.basicCount; i++)
		{
			if (this->game.basic[i].isDrawn == true)
			{
				this->window->draw(this->game.basic[i]);
				this->window->draw(this->game.basic[i].tail1);
				this->window->draw(this->game.basic[i].tail2);
				this->window->draw(this->game.basic[i].tail3);
			}
		}
		for (int i = 0; i < this->game.homingCount; i++)
		{
			if (this->game.homing[i].isDrawn == true)
			{
				this->window->draw(this->game.homing[i]);
				this->window->draw(this->game.homing[i].tail1);
				this->window->draw(this->game.homing[i].tail2);
				this->window->draw(this->game.homing[i].tail3);
			}
		}
		for (int i = 0; i < this->game.healthCount; i++)
		{
			if (this->game.health[i].isDrawn == true)
			{
				this->window->draw(this->game.health[i]);

				this->window->draw(this->game.health[i].tail1);
				this->window->draw(this->game.health[i].tail2);
				this->window->draw(this->game.health[i].tail3);

				this->window->draw(this->game.health[i].sprite);
			}
		}
		for (int i = 0; i < this->game.areaCount; i++)
		{
			if (this->game.area[i].isDrawn == true)
			{
				this->window->draw(this->game.area[i]);

				this->window->draw(this->game.area[i].tail1);
				this->window->draw(this->game.area[i].tail2);
				this->window->draw(this->game.area[i].tail3);

			}
		}
		for (int i = 0; i < this->game.shooterCount; i++)
		{
			if (this->game.shooter[i].isDrawn == true)
			{
				this->window->draw(this->game.shooter[i]);

				this->window->draw(this->game.shooter[i].tail1);
				this->window->draw(this->game.shooter[i].tail2);
				this->window->draw(this->game.shooter[i].tail3);

			}
		}
			
		this->window->draw(this->game.uiText);
		
		break;
	}
	
	this->window->display();
}
void Menu::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->state)
		{
		case 0:
			switch (this->ev.type)
			{
			case Event::Closed:
				this->window->close();
				break;

			case Event::KeyPressed:
				std::cout << "Key Pressed: " << this->ev.key.code << std::endl;
				if (this->ev.key.code == Keyboard::Escape)
				{
					this->window->close();
				}
				break;
			case Event::MouseButtonPressed:
				this->checkClick();
				break;

			}
			break;
		case 1:
			this->game.tail3.setPosition(Vector2f((Mouse::getPosition())) - Vector2f((playerYSize / 128) - 4.f, (playerYSize / 128) - ((playerYSize) / 4) - 2.f));
			this->game.tail2.setPosition(Vector2f((Mouse::getPosition())) - Vector2f((playerYSize / 128) - 4.f, (playerYSize / 128) - ((playerYSize) / 4) - 2.f));
			this->game.tail1.setPosition(Vector2f((Mouse::getPosition())) - Vector2f((playerYSize / 128) - 4.f, (playerYSize / 128) - ((playerYSize) / 4) - 2.f));
			this->game.character.setPosition(Vector2f((Mouse::getPosition())) - Vector2f((playerYSize / 128) - ((playerYSize) / 4), (playerYSize / 128) - ((playerYSize) / 4)));


			if (this->game.character.getPosition().x <= 0)
			{
				this->game.character.setPosition(Vector2f(0.f, this->game.character.getPosition().y));
			}
			if (this->game.character.getPosition().x >= this->window->getSize().x)
			{
				this->game.character.setPosition(Vector2f(this->window->getSize().x, this->game.character.getPosition().y));
			}
			if (this->game.character.getPosition().y <= 0)
			{
				this->game.character.setPosition(Vector2f(this->game.character.getPosition().x, 0.f));
			}
			if (this->game.character.getPosition().y >= this->window->getSize().y)
			{
				this->game.character.setPosition(Vector2f(this->game.character.getPosition().x, this->window->getSize().y));
			}

			if (this->game.jitter == true)
			{
				switch (this->game.jitterCount % 2)
				{
				case 0:
					this->game.character.setPosition(this->game.character.getPosition().x + this->game.jitterSize, this->game.character.getPosition().y);
					this->game.jitterCount = this->game.jitterCount + 1;
					break;
				case 1:
					this->game.character.setPosition(this->game.character.getPosition().x - this->game.jitterSize, this->game.character.getPosition().y);
					this->game.jitterCount = this->game.jitterCount + 1;
					break;
				}

				if (this->game.jitterCount >= 50)
				{
					this->game.jitterCount = 0;
					this->game.jitter = false;
				}
			}

			switch (this->ev.type)
			{
			case Event::Closed:
				this->window->close();
				break;

			case Event::KeyPressed:
				std::cout << "Key Pressed: " << this->ev.key.code << std::endl;
				if (this->ev.key.code == Keyboard::Escape)
				{
					this->window->close();
				}
				break;
			case Event::MouseButtonPressed:
				if (this->game.bomb.dropped != true && this->game.bomb.explode != true)
				{
					this->game.DropBomb.play();
					this->game.bomb.dropped = true;
				}
				break;
			
			}
		}
		
	}
}
void Menu::initButton()
{
	this->button.setSize(Vector2f(this->text.getGlobalBounds().width *1.5, this->text.getGlobalBounds().height * 1.5));
	this->button.setFillColor(Color(255, 0, 0, 32));
	this->button.setOrigin(this->button.getGlobalBounds().width / 2, this->button.getGlobalBounds().height / 2);
	this->button.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2)+10));


	this->optionsButton.setSize(Vector2f(this->options.getGlobalBounds().width * 1.5, this->options.getGlobalBounds().height * 1.5));
	this->optionsButton.setFillColor(Color(255, 0, 0, 32));
	this->optionsButton.setOrigin(this->optionsButton.getGlobalBounds().width / 2, this->optionsButton.getGlobalBounds().height / 2);
	this->optionsButton.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));

	this->exitButton.setSize(Vector2f(this->exit.getGlobalBounds().width * 1.5, this->exit.getGlobalBounds().height * 1.5));
	this->exitButton.setFillColor(Color(255, 0, 0, 32));
	this->exitButton.setOrigin(this->exitButton.getGlobalBounds().width / 2, this->exitButton.getGlobalBounds().height / 2);
	this->exitButton.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2) + 2*(this->window->getSize().y / 10)));

}
void Menu::checkClick()
{

	if (this->button.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		this->game.Start.play();
		this->state = 1;
	}
	if (this->options.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		//this->state = 2;
	}
	if (this->exit.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		this->window->close();
	}
}
void Menu::initMouseBox()
{
	this->mouseBox.setPosition(Vector2f(Mouse::getPosition()));

	this->mouseBox.setSize(Vector2f(playerYSize * 1.4, playerXSize * 1.4));
	this->mouseBox.setOrigin(Vector2f(this->mouseBox.getSize().x / 2, this->mouseBox.getSize().y / 2));
	this->mouseBox.setFillColor(Color(255, 0, 255, 0));
}
void Menu::updateMouseBox()
{
	this->mouseBox.setPosition(Vector2f((Mouse::getPosition())) - Vector2f((playerYSize / 128) - ((playerYSize) / 4), (playerYSize / 128) - ((playerYSize) / 4)));
}
void Menu::renderText()
{

}
void Menu::updateText() 
{
	if (this->button.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		if (this->mouseCollide == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollide = true;
			}
		}
		
		this->button.setScale(1.2, 1.2);
		this->text.setScale(1.2, 1.2);

	}
	else
	{
		//this->button.setSize(Vector2f(this->text.getGlobalBounds().width * 1.5, this->text.getGlobalBounds().height * 1.5));
		this->button.setScale(1, 1);
		this->text.setScale(1, 1);
		this->mouseCollide = false;
	}

	if (this->optionsButton.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		if (this->mouseCollideO == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollideO = true;
			}
		}

		this->optionsButton.setScale(1.2, 1.2);
		this->options.setScale(1.2, 1.2);

	}
	else
	{
		//this->button.setSize(Vector2f(this->text.getGlobalBounds().width * 1.5, this->text.getGlobalBounds().height * 1.5));
		this->optionsButton.setScale(1, 1);
		this->options.setScale(1, 1);
		this->mouseCollideO = false;
	}

	if (this->exitButton.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		if (this->mouseCollideE == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollideE = true;
			}
		}

		this->exitButton.setScale(1.2, 1.2);
		this->exit.setScale(1.2, 1.2);

	}
	else
	{
		//this->button.setSize(Vector2f(this->text.getGlobalBounds().width * 1.5, this->text.getGlobalBounds().height * 1.5));
		this->exitButton.setScale(1, 1);
		this->exit.setScale(1, 1);
		this->mouseCollideE = false;
	}
}
const bool Menu::running() const
{
	return this->window->isOpen();
}
void Menu::updateRand()
{
		if (this->game.timeClock % 120 == 0)
		{
			for (int i = 0; i < this->game.healthCount; i++)
			{
				this->game.health[i].randMove = rand() % (1 + i);
			}
			for (int j = 0; j < this->game.basicCount; j++)
			{
				this->game.basic[j].randMove = rand() % 8 + j;
			}
				
			
		}

}
void Menu::randomizeSpawns()
{
	for (int i = 0; i < this->game.basicCount; i++)
	{

		this->game.basic[i].respawnTimer = rand() % 300;
	}
	for (int j = 0; j < this->game.homingCount; j++)
	{

		this->game.homing[j].respawnTimer = rand() % 300;
	}
	for (int k = 0; k < this->game.healthCount; k++)
	{

		this->game.health[k].respawnTimer = rand() % 300;
	}
	for (int l = 0; l < this->game.homingCount; l++)
	{

		this->game.homing[l].lifeClock = rand() % 600;
	}
	

	
}

