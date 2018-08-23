#include<SFML/Graphics.hpp>
#include"rule_variables.h"
#include"stdafx.h"
#include"objects.h"
#include"main_menu.h"

int main()
{
	init_game_menu();


	while (window.isOpen())
	{
//////////////////////////////////////////////
//////////EVENT///////////////////////////////
//////////////////////////////////////////////
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
//////////////////////////////////////////////
/////////////////////////////////////////////
////////KEY PRESSING/////////////////////////
		if (game)
		{

        }
		if (game_menu)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				game = true;
				game_menu = false;
			}
		}

/////////////////////////////////////////////
///////////ACTIONS///////////////////////////


//////////////////////////////////////////////
//////////////////////////////////////////////
////////////DRAWING///////////////////////////
//////////////////////////////////////////////
		window.clear();
		if (game)
		{

		}
		if (game_menu)
		{
			draw_main_menu(window);
		}
		window.display();
//////////////////////////////////////////////
//////////////////////////////////////////////
	}

	return 0;
}