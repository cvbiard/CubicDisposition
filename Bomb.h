#pragma once
#include "header.h"
class Bomb
{

public:
	bool explode;
	bool dropped;
	bool damage;
	bool dealt;
	int count = 0;

	Bomb();
	~Bomb();

	RectangleShape visual;
	RectangleShape square1;
	RectangleShape square2;
	RectangleShape square3;
	RectangleShape square4;

	SoundBuffer BombSoundBuff;
	Sound BombSound;

	void initBomb();
	void updateBomb();
	void updateEffects();
private:

};

