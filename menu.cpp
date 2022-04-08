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
	this->game.initEnemies(this->window->getSize().x, this->window->getSize().y);


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

	this->Music.setFont(this->font);
	this->Music.setCharacterSize(48);
	this->Music.setFillColor(Color::White);
	this->Music.setString("Music");
	this->Music.setOrigin(this->Music.getGlobalBounds().width / 2, this->Music.getGlobalBounds().height / 2);
	this->Music.setPosition(Vector2f(this->window->getSize().x / 2.25, this->window->getSize().y / 2));

	this->SFX.setFont(this->font);
	this->SFX.setCharacterSize(48);
	this->SFX.setFillColor(Color::White);
	this->SFX.setString("SFX");
	this->SFX.setOrigin(this->SFX.getGlobalBounds().width / 2, this->SFX.getGlobalBounds().height / 2);
	this->SFX.setPosition(Vector2f(this->window->getSize().x / 2.25, this->window->getSize().y / 2.5));


	this->title.setFont(this->font);
	this->title.setCharacterSize(128);
	this->title.setFillColor(Color::White);
	this->title.setString("CUBIC DISPOSITION");
	this->title.setOrigin(this->title.getGlobalBounds().width / 2, this->title.getGlobalBounds().height / 2);
	this->title.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2)- (this->window->getSize().y / 4)));
	
	this->optionsText.setFont(this->font);
	this->optionsText.setCharacterSize(128);
	this->optionsText.setFillColor(Color::White);
	this->optionsText.setString("OPTIONS");
	this->optionsText.setOrigin(this->optionsText.getGlobalBounds().width / 2, this->optionsText.getGlobalBounds().height / 2);
	this->optionsText.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2) - (this->window->getSize().y / 4)));

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

	this->back.setFont(this->font);
	this->back.setCharacterSize(48);
	this->back.setFillColor(Color::White);
	this->back.setString("Back");
	this->back.setOrigin(this->back.getGlobalBounds().width / 2, this->back.getGlobalBounds().height / 2);
	this->back.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2) + 2 * (this->window->getSize().y / 10)));

	this->frCap.setFont(this->font);
	this->frCap.setCharacterSize(48);
	this->frCap.setFillColor(Color::White);
	this->frCap.setString("Framerate Cap");
	this->frCap.setOrigin(this->frCap.getGlobalBounds().width / 2, this->frCap.getGlobalBounds().height / 2);
	this->frCap.setPosition(Vector2f(this->window->getSize().x / 2.25, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));

	this->FPS60.setFont(this->font);
	this->FPS60.setCharacterSize(48);
	this->FPS60.setFillColor(Color::White);
	this->FPS60.setString("60");
	this->FPS60.setOrigin(this->FPS60.getGlobalBounds().width / 2, this->FPS60.getGlobalBounds().height / 2);
	this->FPS60.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));

	this->FPS30.setFont(this->font);
	this->FPS30.setCharacterSize(48);
	this->FPS30.setFillColor(Color::White);
	this->FPS30.setString("30");
	this->FPS30.setOrigin(this->FPS30.getGlobalBounds().width / 2, this->FPS30.getGlobalBounds().height / 2);
	this->FPS30.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));

	this->FPS144.setFont(this->font);
	this->FPS144.setCharacterSize(48);
	this->FPS144.setFillColor(Color::White);
	this->FPS144.setString("144");
	this->FPS144.setOrigin(this->FPS144.getGlobalBounds().width / 2, this->FPS144.getGlobalBounds().height / 2);
	this->FPS144.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));

	this->FPS240.setFont(this->font);
	this->FPS240.setCharacterSize(48);
	this->FPS240.setFillColor(Color::White);
	this->FPS240.setString("240");
	this->FPS240.setOrigin(this->FPS240.getGlobalBounds().width / 2, this->FPS240.getGlobalBounds().height / 2);
	this->FPS240.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));
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
		this->game.enemyUpdate(this->window->getSize().x, this->window->getSize().y, this->reg, this->framerate);
		this->game.shieldUpdate(this->reg, this->framerate);
		this->game.updateFlash(this->reg, this->framerate);
		this->game.updateTimeClock();
		this->game.scoreUpdate(this->reg, this->framerate);
		this->game.collision();
		this->game.bomb.updateBomb(this->reg, this->framerate);

		if (this->game.life <= 0)
		{
			cout << "You're trast bro u lose" << endl;
			this->resetGame();
			
		}
		
		this->updateText();
		break;

	case 2:
		this->pollEvents();
		this->updateText();
		this->updateMouseBox();
		break;
	}

}
void Menu::resetGame()
{
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
	this->game.frameClock = 0;
	this->game.timeClock = 0;
	this->game.updateText();
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
		//this->window->draw(this->mouseBox);
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
	case 2:
		this->window->clear();
		//this->window->draw(this->backButton);
		//this->window->draw(this->mouseBox);
		this->window->draw(this->optionsText);
		this->window->draw(this->Music);
		this->window->draw(this->musicBox);
		this->window->draw(this->SFX);
		this->window->draw(this->sfxBox);
		this->window->draw(this->frCap);
		
		if (this->visibleMenu == false)
		{
			if (this->framerate == 30)
			{
				this->window->draw(this->dropdown);
				this->window->draw(this->FPS30);
			}
			if (this->framerate == 60)
			{
				this->window->draw(this->dropdown);
				this->window->draw(this->FPS60);
			}
			if (this->framerate == 144)
			{
				this->window->draw(this->dropdown);
				this->window->draw(this->FPS144);
			}
			if (this->framerate == 240)
			{
				this->window->draw(this->dropdown);
				this->window->draw(this->FPS240);
			}
		}
		else
		{
			this->window->draw(this->dropdown30);
			this->window->draw(this->dropdown60);
			this->window->draw(this->dropdown144);
			this->window->draw(this->dropdown240);

			this->window->draw(this->FPS30);
			this->window->draw(this->FPS60);
			this->window->draw(this->FPS144);
			this->window->draw(this->FPS240);


		}
		this->window->draw(this->back);
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
					this->resetGame();
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
			break;
		case 2:
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

	this->backButton.setSize(Vector2f(this->back.getGlobalBounds().width * 1.5, this->back.getGlobalBounds().height * 1.5));
	this->backButton.setFillColor(Color(255, 0, 0, 32));
	this->backButton.setOrigin(this->backButton.getGlobalBounds().width / 2, this->backButton.getGlobalBounds().height / 2);
	this->backButton.setPosition(Vector2f(this->window->getSize().x / 2, (this->window->getSize().y / 2) + 2 * (this->window->getSize().y / 10)));

	this->dropdown60.setSize(Vector2f(this->FPS60.getGlobalBounds().width * 6, this->FPS60.getGlobalBounds().height*1.5));
	this->dropdown60.setFillColor(Color(0, 0, 0, 127));
	this->dropdown60.setOrigin(this->dropdown60.getGlobalBounds().width / 2, this->dropdown60.getGlobalBounds().height / 2);
	this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y+(this->FPS60.getGlobalBounds().height/6)));

	this->dropdown30.setSize(Vector2f(this->FPS60.getGlobalBounds().width * 6, this->FPS60.getGlobalBounds().height * 1.5));
	this->dropdown30.setFillColor(Color(0, 0, 0, 127));
	this->dropdown30.setOrigin(this->dropdown30.getGlobalBounds().width / 2, this->dropdown30.getGlobalBounds().height / 2);
	this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));

	this->dropdown144.setSize(Vector2f(this->FPS60.getGlobalBounds().width * 6, this->FPS60.getGlobalBounds().height * 1.5));
	this->dropdown144.setFillColor(Color(0, 0, 0, 127));
	this->dropdown144.setOrigin(this->dropdown144.getGlobalBounds().width / 2, this->dropdown144.getGlobalBounds().height / 2);
	this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));

	this->dropdown240.setSize(Vector2f(this->FPS60.getGlobalBounds().width * 6, this->FPS60.getGlobalBounds().height * 1.5));
	this->dropdown240.setFillColor(Color(0, 0, 0, 127));
	this->dropdown240.setOrigin(this->dropdown240.getGlobalBounds().width / 2, this->dropdown240.getGlobalBounds().height / 2);
	this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));

	this->dropdown.setSize(Vector2f(this->FPS60.getGlobalBounds().width * 6, this->FPS60.getGlobalBounds().height * 1.5));
	this->dropdown.setFillColor(Color(255, 255, 255, 127));
	this->dropdown.setOrigin(this->dropdown.getGlobalBounds().width / 2, this->dropdown.getGlobalBounds().height / 2);
	this->dropdown.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));

	this->sfxBox.setSize(Vector2f(this->SFX.getGlobalBounds().width * 1.5, this->SFX.getGlobalBounds().width * 1.5));
	this->sfxBox.setFillColor(Color(0, 255, 0, 127));
	this->sfxBox.setOrigin(this->sfxBox.getGlobalBounds().width / 2, this->sfxBox.getGlobalBounds().height / 2);
	this->sfxBox.setPosition(Vector2f(this->window->getSize().x / 1.75, this->SFX.getPosition().y + (this->SFX.getGlobalBounds().height / 6)));

	this->musicBox.setSize(Vector2f(this->SFX.getGlobalBounds().width * 1.5, this->SFX.getGlobalBounds().width * 1.5));
	this->musicBox.setFillColor(Color(0, 255, 0, 127));
	this->musicBox.setOrigin(this->musicBox.getGlobalBounds().width / 2, this->musicBox.getGlobalBounds().height / 2);
	this->musicBox.setPosition(Vector2f(this->window->getSize().x / 1.75, this->Music.getPosition().y + (this->Music.getGlobalBounds().height / 6)));

}
void Menu::checkClick()
{

	if (this->button.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 0)
	{
		this->game.scoreUpdate(this->reg, this->framerate);
		this->resetGame();
		this->game.Start.play();
		this->state = 1;
	}
	if (this->options.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 0)
	{
		this->state = 2;
	}
	if (this->exit.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 0)
	{
		this->window->close();
	}
	if (this->back.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		this->state = 0;
	}
	if (this->dropdown30.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->visibleMenu == true)
		{
			this->framerate = 30;
			this->window->setFramerateLimit(30);
			this->visibleMenu = false;
		}
	}
	if (this->dropdown60.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->visibleMenu == true)
		{
			this->framerate = 60;
			this->window->setFramerateLimit(60);
			this->visibleMenu = false;
		}
	}
	if (this->dropdown144.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->visibleMenu == true)
		{
			this->framerate = 144;
			this->window->setFramerateLimit(144);
			this->visibleMenu = false;
		}
	}
	if (this->dropdown240.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->visibleMenu == true)
		{
			this->framerate = 240;
			this->window->setFramerateLimit(240);
			this->visibleMenu = false;
		}
	}
	if (this->sfxBox.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->sfx == false)
		{
			this->sfx = true;
			this->game.sfxMulti = 1.0;
			this->game.updateAudio();
		}
		else if (this->sfx == true)
		{
			this->sfx = false;
			this->game.sfxMulti = 0.0;
			this->game.updateAudio();
		}
		
	}
	if (this->musicBox.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->music == false)
		{
			this->music = true;
			this->game.volumeMulti = 1.0f;
			this->game.updateAudio();
		}
		else if (this->music == true)
		{
			this->music = false;
			this->game.volumeMulti = 0.0f;
			this->game.updateAudio();
		}
	}
}
void Menu::initMouseBox()
{
	this->mouseBox.setPosition(Vector2f(Mouse::getPosition()));

	this->mouseBox.setSize(Vector2f(playerYSize * 1.4, playerXSize * 1.4));
	this->mouseBox.setOrigin(Vector2f(this->mouseBox.getSize().x / 2, this->mouseBox.getSize().y / 2));
	this->mouseBox.setFillColor(Color(255, 0, 255, 127));
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
	if (this->musicBox.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		if (this->music == true)
		{
			this->musicBox.setFillColor(Color(0, 255, 0, 200));
		}
		else
		{
			this->musicBox.setFillColor(Color(255, 0, 0, 200));
		}
	}
	else
	{
		if (this->music == true)
		{
			this->musicBox.setFillColor(Color(0, 255, 0, 127));
		}
		else
		{
			this->musicBox.setFillColor(Color(255, 0, 0, 127));
		}
	}
	if (this->sfxBox.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()))
	{
		if (this->sfx == true)
		{
			this->sfxBox.setFillColor(Color(0, 255, 0, 200));
		}
		else
		{
			this->sfxBox.setFillColor(Color(255, 0, 0, 200));
		}
	}
	else
	{
		if (this->sfx == true)
		{
			this->sfxBox.setFillColor(Color(0, 255, 0, 127));
		}
		else
		{
			this->sfxBox.setFillColor(Color(255, 0, 0, 127));
		}
	}
	if (this->visibleMenu == false)
	{
		this->FPS30.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));
		this->FPS60.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));
		this->FPS144.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));
		this->FPS240.setPosition(Vector2f(this->window->getSize().x / 1.75, (this->window->getSize().y / 2) + (this->window->getSize().y / 10)));

		this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
		this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
		this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
		this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));


	}
	if (this->button.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 0)
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


	if (this->optionsButton.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 0)
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

	if (this->exitButton.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds())&&this->state == 0)
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

	if (this->backButton.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds())&& this->state == 2)
	{
		if (this->mouseCollideB == false)
		{


			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();

				this->mouseCollideB = true;
			}
			this->back.setScale(1.2, 1.2);

		}
	}
	else
	{
		this->mouseCollideB = false;
		
		this->back.setScale(1, 1);
		
	}

	if (this->dropdown.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{


			if (this->framerate == 60)
			{
				this->FPS30.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS144.getGlobalBounds().height*1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height*1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 30)
			{
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 144)
			{
				this->FPS30.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 240)
			{
				this->FPS30.setPosition(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
		
		//this->exit.setScale(1.2, 1.2);

	}

	if (this->sfxBox.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->mouseCollideS == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollideS = true;
			}

		}

	}
	else
	{
		this->mouseCollideS = false;
	}
	if (this->musicBox.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->mouseCollideM == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollideM = true;
			}

		}

	}
	else
	{
		this->mouseCollideM = false;
	}
	if (this->dropdown30.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->mouseCollide2 == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollide2 = true;
			}

		}

	}
	else
	{
		this->mouseCollide2 = false;
	}
	if (this->dropdown60.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->mouseCollide3 == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollide3 = true;
			}

		}

	}
	else
	{
		this->mouseCollide3 = false;
	}
	if (this->dropdown144.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->mouseCollide4 == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollide4 = true;
			}

		}

	}
	else
	{
		this->mouseCollide4 = false;
	}
	if (this->dropdown240.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && this->state == 2)
	{
		if (this->mouseCollide5 == false)
		{
			if (this->game.Rollover.getStatus() != Sound::Playing)
			{
				this->game.Rollover.play();
				this->mouseCollide5 = true;
			}

		}

	}
	else
	{
		this->mouseCollide5 = false;
	}
	if (this->dropdown30.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && visibleMenu == true)
	{

		this->dropdown240.setFillColor(Color(255, 255, 255, 127));
		this->dropdown60.setFillColor(Color(255, 255, 255, 127));
		this->dropdown144.setFillColor(Color(255, 255, 255, 127));
		this->dropdown30.setFillColor(Color(255, 255, 255, 200));
		
		

			if (this->framerate == 60)
			{
				this->FPS30.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 30)
			{
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 144)
			{
				this->FPS30.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 240)
			{
				this->FPS30.setPosition(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}

	}
	if (this->dropdown60.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && visibleMenu == true)
	{
		this->dropdown30.setFillColor(Color(255, 255, 255, 127));
		this->dropdown240.setFillColor(Color(255, 255, 255, 127));
		this->dropdown144.setFillColor(Color(255, 255, 255, 127));
		this->dropdown60.setFillColor(Color(255, 255, 255, 200));
			if (this->framerate == 60)
			{
				this->FPS30.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 30)
			{
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 144)
			{
				this->FPS30.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 240)
			{
				this->FPS30.setPosition(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}

	}
	if (this->dropdown144.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && visibleMenu == true)
	{
		this->dropdown30.setFillColor(Color(255, 255, 255, 127));
		this->dropdown60.setFillColor(Color(255, 255, 255, 127));
		this->dropdown240.setFillColor(Color(255, 255, 255, 127));
		this->dropdown144.setFillColor(Color(255, 255, 255, 200));
			if (this->framerate == 60)
			{
				this->FPS30.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 30)
			{
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 144)
			{
				this->FPS30.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 240)
			{
				this->FPS30.setPosition(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
	}
	if (this->dropdown240.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) && visibleMenu == true)
	{
		this->dropdown30.setFillColor(Color(255, 255, 255, 127));
		this->dropdown60.setFillColor(Color(255, 255, 255, 127));
		this->dropdown144.setFillColor(Color(255, 255, 255, 127));
		this->dropdown240.setFillColor(Color(255, 255, 255, 200));

			if (this->framerate == 60)
			{
				this->FPS30.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 30)
			{
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 144)
			{
				this->FPS30.setPosition(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS240.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS240.getGlobalBounds().height * 1.5));
				this->dropdown240.setPosition(Vector2f(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS240.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
			if (this->framerate == 240)
			{
				this->FPS30.setPosition(this->FPS240.getPosition().x, this->FPS240.getPosition().y + (this->FPS30.getGlobalBounds().height * 1.5));
				this->dropdown30.setPosition(Vector2f(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS30.getGlobalBounds().height / 6)));
				this->FPS60.setPosition(this->FPS30.getPosition().x, this->FPS30.getPosition().y + (this->FPS60.getGlobalBounds().height * 1.5));
				this->dropdown60.setPosition(Vector2f(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS60.getGlobalBounds().height / 6)));
				this->FPS144.setPosition(this->FPS60.getPosition().x, this->FPS60.getPosition().y + (this->FPS144.getGlobalBounds().height * 1.5));
				this->dropdown144.setPosition(Vector2f(this->FPS144.getPosition().x, this->FPS144.getPosition().y + (this->FPS144.getGlobalBounds().height / 6)));
				this->visibleMenu = true;
			}
	}
	if (this->dropdown240.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) == false)
	{
		if (this->dropdown144.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) == false)
		{
			if (this->dropdown60.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) == false)
			{
				if (this->dropdown30.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) == false)
				{
					if (this->dropdown.getGlobalBounds().intersects(this->mouseBox.getGlobalBounds()) == false)
					{
						visibleMenu = false;
					}
				}
			}
		}
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

