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
	void initMouseBox();
	void initButton();
	bool mouseCollide = false;
	bool mouseCollideO = false;
	bool mouseCollideE = false;
	void initVariables();
	void initWindow();
	void initFont();
	void initText();
	Font font;
	Text text;
	Text title;
	Text options;
	Text exit;
	Clock clock;
	float dt;
	float reg;
	int state = 0;

	Game game;


	void update();
	void render();
	void pollEvents();

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