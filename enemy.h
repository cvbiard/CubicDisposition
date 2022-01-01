#pragma once
#include "header.h"
class Enemy: public RectangleShape
{
private:
	

public:
	int respawnTimer = 0;
	RectangleShape tail1;
	RectangleShape tail2;
	RectangleShape tail3;
	bool isDrawn = false;
	bool jitter = false;
	int jitterCount = 0;
	int jitterSize = 10;
	int randMove = 0;
	virtual void initTail();
	Enemy();
	virtual void movement();
	int genSpawnY(int height);
	int genSpawnX(int width);
	void checkSpawn();
	virtual void checkDespawn(int width, int height);
	virtual ~Enemy();
	virtual void initEnemy(int width, int height);
};

