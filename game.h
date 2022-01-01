#pragma once
#include "header.h"
#include "enemy.h"
#include "homing.h"
#include "health.h"
#include "Bomb.h"
#include "Area.h"
#include "Shooter.h"

class Game
{
private:
	//Variables
	//Window
	
public:

	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Functions

	void initVariables();
	void initCharacter();
	void initFont();
	void initAudio();
	void initFlash(int width, int height);
	void updateFlash();
	void playTrack();
	void updateBeatClock();
	void initText(RenderWindow* window);
	void jitterStart();
	void initWindowSize(int width, int height);
	bool jitter = false;
	bool firstPlay = true;
	int windowWidth;
	int windowHeight;

	double beatClock = 0.0;

	int jitterCount = 0;
	int jitterSize = 10;
	int flashCount = 0;
	int life = 3;
	int basicCount = 7;
	int homingCount = 5;
	int healthCount = 3;
	int areaCount = 5;
	int shooterCount = 4;
	int shieldOpacity = 255;
	Font font;
	Text uiText;
	Music track;
	Music Kick;
	Music KickTail;
	Music BassSynth;
	Music Lead1;
	Music Lead1Tail;
	Music Lead2;
	Music Lead2Tail;
	Music Lead3;
	Music Lead3Tail;
	Music Pad;

	SoundBuffer DropBombBuff;
	SoundBuffer HealBuff;
	SoundBuffer HurtBuff;
	SoundBuffer EnemyDieBuff;
	SoundBuffer StartBuff;
	SoundBuffer RolloverBuff;

	Sound Hurt;
	Sound DropBomb;
	Sound Heal;
	Sound EnemyDie;
	Sound Start;
	Sound Rollover;

	Bomb bomb;

	//Game Objects

	Enemy basic[7];
	Homing homing[5];
	Health health[3];
	Area area[5];
	Shooter shooter[4];

	void enemyUpdate(int width, int height);
	void shieldUpdate();
	void collision();
	void takeHit();
	void scoreUpdate();
	int randomRespawn();

	void updateFrameClock();
	void updateTimeClock();

	void renderText();
	void updateText();

	RectangleShape flash;
	RectangleShape character;
	RectangleShape tail1;
	RectangleShape tail2;
	RectangleShape tail3;
	int draw1 = 1;
	int draw2 = 1;
	int draw3 = 1;
	int score = 0;
	int frameClock = 0;
	int timeClock = 0;
	void initTail();

	const bool running() const;


	//Test Functions
	void testRange();
	void testLife();
	void testCollision();
	void testShield();
	void testBomb();

};