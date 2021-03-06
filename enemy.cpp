#include "enemy.h"

Enemy::Enemy()
{
	//this->isDrawn = true;
}
Enemy::~Enemy()
{

}
void Enemy::initEnemy(int width, int height)
{
	//this->setPosition(Vector2f(this->genSpawnX(width), 0.f));

	this->respawnTimer = rand() % 200;
	cout << "Gen: " << this->respawnTimer << endl;
	//this->setPosition(200.f, 200.f);

	this->setSize(Vector2f(playerYSize, playerXSize));
	this->setOrigin(Vector2f(this->getSize().x / 2, this->getSize().y / 2));
	this->setFillColor(Color(127,0,255,255));
	this->setPosition(Vector2f(this->genSpawnX(width), -(height/3)));

}
void Enemy::initTail()
{

	this->tail1.setSize(Vector2f(playerYSize / 1.5, playerXSize / 1.5));
	this->tail2.setSize(Vector2f(playerYSize / 1.75, playerXSize / 1.75));
	this->tail3.setSize(Vector2f(playerYSize / 2, playerXSize / 2));

	this->tail1.setOrigin(Vector2f((this->tail1.getSize().x / 2), (this->tail1.getSize().y / 2)));
	this->tail2.setOrigin(Vector2f((this->tail2.getSize().x / 2),(this->tail2.getSize().y / 2)));
	this->tail3.setOrigin(Vector2f((this->tail3.getSize().x / 2), (this->tail3.getSize().y / 2)));

	this->tail1.setFillColor(Color(102, 0, 204, 255));
	this->tail2.setFillColor(Color(76, 0, 153, 255));
	this->tail3.setFillColor(Color(51, 0, 102, 255));

}
void Enemy::movement(float dt, int framerate)
{
	
	this->tail3.move(Vector2f(0.f, 4.4 * dt));
	this->tail2.move(Vector2f(0.f, 4.6 * dt));
	this->tail1.move(Vector2f(0.f, 4.8 * dt));

	this->rotate(3*dt);
	this->tail3.rotate(5*dt);
	this->tail2.rotate(5*dt);
	this->tail1.rotate(5*dt);

	this->move(Vector2f(0.f, 5.f * dt));

	if (this->jitter == true)
	{
		switch (jitterCount % 2)
		{
		case 0:
			this->setPosition(this->getPosition().x + jitterSize, this->getPosition().y);
			//this->move(jitterSize*dt, 0.f);
			this->jitterCount = this->jitterCount + 1;
			break;
		case 1:
			this->setPosition(this->getPosition().x - jitterSize, this->getPosition().y);
			//this->move(-jitterSize*dt, 0.f);
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
int Enemy::genSpawnX(int width)
{
	int num = (rand()+1)%width;
	//cout << "Random location: " << num << endl;
	return (num);
}
int Enemy::genSpawnY(int height)
{
	int num = (rand()+1)%height;
	//cout << "Random location: " << num << endl;
	return (num);
}
void Enemy::checkDespawn(int width, int height, float dt, int framerate)
{
	
	if (this->getPosition().y > (float)(height + (height/3)))
	{
		this->isDrawn = false;
		this->setPosition(Vector2f(this->genSpawnX(width), -(height / 3)));
		this->movement(dt, framerate);
		this->respawnTimer = (int)(abs(300*sin(rand())));
	}
}
void Enemy::checkSpawn(float dt)
{
	if (this->respawnTimer == 0)
	{
		this->tail3.setPosition(this->getPosition());
		this->tail2.setPosition(this->getPosition());
		this->tail1.setPosition(this->getPosition());
		this->jitter = false;
		this->isDrawn = true;
	}
	if (this->isDrawn == false)
	{
		this->respawnTimer = this->respawnTimer - 1 * dt;
	}
}