#include "health.h"
void Health::initEnemy(int width, int height)
{
	this->setPosition(Vector2f(this->genSpawnX(width), this->genSpawnY(height)));

	//this->setPosition(200.f, 200.f);
	this->respawnTimer = rand() % 1200;
	this->setSize(Vector2f(playerYSize, playerXSize));
	this->setOrigin(Vector2f(this->getSize().x / 2, this->getSize().y / 2));
	this->setFillColor(Color(51, 51, 255, 255));
}
void Health::initTail()
{

	this->tail1.setSize(Vector2f(playerYSize * 1.7, playerXSize * 1.7));
	this->tail2.setSize(Vector2f(playerYSize * 1.4, playerXSize * 1.4));
	this->tail3.setSize(Vector2f(playerYSize * .8, playerXSize * .8));

	this->tail1.setOrigin(Vector2f((this->tail1.getSize().x / 2), (this->tail1.getSize().y / 2)));
	this->tail2.setOrigin(Vector2f((this->tail2.getSize().x / 2), (this->tail2.getSize().y / 2)));
	this->tail3.setOrigin(Vector2f((this->tail3.getSize().x / 2), (this->tail3.getSize().y / 2)));

	this->tail1.setFillColor(Color(0, 255, 0, 255));
	this->tail2.setFillColor(Color(0, 0, 255, 255));
	this->tail3.setFillColor(Color(0, 0, 255, 255));

	this->tail1.setPosition(this->getPosition());
	this->tail2.setPosition(this->getPosition());
	this->tail3.setPosition(this->getPosition());
}
void Health::movement(int width, int height, float dt, int framerate)
{


	if (abs(this->getPosition().x - Mouse::getPosition().x) < 200 && abs(this->getPosition().y - Mouse::getPosition().y) < 200)
	{
		if (this->getPosition().x > Mouse::getPosition().x)
		{
			this->move(Vector2f(this->speed * dt, 0));
		}
		if (this->getPosition().x < Mouse::getPosition().x)
		{
			this->move(Vector2f(-this->speed * dt, 0));
		}
		if (this->getPosition().y > Mouse::getPosition().y)
		{
			this->move(Vector2f(0, this->speed * dt));
		}
		if (this->getPosition().y < Mouse::getPosition().y)
		{
			this->move(Vector2f(0, -this->speed * dt));
		}
	}
	else
	{
		switch (this->randMove)
		{
		case 0:

			this->move(Vector2f(this->speed*dt, 0));
			break;
		case 1:
			this->move(Vector2f(-this->speed * dt, 0));
			break;
		case 2:
			this->move(Vector2f(0, this->speed * dt));
			break;
		case 3:
			this->move(Vector2f(0, -this->speed * dt));
			break;
		}
	}
	
	this->tail1.setPosition(this->getPosition());
	this->tail2.setPosition(this->getPosition());
	this->tail3.setPosition(this->getPosition());
	this->sprite.setPosition(this->getPosition());

	this->rotate((3*dt));
	this->tail1.rotate((5*dt));
	this->tail2.rotate((7*dt));
	this->tail3.rotate((9*dt));

	this->tail3.setFillColor(Color(0, 0, 255, (127 + (64 * sin((1.0 / (framerate / 4)) * ((float)this->timeClock))))));
	this->tail2.setFillColor(Color(0, 0, 255, (127 + (64 * sin((1.0 / (framerate / 6)) * ((float)this->timeClock))))));
	this->tail1.setFillColor(Color(0, 0, 255, (127 + (64 * sin((1.0 / (framerate / 8)) * ((float)this->timeClock))))));

	if (this->getPosition().x <= 0.f)
	{
		this->setPosition(0.f, this->getPosition().y);
		this->randMove = 0;
	}
	if (this->getPosition().x >= (float)width)
	{
		this->setPosition((float)width, this->getPosition().y);
		this->randMove = 1;
	}
	if (this->getPosition().y <= 0.f)
	{
		this->setPosition(this->getPosition().x, 0.f);
		this->randMove = 2;
	}
	if (this->getPosition().y >= (float)height)
	{
		this->setPosition(this->getPosition().x, (float)height);
		this->randMove = 3;
	}

	if (this->jitter == true)
	{
		switch (jitterCount % 2)
		{
		case 0:
			this->setPosition(this->getPosition().x + jitterSize, this->getPosition().y);
			this->jitterCount = this->jitterCount + 1;
			break;
		case 1:
			this->setPosition(this->getPosition().x - jitterSize, this->getPosition().y);
			this->jitterCount = this->jitterCount + 1;
			break;
		}

		if (this->jitterCount >= framerate)
		{
			this->jitterCount = 0;
			this->jitter = false;
		}
	}

}
void Health::checkDespawn(int width)
{
	if (this->lifeClock == 6000)
	{
		this->isDrawn = false;
		this->setPosition(Vector2f(this->genSpawnX(width), 0.f));
		this->respawnTimer = 300;

		this->lifeClock = 0;
	}
	else
	{
		this->lifeClock = this->lifeClock + 1;
	}
}
void Health::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);

	this->sprite.setScale(0.08, 0.08);
}
void Health::initTexture()
{
	this->texture.loadFromFile("Resources/Textures/heart.png");

}