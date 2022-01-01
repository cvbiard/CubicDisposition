#include "Shooter.h"
void Shooter::initEnemy(int width, int height)
{
	this->setPosition(Vector2f(this->genSpawnX(width), this->genSpawnY(height)));
	//this->setPosition(200.f, 200.f);
	this->respawnTimer = rand() % 200;

	this->setSize(Vector2f(playerYSize, playerXSize));
	this->setOrigin(Vector2f(this->getSize().x / 2, this->getSize().y / 2));
	this->setFillColor(Color(255, 255, 255, 255));
}
void Shooter::initTail()
{

	this->tail1.setSize(Vector2f(playerYSize / 1.5, playerXSize / 1.5));
	this->tail2.setSize(Vector2f(playerYSize / 1.75, playerXSize / 1.75));
	this->tail3.setSize(Vector2f(playerYSize / 2, playerXSize / 2));

	this->tail1.setOrigin(Vector2f((this->tail1.getSize().x / 2), (this->tail1.getSize().y / 2)));
	this->tail2.setOrigin(Vector2f((this->tail2.getSize().x / 2), (this->tail2.getSize().y / 2)));
	this->tail3.setOrigin(Vector2f((this->tail3.getSize().x / 2), (this->tail3.getSize().y / 2)));

	this->tail1.setFillColor(Color(224, 224, 224, 255));
	this->tail2.setFillColor(Color(192, 192, 192, 255));
	this->tail3.setFillColor(Color(160, 160, 160, 255));

	this->tail1.setPosition(this->getPosition());
	this->tail2.setPosition(this->getPosition());
	this->tail3.setPosition(this->getPosition());
}
void Shooter::movement(Shooter shooter[4], int width, int height)
{
	this->rotate(3);
	this->tail1.rotate(5);
	this->tail2.rotate(7);
	this->tail3.rotate(9);
	if (abs(this->tail1.getPosition().x - Mouse::getPosition().x) < 200 && abs(this->tail1.getPosition().y - Mouse::getPosition().y) < 200)
	{
	//Tail 3
	if (this->tail3.getPosition().x > this->tail2.getPosition().x)
	{
		this->tail3.setPosition(this->tail3.getPosition().x - this->tailSpeed * 0.08, this->tail3.getPosition().y);
	}
	if (this->tail3.getPosition().x < this->tail2.getPosition().x)
	{
		this->tail3.setPosition(this->tail3.getPosition().x + this->tailSpeed * .08, this->tail3.getPosition().y);
	}
	if (this->tail3.getPosition().y > this->tail2.getPosition().y)
	{
		this->tail3.setPosition(this->tail3.getPosition().x, this->tail3.getPosition().y - this->tailSpeed * .08);
	}
	if (this->tail3.getPosition().y < this->tail2.getPosition().y)
	{
		this->tail3.setPosition(this->tail3.getPosition().x, this->tail3.getPosition().y + this->tailSpeed * .08);
	}

	//Tail 2
	if (this->tail2.getPosition().x > this->tail1.getPosition().x)
	{
		this->tail2.setPosition(this->tail2.getPosition().x - this->tailSpeed * 0.09, this->tail2.getPosition().y);
	}
	if (this->tail2.getPosition().x < this->tail1.getPosition().x)
	{
		this->tail2.setPosition(this->tail2.getPosition().x + this->tailSpeed * 0.09, this->tail2.getPosition().y);
	}
	if (this->tail2.getPosition().y > this->tail1.getPosition().y)
	{
		this->tail2.setPosition(this->tail2.getPosition().x, this->tail2.getPosition().y - this->tailSpeed * 0.09);
	}
	if (this->tail2.getPosition().y < this->tail1.getPosition().y)
	{
		this->tail2.setPosition(this->tail2.getPosition().x, this->tail2.getPosition().y + this->tailSpeed * 0.09);
	}

	
		if (this->tail1.getPosition().x > Mouse::getPosition().x)
		{
			this->tail1.setPosition(this->tail1.getPosition().x + this->tailSpeed*0.1, this->tail1.getPosition().y);
		}
		if (this->tail1.getPosition().x < Mouse::getPosition().x)
		{
			this->tail1.setPosition(this->tail1.getPosition().x - this->tailSpeed * 0.1, this->tail1.getPosition().y);
		}
		if (this->tail1.getPosition().y > Mouse::getPosition().y)
		{
			this->tail1.setPosition(this->tail1.getPosition().x, this->tail1.getPosition().y + this->tailSpeed * 0.1);
		}
		if (this->tail1.getPosition().y < Mouse::getPosition().y)
		{
			this->tail1.setPosition(this->tail1.getPosition().x, this->tail1.getPosition().y - this->tailSpeed * 0.1);
		}





	}
	else if (abs(this->tail1.getPosition().x - Mouse::getPosition().x) < 250 && abs(this->tail1.getPosition().y - Mouse::getPosition().y) < 250)
	{
		if (abs(this->tail1.getPosition().x - Mouse::getPosition().x) > 200 && abs(this->tail1.getPosition().y - Mouse::getPosition().y) > 200)
		{

		}

	}
	else
	{
		//Tail 3
		if (this->tail3.getPosition().x > this->tail2.getPosition().x)
		{
			this->tail3.setPosition(this->tail3.getPosition().x - this->tailSpeed * .8, this->tail3.getPosition().y);
		}
		if (this->tail3.getPosition().x < this->tail2.getPosition().x)
		{
			this->tail3.setPosition(this->tail3.getPosition().x + this->tailSpeed * .8, this->tail3.getPosition().y);
		}
		if (this->tail3.getPosition().y > this->tail2.getPosition().y)
		{
			this->tail3.setPosition(this->tail3.getPosition().x, this->tail3.getPosition().y - this->tailSpeed * .8);
		}
		if (this->tail3.getPosition().y < this->tail2.getPosition().y)
		{
			this->tail3.setPosition(this->tail3.getPosition().x, this->tail3.getPosition().y + this->tailSpeed * .8);
		}

		//Tail 2
		if (this->tail2.getPosition().x > this->tail1.getPosition().x)
		{
			this->tail2.setPosition(this->tail2.getPosition().x - this->tailSpeed * 0.9, this->tail2.getPosition().y);
		}
		if (this->tail2.getPosition().x < this->tail1.getPosition().x)
		{
			this->tail2.setPosition(this->tail2.getPosition().x + this->tailSpeed * 0.9, this->tail2.getPosition().y);
		}
		if (this->tail2.getPosition().y > this->tail1.getPosition().y)
		{
			this->tail2.setPosition(this->tail2.getPosition().x, this->tail2.getPosition().y - this->tailSpeed * 0.9);
		}
		if (this->tail2.getPosition().y < this->tail1.getPosition().y)
		{
			this->tail2.setPosition(this->tail2.getPosition().x, this->tail2.getPosition().y + this->tailSpeed * 0.9);
		}
		//Tail 1
		if (this->tail1.getPosition().x > Mouse::getPosition().x)
		{
			this->tail1.setPosition(this->tail1.getPosition().x - this->tailSpeed, this->tail1.getPosition().y);
		}
		if (this->tail1.getPosition().x < Mouse::getPosition().x)
		{
			this->tail1.setPosition(this->tail1.getPosition().x + this->tailSpeed, this->tail1.getPosition().y);
		}
		if (this->tail1.getPosition().y > Mouse::getPosition().y)
		{
			this->tail1.setPosition(this->tail1.getPosition().x, this->tail1.getPosition().y - this->tailSpeed);
		}
		if (this->tail1.getPosition().y < Mouse::getPosition().y)
		{
			this->tail1.setPosition(this->tail1.getPosition().x, this->tail1.getPosition().y + this->tailSpeed);
		}
	}	

	FloatRect current = this->tail1.getGlobalBounds();

	for (int i = 0; i < 4; i++)
	{
		FloatRect other = shooter[i].tail1.getGlobalBounds();

		if (this->tail1.getPosition() != shooter[i].tail1.getPosition() && current.intersects(other))
		{
			if (this->tail1.getPosition().x > shooter[i].tail1.getPosition().x)
			{
				this->tail1.setPosition(Vector2f(this->tail1.getPosition().x + 3, this->tail1.getPosition().y));
			}
			if (this->tail1.getPosition().x < shooter[i].tail1.getPosition().x)
			{
				this->tail1.setPosition(Vector2f(this->tail1.getPosition().x - 3, this->tail1.getPosition().y));
			}
			if (this->tail1.getPosition().y > shooter[i].tail1.getPosition().y)
			{
				this->tail1.setPosition(Vector2f(this->tail1.getPosition().x, this->tail1.getPosition().y + 3));
			}
			if (this->tail1.getPosition().y < shooter[i].tail1.getPosition().y)
			{
				this->tail1.setPosition(Vector2f(this->tail1.getPosition().x, this->tail1.getPosition().y - 3));
			}
		}
	}


	if (abs(this->getPosition().x - Mouse::getPosition().x) < 200 && abs(this->getPosition().y - Mouse::getPosition().y) < 200)
	{
		if (this->getPosition().x > Mouse::getPosition().x)
		{
			this->setPosition(this->getPosition().x + this->speed, this->getPosition().y);
		}
		if (this->getPosition().x < Mouse::getPosition().x)
		{
			this->setPosition(this->getPosition().x - this->speed, this->getPosition().y);
		}
		if (this->getPosition().y > Mouse::getPosition().y)
		{
			this->setPosition(this->getPosition().x, this->getPosition().y + this->speed);
		}
		if (this->getPosition().y < Mouse::getPosition().y)
		{
			this->setPosition(this->getPosition().x, this->getPosition().y - this->speed);
		}
	}

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

		if (this->jitterCount >= 50)
		{
			this->jitterCount = 0;
			this->jitter = false;
		}
	}
}