#include<SFML/Graphics.hpp>
#include"rule_variables.h"
#include"stdafx.h"
#include"objects.h"

void draw_borders();
int main()
{
	font.loadFromFile("9303.ttf");


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

/////////////////////////////////////////////
///////////ACTIONS///////////////////////////


//////////////////////////////////////////////
//////////////////////////////////////////////
////////////DRAWING///////////////////////////
//////////////////////////////////////////////
		window.clear();
	
		draw_borders();
		window.display();
//////////////////////////////////////////////
//////////////////////////////////////////////
	}

	return 0;
}
void draw_borders()
{
	Text border;
	border.setFont(font);
	border.setString("fuckyou");
	border.setCharacterSize(24);
	Vector2f border_pos_up;
	border_pos_up.x = 0;

	for (int i = 0; i < 7; i++)
	{
		window.draw(border);
		border_pos_up.x += 120;
		border.setPosition(border_pos_up);
	}

	Vector2f border_pos_up2;
	border_pos_up2.x = 0;
	border_pos_up2.y = 60;
	for (int i = 0; i < 7; i++)
	{
		window.draw(border);
		border_pos_up.x += 120;
		border.setPosition(border_pos_up);
	}

	Vector2f border_pos_down;
	border_pos_down.x = 0;
	border_pos_down.y = 576;
	for (int i = 0; i < 7; i++)
	{
		window.draw(border);
		border_pos_down.x += 120;
		border.setPosition(border_pos_down);
	}

	border_pos_down.y = 576;
	border_pos_down.x = 0;
	border.setPosition(border_pos_down);
	window.draw(border);

}