#include "header.h"
#include "game.h"
#include "menu.h"
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
	}
	

	return 0;
}