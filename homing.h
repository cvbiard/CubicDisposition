#pragma once
#include "header.h"
#include "enemy.h"
class Homing: public Enemy
{
public:
	void movement(Homing homing[5], float dt, int framerate);
	void initEnemy(int width, int height);
	int speed = 5;
	int lifeClock = 0;
	int accelV = 0;
	int speedV = 0;
	int maxSpeed = 6;
	void initTail();
	void checkDespawn(int width);
private:
};

