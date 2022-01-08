#include "header.h"
#include "game.h"
#include "menu.h"

//To do:
//1. Fix screen size related bugs - DONE
//2. Framerate independent gameplay - DONE
//3. Options
//4. Balance
//5. Installer

int main(void)
{
	ofstream outfile("test.txt");

	outfile << "my text here!" << std::endl;

	outfile.close();

	srand(time(NULL));
	

	Menu menu;


	std::cout << "Hello world" << std::endl;
	

	while (menu.running())
	{
	
		menu.game.timeClock = menu.game.timeClock+1;
		menu.update();


		menu.render();
		menu.dt = menu.clock.restart().asSeconds();
		menu.reg = menu.dt * multi;
	}
	

	return 0;
}