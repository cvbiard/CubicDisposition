#pragma once
#include "header.h"
#include "enemy.h"
class Area: public Enemy
{
public:
	void movement(Area area[5]);
	void initEnemy();
	int speed = 5;
	int lifeClock = 0;
	int accelV = 0;
	int speedV = 0;
	int maxSpeed = 6;
	void initTail();
	void checkDespawn();
private:
};

