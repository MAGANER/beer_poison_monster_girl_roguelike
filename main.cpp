#include<SFML/Graphics.hpp>
#include"rule_variables.h"
#include"stdafx.h"
#include"objects.h"
#include<iostream>

using namespace std;
Text hero;

void set_hero_on_map();
void draw_action_line();
void draw_vertical_borders();
void draw_borders();
int main()
{
	Vector2f hero_pos;

	font.loadFromFile("9303.ttf");
	hero.setFont(font);
	hero.setCharacterSize(36);
	hero.setString("@");


	set_hero_on_map();
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
		if (hero_step)
		{
			if (Keyboard::isKeyPressed(Keyboard::W))
			{

				direction = "up";
				
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				direction = "down";
				
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				direction = "left";
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				direction = "right";
			}
			if (!stop)
			{
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (direction == "up")
					{
						Vector2f heropos = hero.getPosition();

						hero_pos.x = heropos.x;
						hero_pos.y = heropos.y;

						hero_pos.y -= 32;
						hero.setPosition(hero_pos);
						stop = true;
					}
					if (direction == "down")
					{
						Vector2f heropos = hero.getPosition();

						hero_pos.x = heropos.x;
						hero_pos.y = heropos.y;

						hero_pos.y += 32;
						hero.setPosition(hero_pos);
						stop = true;
					}
					if (direction == "left")
					{
						Vector2f heropos = hero.getPosition();

						hero_pos.x = heropos.x;
						hero_pos.y = heropos.y;

						hero_pos.x -= 32;
						hero.setPosition(hero_pos);
						stop = true;
					}
					if (direction == "right")
					{
						Vector2f heropos = hero.getPosition();

						hero_pos.x = heropos.x;
						hero_pos.y = heropos.y;

						hero_pos.x += 32;
						hero.setPosition(hero_pos);
						stop = true;
					}
				}
			}
			if (stop)
			{	
				if (!Keyboard::isKeyPressed(Keyboard::Space))
				{
						stop = false;
				}
	

			}
        }


//////////////////////////////////////////////
//////////////////////////////////////////////
////////////DRAWING///////////////////////////
//////////////////////////////////////////////
		window.clear();
		window.draw(hero);
		draw_vertical_borders();
		draw_action_line();
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

	pos.x = 810;
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
void draw_action_line()
{
	Text border;
	border.setFont(font);
	border.setString("fuckyou");
	border.setCharacterSize(24);
	Vector2f border_pos_up;
	border_pos_up.x = 0;
	border_pos_up.y = 140;
	for (int i = 0; i < 7; i++)
	{
		window.draw(border);
		border_pos_up.x += 120;
		border.setPosition(border_pos_up);
	}
	border_pos_up.x = 0;
	border_pos_up.y = 140;
	border.setPosition(border_pos_up);
	window.draw(border);
}
void set_hero_on_map()
{
	srand(time(0));
	int y = 140 + rand() % 520;
	int x = 20 + rand() % 680;

	Vector2f hero_pos;
	hero_pos.y =(float) y;
	hero_pos.x = (float)x;
	hero.setPosition(hero_pos);
}