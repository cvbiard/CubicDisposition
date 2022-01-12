#pragma once
#include "header.h"
#include "enemy.h"
#include "game.h"

class Menu
{
public:
	RenderWindow* window;
	Event ev;
	VideoMode videoMode;
	RectangleShape button;
	RectangleShape optionsButton;
	RectangleShape exitButton;
	RectangleShape mouseBox;
	RectangleShape backButton;
	void initMouseBox();
	void initButton();
	bool mouseCollide = false;
	bool mouseCollideO = false;
	bool mouseCollideE = false;
	bool mouseCollideB = false;
	bool mouseCollide1 = false;
	bool mouseCollide2 = false;
	bool mouseCollide3 = false;
	bool mouseCollide4 = false;
	bool mouseCollide5 = false;
	bool mouseCollideS = false;
	bool mouseCollideM = false;
	void initVariables();
	void initWindow();
	void initFont();
	void initText();
	Font font;
	Text text;
	Text title;
	Text SFX;
	Text Music;
	Text optionsText;
	Text options;
	Text exit;
	Text back;
	Text frCap;
	Text FPS30;
	Text FPS60;
	Text FPS144;
	Text FPS240;
	RectangleShape dropdown;
	RectangleShape dropdown30;
	RectangleShape dropdown60;
	RectangleShape dropdown144;
	RectangleShape dropdown240;
	RectangleShape sfxBox;
	RectangleShape musicBox;
	Clock clock;
	float dt;
	bool music = true;
	bool sfx = true;
	bool visibleMenu;
	float reg;
	int state = 0;
	int framerate = 60;

	Game game;


	void update();
	void render();
	void pollEvents();
	void resetGame();

	void checkClick();
	void updateMouseBox();

	void randomizeSpawns();

	void renderText();
	void updateText();

	void updateRand();

	Menu();
	virtual ~Menu();

	const bool running() const;

private:

};