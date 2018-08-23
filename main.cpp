#include<SFML/Graphics.hpp>
#include"rule_variables.h"
#include"stdafx.h"
#include"objects.h"
#include<iostream>

using namespace std;
Text hero;

void draw_vertical_borders();
void draw_borders();
int main()
{
	font.loadFromFile("9303.ttf");
	hero.setFont(font);
	hero.setCharacterSize(48);
	hero.setString("@");

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
		window.draw(hero);
		draw_vertical_borders();
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
void draw_vertical_borders()
{
	Text border;
	border.setFont(font);
	border.setString("fuckyou");
	border.setCharacterSize(24);
	border.setRotation(90);
	Vector2f pos;
	pos.x = 30;
	pos.y = 0;
	for (int i = 0; i < 7; i++)
	{
		window.draw(border);
		pos.y += 120;
		border.setPosition(pos);

	}
	pos.y = 0;
	border.setPosition(pos);
	window.draw(border);

	pos.x = 800;
	pos.y = 0;
	for (int i = 0; i < 7; i++)
	{
		window.draw(border);
		pos.y += 120;
		border.setPosition(pos);
	}
	pos.y = 0;
	border.setPosition(pos);
	window.draw(border);
}