#pragma once
#include "header.h"
#include "enemy.h"
class Shooter: public Enemy
{
public:
	void initEnemy();
	void initTail();
	void movement(Shooter shooter[4]);
	int speed = 2;
	int tailSpeed = 3;
private:
};

