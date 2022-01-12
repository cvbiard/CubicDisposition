#include "Area.h"
void Area::initTail()
{

	this->tail1.setSize(Vector2f(playerYSize / 1.5, playerXSize / 1.5));
	this->tail2.setSize(Vector2f(playerYSize / 1.75, playerXSize / 1.75));
	this->tail3.setSize(Vector2f(playerYSize / 2, playerXSize / 2));

	this->tail1.setOrigin(Vector2f((this->tail1.getSize().x / 2), (this->tail1.getSize().y / 2)));
	this->tail2.setOrigin(Vector2f((this->tail2.getSize().x / 2), (this->tail2.getSize().y / 2)));
	this->tail3.setOrigin(Vector2f((this->tail3.getSize().x / 2), (this->tail3.getSize().y / 2)));

	this->tail1.setFillColor(Color(204, 204, 0, 255));
	this->tail2.setFillColor(Color(153, 153, 0, 255));
	this->tail3.setFillColor(Color(102, 102, 0, 255));

	this->tail1.setPosition(this->getPosition());
	this->tail2.setPosition(this->getPosition());
	this->tail3.setPosition(this->getPosition());
}
void Area::initEnemy(int width, int height)
{
	this->setPosition(Vector2f(this->genSpawnX(width), this->genSpawnY(height)));
	//this->setPosition(200.f, 200.f);
	this->respawnTimer = rand() % 200;

	this->setSize(Vector2f(playerYSize, playerXSize));
	this->setOrigin(Vector2f(this->getSize().x / 2, this->getSize().y / 2));
	this->setFillColor(Color(255, 255, 0, 255));
}
void Area::movement(Area area[5], float dt, int framerate)
{
	this->rotate(3*dt);
	this->tail1.rotate(5*dt);
	this->tail2.rotate(7*dt);
	this->tail3.rotate(9*dt);


	
		//Tail 3
		if (this->tail3.getPosition().x > this->tail2.getPosition().x)
		{
			//this->tail3.setPosition(this->tail3.getPosition().x - this->speed * .7, this->tail3.getPosition().y);
			this->tail3.move(-(this->speed * .7) * dt, 0.f);
		}
		if (this->tail3.getPosition().x < this->tail2.getPosition().x)
		{
			//this->tail3.setPosition(this->tail3.getPosition().x + this->speed * .7, this->tail3.getPosition().y);
			this->tail3.move((this->speed * .7) * dt, 0.f);
		}
		if (this->tail3.getPosition().y > this->tail2.getPosition().y)
		{
			//this->tail3.setPosition(this->tail3.getPosition().x, this->tail3.getPosition().y - this->speed * .7);
			this->tail3.move(0.f, -(this->speed * .7) * dt);
		}
		if (this->tail3.getPosition().y < this->tail2.getPosition().y)
		{
			//this->tail3.setPosition(this->tail3.getPosition().x, this->tail3.getPosition().y + this->speed * .7);
			this->tail3.move(0.f, (this->speed * .7) * dt);
		}

		//Tail 2
		if (this->tail2.getPosition().x > this->tail1.getPosition().x)
		{
			//this->tail2.setPosition(this->tail2.getPosition().x - this->speed * 0.8, this->tail2.getPosition().y);
			this->tail2.move(-(this->speed * .8) * dt, 0.f);
		}
		if (this->tail2.getPosition().x < this->tail1.getPosition().x)
		{
			//this->tail2.setPosition(this->tail2.getPosition().x + this->speed * 0.8, this->tail2.getPosition().y);
			this->tail2.move((this->speed * .8) * dt, 0.f);
		}
		if (this->tail2.getPosition().y > this->tail1.getPosition().y)
		{
			//this->tail2.setPosition(this->tail2.getPosition().x, this->tail2.getPosition().y - this->speed * 0.8);
			this->tail2.move(0.f, -(this->speed * .8) * dt);
		}
		if (this->tail2.getPosition().y < this->tail1.getPosition().y)
		{
			//this->tail2.setPosition(this->tail2.getPosition().x, this->tail2.getPosition().y + this->speed * 0.8);
			this->tail2.move(0.f, (this->speed * .8) * dt);
		}

		//Tail 1
		if (this->tail1.getPosition().x > this->getPosition().x)
		{
			//this->tail1.setPosition(this->tail1.getPosition().x - this->speed * .9, this->tail1.getPosition().y);
			this->tail1.move(-(this->speed * .9) * dt, 0.f);
		}
		if (this->tail1.getPosition().x < this->getPosition().x)
		{
			//this->tail1.setPosition(this->tail1.getPosition().x + this->speed * 0.9, this->tail1.getPosition().y);
			this->tail1.move((this->speed * .9) * dt, 0.f);
		}
		if (this->tail1.getPosition().y > this->getPosition().y)
		{
			//this->tail1.setPosition(this->tail1.getPosition().x, this->tail1.getPosition().y - this->speed * 0.9);
			this->tail1.move(0.f, -(this->speed * .9) * dt);
		}
		if (this->tail1.getPosition().y < this->getPosition().y)
		{
			//this->tail1.setPosition(this->tail1.getPosition().x, this->tail1.getPosition().y + this->speed * 0.9);
			this->tail1.move(0.f, (this->speed * .9) * dt);
		}

	if (abs(this->getPosition().x - Mouse::getPosition().x) < 200 && abs(this->getPosition().y - Mouse::getPosition().y) < 200)
	{
		//Base square
		if (this->getPosition().x > Mouse::getPosition().x)
		{
			//this->setPosition(this->getPosition().x - this->speed, this->getPosition().y);
			this->move(-this->speed * dt, 0.f);
		}
		if (this->getPosition().x < Mouse::getPosition().x)
		{
			//this->setPosition(this->getPosition().x + this->speed, this->getPosition().y);
			this->move(this->speed * dt, 0.f);
		}
		if (this->getPosition().y > Mouse::getPosition().y)
		{
			//this->setPosition(this->getPosition().x, this->getPosition().y - this->speed);
			this->move(0.f, -this->speed * dt);
		}
		if (this->getPosition().y < Mouse::getPosition().y)
		{
			//this->setPosition(this->getPosition().x, this->getPosition().y + this->speed);
			this->move(0.f, this->speed * dt);
		}
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

	FloatRect current = this->getGlobalBounds();

	for (int i = 0; i < 5; i++)
	{
		FloatRect other = area[i].getGlobalBounds();

		if (this->getPosition() != area[i].getPosition() && current.intersects(other))
		{
			if (this->getPosition().x > area[i].getPosition().x)
			{
				//this->setPosition(Vector2f(this->getPosition().x + 3, this->getPosition().y));
				this->move(3.f, 0.f);
			}
			if (this->getPosition().x < area[i].getPosition().x)
			{
				//this->setPosition(Vector2f(this->getPosition().x - 3, this->getPosition().y));
				this->move(-3.f, 0.f);
			}
			if (this->getPosition().y > area[i].getPosition().y)
			{
				//this->setPosition(Vector2f(this->getPosition().x, this->getPosition().y + 3));
				this->move(0.f, 3.f);
			}
			if (this->getPosition().y < area[i].getPosition().y)
			{
				//this->setPosition(Vector2f(this->getPosition().x, this->getPosition().y - 3));
				this->move(0.f, -3.f);
			}
		}
	}
}
void Area::checkDespawn(int width)
{
	if (this->lifeClock == 600)
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