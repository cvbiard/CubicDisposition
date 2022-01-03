#pragma once
#include "enemy.h"
#include "header.h"
class Health: public Enemy
{
public:
	Sprite sprite;
	Texture texture;
	void initSprite();
	void initTexture();
	void initEnemy(int width, int height);
	void movement(int width, int height, float dt);
	int speed = 5;
	int timeClock = 0;
	int randMove = 0;
	int lifeClock = 0;
	int accelV = 0;
	int speedV = 0;
	int maxSpeed = 6;
	void initTail();
	void checkDespawn(int width);
private:
};

