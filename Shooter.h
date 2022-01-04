#pragma once
#include "header.h"
#include "enemy.h"
class Shooter: public Enemy
{
public:
	void initEnemy(int width, int height);
	void initTail();
	void movement(Shooter shooter[4], int width, int height, float dt);
	int speed = 2;
	int tailSpeed = 3;
private:
};

