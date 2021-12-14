#include "game.h"


Game::Game()
{
	this->initVariables();
	this->initCharacter();
	this->initFont();
	this->initAudio();
	this->initFlash();
	for (int i = 0; i < this->basicCount; i++)
	{
		this->basic[i].initEnemy();
		this->basic[i].initTail();
	}
	for (int i = 0; i < this->homingCount; i++)
	{
		this->homing[i].initEnemy();
		this->homing[i].initTail();
	}
	for (int i = 0; i < this->healthCount; i++)
	{
		this->health[i].initEnemy();
		this->health[i].initTail();
		this->health[i].initTexture();
		this->health[i].initSprite();
	}
	for (int i = 0; i < this->areaCount; i++)
	{
		this->area[i].initEnemy();
		this->area[i].initTail();
	}
	for (int i = 0; i < this->shooterCount; i++)
	{
		this->shooter[i].initEnemy();
		this->shooter[i].initTail();
	}

	this->initTail();
}
void Game::initFlash()
{
	this->flash.setSize(Vector2f(1920, 1080));
	this->flash.setPosition(0, 0);
	this->flash.setFillColor(Color(255, 0, 0, 0));
}
void Game::updateFlash()
{
	float t = this->timeClock;

	if (this->Hurt.getStatus() == Sound::Playing)
	{
		this->flash.setFillColor(Color(255, abs(255 * sin(this->flashCount *.05)), abs(255 * sin(this->flashCount *.05)), abs(255 * sin(this->flashCount *.05))));
		this->flashCount = this->flashCount + 1;
	}
	else
	{
		if (this->life == 3)
		{
			this->flash.setFillColor(Color(102, 255, 102, 16 + ((16 * sin((float)((float)(this->timeClock / (float)(2.35 * 10))))))));
			this->flashCount = 0;
		}
		if (this->life == 2)
		{
			this->flash.setFillColor(Color(255, 255, 102, 16 + ((16 * sin((float)((float)(this->timeClock / (float)(2.35 * 10))))))));
			this->flashCount = 0;
		}
		if (this->life == 1)
		{
			this->flash.setFillColor(Color(255, 102, 102, 16 + ((16 * sin((float)((float)(this->timeClock / (float)(2.35 * 10))))))));
			this->flashCount = 0;
		}
		
	}
}
void Game::updateBeatClock()
{
	this->beatClock = 255 + (255 * sin(((140 / 60) * this->frameClock)));
}
Game::~Game()
{

}
void Game::shieldUpdate()
{
	this->takeHit();
	this->character.rotate(3);
	this->tail1.rotate(5);
	this->tail2.rotate(7);
	this->tail3.rotate(9);

	//this->character.setFillColor(Color(0, 255, 0, abs(255 * sin(this->timeClock * .05 + 1))));
	this->tail3.setFillColor(Color(255, 255, 0, abs(255 * sin(this->timeClock * .05 +1))));
	this->tail2.setFillColor(Color(0, 255, 0, abs(255 * sin(this->timeClock * .05+1.5))));
	this->tail1.setFillColor(Color(0, 0, 255, abs(255 * sin(this->timeClock * .05+2))));
	
}
void Game::updateTimeClock()
{
	this->timeClock = this->timeClock + 1;
	for (int i = 0; i < this->healthCount; i++)
	{
		this->health[i].timeClock = this->timeClock;
	}
}
void Game::playTrack()
{
	
	if (this->timeClock > 500 && this->timeClock < 550)
	{
		this->KickTail.setVolume(75.f);
		this->Lead1Tail.setVolume(75.f);
		this->Lead2Tail.setVolume(75.f);
		this->Lead3Tail.setVolume(75.f);
	}
	if (this->Kick.getStatus() != Music::Playing)
	{
		
		this->KickTail.play();
		this->Lead1Tail.play();
		this->Lead2Tail.play();
		this->Lead3Tail.play();
		
		this->BassSynth.play();
		this->Lead1.play();
		this->Lead2.play();
		this->Lead3.play();
		this->Pad.play();
	
		this->firstPlay = false;

		this->Kick.play();
	}


}
void Game::enemyUpdate()
{

	if (this->score > 10)
	{
		for (int i = 0; i < this->basicCount; i++)
		{
			if (this->basic[i].isDrawn == true)
			{
				this->basic[i].movement();
				this->basic[i].checkDespawn();
			}
			if (this->basic[i].isDrawn == false)
			{
				this->basic[i].checkSpawn();
			}
		}
	}
	if (this->score > 200)
	{
		for (int i = 0; i < this->homingCount; i++)
		{
			if (this->homing[i].isDrawn == true)
			{
				this->homing[i].movement(this->homing);
				//this->homing[i].checkDespawn();
			}
			if (this->homing[i].isDrawn == false)
			{
				this->homing[i].checkSpawn();
			}
		}
	}
	if (this->score > 10)
	{
		for (int i = 0; i < this->healthCount; i++)
		{
			if (this->health[i].isDrawn == true)
			{
				this->health[i].movement();
				this->health[i].checkDespawn();
			}
			if (this->health[i].isDrawn == false)
			{
				this->health[i].checkSpawn();
			}
		}
	}
	if (this->score > 300)
	{
		for (int i = 0; i < this->areaCount; i++)
		{
			if (this->area[i].isDrawn == true)
			{
				this->area[i].movement(this->area);
				//this->area[i].checkDespawn();
			}
			if (this->area[i].isDrawn == false)
			{
				this->area[i].checkSpawn();
			}
		}
	}
	if (this->score > 500)
	{
		for (int i = 0; i < this->shooterCount; i++)
		{
			if (this->shooter[i].isDrawn == true)
			{
				this->shooter[i].movement(this->shooter);
				//this->area[i].checkDespawn();
			}
			if (this->shooter[i].isDrawn == false)
			{
				this->shooter[i].checkSpawn();
			}
		}
	}
}
void Game::scoreUpdate()
{
	if (this->frameClock == 0 || this->frameClock == 29)
	{
		string label = "Score: ";
		this->score = this->score + 1;

		string intStr = "score number";

		stringstream ss;
		ss << this->score;
		ss >> intStr;

		label += intStr;

		this->uiText.setString(label);
	}
	
}
void Game::updateFrameClock()
{
	this->frameClock = this->frameClock + 1;

	if (this->frameClock == 60)
	{
		this->frameClock = 0;
	}
}
void Game::initAudio()
{
	//this->track.openFromFile("141.wav");
	this->Kick.openFromFile("Resources/Audio/Music/Kick.wav");
	this->KickTail.openFromFile("Resources/Audio/Music/Kick.wav");
	this->BassSynth.openFromFile("Resources/Audio/Music/BassSynth.wav");
	this->Lead1.openFromFile("Resources/Audio/Music/Lead1.wav");
	this->Lead2.openFromFile("Resources/Audio/Music/Lead2.wav");
	this->Lead3.openFromFile("Resources/Audio/Music/Lead3.wav");
	this->Lead1Tail.openFromFile("Resources/Audio/Music/Lead1Tail.wav");
	this->Lead2Tail.openFromFile("Resources/Audio/Music/Lead2Tail.wav");
	this->Lead3Tail.openFromFile("Resources/Audio/Music/Lead3Tail.wav");
	this->Pad.openFromFile("Resources/Audio/Music/Pad.wav");

	this->bomb.BombSoundBuff.loadFromFile("Resources/Audio/SFX/Bomb.wav");
	this->DropBombBuff.loadFromFile("Resources/Audio/SFX/DropBomb.wav");
	this->HealBuff.loadFromFile("Resources/Audio/SFX/Heal.wav");
	this->HurtBuff.loadFromFile("Resources/Audio/SFX/Hurt.wav");
	this->EnemyDieBuff.loadFromFile("Resources/Audio/SFX/EnemyDie.wav");
	this->StartBuff.loadFromFile("Resources/Audio/SFX/Start.wav");
	this->RolloverBuff.loadFromFile("Resources/Audio/SFX/Rollover.wav");

	this->bomb.BombSound.setBuffer(this->bomb.BombSoundBuff);
	this->DropBomb.setBuffer(this->DropBombBuff);
	this->Heal.setBuffer(this->HealBuff);
	this->Hurt.setBuffer(this->HurtBuff);
	this->EnemyDie.setBuffer(this->EnemyDieBuff);
	this->EnemyDie.setVolume(25.f);
	//this->Hurt.setVolume(75.f);

	this->Start.setBuffer(this->StartBuff);
	this->Rollover.setBuffer(this->RolloverBuff);
	this->Rollover.setVolume(50.f);

	this->Kick.setVolume(75.f);
	this->BassSynth.setVolume(75.f);
	this->Lead1.setVolume(75.f);
	this->Lead2.setVolume(75.f);
	this->Lead3.setVolume(75.f);
	this->Pad.setVolume(75.f);

	this->Kick.setLoop(true);
	this->BassSynth.setLoop(true);
	this->Lead1.setLoop(true);
	this->Lead2.setLoop(true);
	this->Lead3.setLoop(true);
	this->Pad.setLoop(true);

	this->KickTail.setLoop(true);
	this->Lead1Tail.setLoop(true);
	this->Lead2Tail.setLoop(true);
	this->Lead3Tail.setLoop(true);

	this->KickTail.setVolume(0);
	this->Lead1Tail.setVolume(0);
	this->Lead2Tail.setVolume(0);
	this->Lead3Tail.setVolume(0);
}
void Game::initFont()
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
void Game::takeHit()
{
	
}
void Game::jitterStart()
{
	this->Hurt.play();
	this->jitter = true;
	for (int i = 0; i < this->basicCount; i++)
	{
		this->basic[i].jitter = true;
	}
	for (int i = 0; i < this->homingCount; i++)
	{
		this->homing[i].jitter = true;
	}
	for (int i = 0; i < this->healthCount; i++)
	{
		this->health[i].jitter = true;
	}
	for (int i = 0; i < this->areaCount; i++)
	{
		this->area[i].jitter = true;
	}
	for (int i = 0; i < this->shooterCount; i++)
	{
		this->shooter[i].jitter = true;
	}
}
void Game::initText(RenderWindow* window)
{
	this->uiText.setOrigin(this->uiText.getGlobalBounds().width / 2, this->uiText.getGlobalBounds().height / 2);
	///this->uiText.setPosition(Vector2f(window->getSize().x / 2, window->getSize().y / 2));
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(48);
	this->uiText.setFillColor(Color::White);
	this->uiText.setString("1");


}
void Game::initVariables()
{


}
void Game::initCharacter()
{
	this->character.setPosition(Vector2f(Mouse::getPosition()));

	this->character.setSize(Vector2f(playerYSize*1.4, playerXSize*1.4));
	this->character.setOrigin(Vector2f(this->character.getSize().x / 2, this->character.getSize().y / 2));
	this->character.setFillColor(Color(0, 255, 0, 0));
	//this->character.setOutlineColor(Color::Green);
	//this->character.setOutlineThickness(1.f);
	
	
}
void Game::initTail()
{
	this->tail3.setPosition(Vector2f((Mouse::getPosition())) - Vector2f(playerXSize / 128, (playerYSize / 128)+ (playerYSize * 1.1)/2));
	this->tail2.setPosition(Vector2f(Vector2f((Mouse::getPosition())) - Vector2f(playerXSize / 128, playerYSize / 128)));
	this->tail1.setPosition(Vector2f(Vector2f((Mouse::getPosition())) - Vector2f(playerXSize / 128, playerYSize / 128)));
	
	this->tail1.setSize(Vector2f(playerYSize * 2.1, playerXSize * 2.1));
	this->tail2.setSize(Vector2f(playerYSize * 1.9, playerXSize * 1.9));
	this->tail3.setSize(Vector2f(playerYSize * 1.6, playerXSize * 1.6));
	
	
	this->tail1.setOrigin(Vector2f(this->tail1.getSize().x / 2, this->tail1.getSize().y / 2));
	this->tail2.setOrigin(Vector2f(this->tail2.getSize().x / 2, this->tail2.getSize().y / 2));
	this->tail3.setOrigin(Vector2f(this->tail3.getSize().x / 2, this->tail3.getSize().y / 2));
	
	
	
	
	this->tail3.setFillColor(Color(255, 255, 0, 127));
	this->tail2.setFillColor(Color(0, 255, 0, 127));
	this->tail1.setFillColor(Color(0, 0, 255, 127));

	
}
void Game::collision()
{
	FloatRect playerBounds = this->character.getGlobalBounds();
	FloatRect bombBounds = this->bomb.visual.getGlobalBounds();

	if (playerBounds.intersects(bombBounds) && this->bomb.damage == true)
	{
		if (this->bomb.dealt == false)
		{
			this->life = this->life - 1;
			this->jitterStart();
			this->bomb.dealt = true;
		}
	}

	for (int i = 0; i < this->basicCount; i++)
	{
		FloatRect enemyBounds = this->basic[i].getGlobalBounds();
		if (enemyBounds.intersects(playerBounds) && this->basic[i].isDrawn == true)
		{
			if (this->jitter == false)
			{
				cout << "You hit a basic enemy " << "Draw status: " << this->basic[i].isDrawn << endl;
				this->basic[i].isDrawn = false;
				this->basic[i].setPosition(Vector2f(this->basic[i].genSpawnX(), 0.f));
				this->basic[i].respawnTimer = this->randomRespawn() % 300;
				cout << "Basic timer: " << this->homing[i].respawnTimer <<endl;
				this->life = this->life - 1;
				cout << "LIFE: " << this->life << endl;
				this->jitterStart();
			}
			
		}
		if (enemyBounds.intersects(bombBounds) && this->bomb.damage == true)
		{
			this->basic[i].isDrawn = false;
			this->basic[i].setPosition(Vector2f(this->basic[i].genSpawnX(), 0.f));
			this->basic[i].respawnTimer = this->randomRespawn() % 300;
			this->score = this->score + 50;
			this->EnemyDie.play();
		}
	}
	for (int i = 0; i < this->homingCount; i++)
	{
		FloatRect homingBounds = this->homing[i].getGlobalBounds();
		if (homingBounds.intersects(playerBounds) && this->homing[i].isDrawn == true)
		{
			if (this->jitter == false)
			{
				cout << "You hit a homing enemy" << endl;
				this->homing[i].isDrawn = false;
				this->homing[i].setPosition(Vector2f(this->homing[i].genSpawnX(), this->homing[i].genSpawnY()));
				this->homing[i].respawnTimer = this->randomRespawn() % 200;
				this->life = this->life - 1;
				cout << "LIFE: " << this->life << endl;
				this->jitterStart();
			}
			
		}
		if (homingBounds.intersects(bombBounds) && this->bomb.damage == true)
		{
			this->homing[i].isDrawn = false; 
			this->homing[i].setPosition(Vector2f(this->homing[i].genSpawnX(), this->homing[i].genSpawnY()));
			this->homing[i].respawnTimer = this->randomRespawn() %  200;
			cout << "Homing timer: " << this->homing[i].respawnTimer << endl;
			this->score = this->score + 50;
			this->EnemyDie.play();
		}
	}
	for (int i = 0; i < this->healthCount; i++)
	{
		FloatRect healthBounds = this->health[i].getGlobalBounds();
		if (healthBounds.intersects(playerBounds) && this->health[i].isDrawn == true)
		{
			cout << "You hit a health dude" << endl;
			this->health[i].isDrawn = false;
			this->health[i].setPosition(Vector2f(this->health[i].genSpawnX(), this->health[i].genSpawnY()));
			this->health[i].respawnTimer = this->randomRespawn()%1200;
			cout << "Health timer: " << this->homing[i].respawnTimer << endl;

			if (this->life < 3)
			{
				this->Heal.play();
				this->life = this->life + 1;
				//cout << "LIFE: " << this->life << endl;
			}
			else
			{
				this->EnemyDie.play();
			}

		}
		if (healthBounds.intersects(bombBounds) && this->bomb.damage == true)
		{
			this->health[i].isDrawn = false;
			this->health[i].setPosition(Vector2f(this->health[i].genSpawnX(), this->health[i].genSpawnY()));
			this->health[i].respawnTimer = this->randomRespawn() % 1200;
			this->EnemyDie.play();
		}
	}
	for (int i = 0; i < this->areaCount; i++)
	{
		FloatRect areaBounds = this->area[i].getGlobalBounds();
		if (areaBounds.intersects(playerBounds) && this->area[i].isDrawn == true)
		{
			cout << "You hit a area dude" << endl;
			this->area[i].isDrawn = false;
			this->area[i].setPosition(Vector2f(this->area[i].genSpawnX(), this->area[i].genSpawnY()));
			this->area[i].respawnTimer = this->randomRespawn() % 1200;
			cout << "Health timer: " << this->area[i].respawnTimer << endl;
			this->life = this->life - 1;
			cout << "LIFE: " << this->life << endl;
			this->jitterStart();
	

		}
		if (areaBounds.intersects(bombBounds) && this->bomb.damage == true)
		{
			this->area[i].isDrawn = false;
			this->area[i].setPosition(Vector2f(this->area[i].genSpawnX(), this->area[i].genSpawnY()));
			this->area[i].respawnTimer = this->randomRespawn() % 1200;
			this->score = this->score + 50;
			this->EnemyDie.play();
		}
	}
	for (int i = 0; i < this->shooterCount; i++)
	{
		FloatRect shooterBounds = this->shooter[i].getGlobalBounds();
		FloatRect shooterTailBounds = this->shooter[i].tail1.getGlobalBounds();
		if (shooterBounds.intersects(playerBounds) && this->shooter[i].isDrawn == true)
		{
			cout << "You hit a shooter dude" << endl;
			this->shooter[i].isDrawn = false;
			this->shooter[i].setPosition(Vector2f(this->shooter[i].genSpawnX(), this->shooter[i].genSpawnY()));
			this->shooter[i].respawnTimer = this->randomRespawn() % 1200;
			cout << "Health timer: " << this->shooter[i].respawnTimer << endl;
			this->life = this->life - 1;
			cout << "LIFE: " << this->life << endl;
			this->jitterStart();


		}
		if (shooterTailBounds.intersects(playerBounds) && this->shooter[i].isDrawn == true)
		{
			cout << "You hit a shooter dude" << endl;
			this->shooter[i].tail1.setPosition(this->shooter[i].getPosition());
			cout << "Health timer: " << this->shooter[i].respawnTimer << endl;
			this->life = this->life - 1;
			cout << "LIFE: " << this->life << endl;
			this->jitterStart();


		}
		if (shooterBounds.intersects(bombBounds) && this->bomb.damage == true)
		{
			this->shooter[i].isDrawn = false;
			this->shooter[i].setPosition(Vector2f(this->shooter[i].genSpawnX(), this->shooter[i].genSpawnY()));
			this->shooter[i].respawnTimer = this->randomRespawn() % 1200;
			this->score = this->score + 50;
			this->EnemyDie.play();
		}
	}

}
int Game::randomRespawn()
{
	return rand();
}
void Game::renderText()
{
}
void Game::updateText()
{

}
//Test functions
void Game::testRange()
{
	for (int i = 0; i < this->basicCount; i++)
	{
		if (abs(this->character.getPosition().x - this->basic[i].getPosition().x) < 200 && abs(this->character.getPosition().y - this->basic[i].getPosition().y) < 200)
		{
			if (this->basic[i].isDrawn == true)
			{
				cout << "You are within 200 pixels of basic enemy " << i << endl;
			}
			
		}
	}
	for (int i = 0; i < this->homingCount; i++)
	{
		if (abs(this->character.getPosition().x - this->homing[i].getPosition().x) < 200 && abs(this->character.getPosition().y - this->homing[i].getPosition().y) < 200)
		{
			if (this->homing[i].isDrawn == true)
			{
				cout << "You are within 200 pixels of homing enemy " << i << endl;
			}
		}
	}
	for (int i = 0; i < this->healthCount; i++)
	{
		if (abs(this->character.getPosition().x - this->health[i].getPosition().x) < 200 && abs(this->character.getPosition().y - this->health[i].getPosition().y) < 200)
		{
			if (this->health[i].isDrawn == true)
			{
				cout << "You are within 200 pixels of health enemy " << i << endl;
			}
		}
	}
	for (int i = 0; i < this->areaCount; i++)
	{
		if (abs(this->character.getPosition().x - this->area[i].getPosition().x) < 200 && abs(this->character.getPosition().y - this->area[i].getPosition().y) < 200)
		{
			if (this->area[i].isDrawn == true)
			{
				cout << "You are within 200 pixels of area enemy " << i << endl;
			}
		}
	}
	for (int i = 0; i < this->shooterCount; i++)
	{
		if (abs(this->character.getPosition().x - this->shooter[i].getPosition().x) < 200 && abs(this->character.getPosition().y - this->shooter[i].getPosition().y) < 200)
		{
			if (this->shooter[i].isDrawn == true)
			{
				cout << "You are within 200 pixels of shooter enemy " << i << endl;
			}
		}
	}
}
void Game::testLife()
{
	bool alive = true;

	
		if (this->life <= 0)
		{
			alive = false;
		}

		cout << "Currently alive? " << alive << endl;
	
	
}
void Game::testCollision()
{
	FloatRect playerBounds = this->character.getGlobalBounds();

	for (int i = 0; i < this->basicCount; i++)
	{
		FloatRect enemyBounds = this->basic[i].getGlobalBounds();
		if (enemyBounds.intersects(playerBounds))
		{
			cout << "Collided with basic enemy " << i << endl;

		}
	}
	
}
void Game::testShield()
{
	
		if (life == 3)
		{
			cout << "Shield currently blue" << endl;
		}
		else if (life == 2)
		{
			cout << "Shield currently green" << endl;
		}
		else if (life == 1)
		{
			cout << "Shield currently yellow" << endl;
		}
		else
		{
			cout << "Shield currently none" << endl;
		}
	

}
void Game::testBomb()
{
	bool bombDropped = false;

	
		if (this->bomb.dropped == true)
		{
			bombDropped = true;
		}

		cout << "Is bomb currently dropped? " << bombDropped << endl;
	

	
}