#include<SFML/Graphics.hpp>
#include"rule_variables.h"
#include"stdafx.h"
#include"objects.h"
#include<iostream>

using namespace std;

void generate_object();
void check_hero_acrossed_border(string direction);
void set_hero_on_map();
void draw_action_line();
void draw_vertical_borders();
void draw_borders();
int main()
{
	
	action.setFont(font);
	hero.setCharacterSize(36);


	font.loadFromFile("9303.ttf");
	hero.setFont(font);
	hero.setCharacterSize(36);
	hero.setString("@");

	object.setFont(font);
	object.setCharacterSize(36);
	object.setString("?");
	action_pos.x = 100;
	action_pos.y = 100;
	action.setPosition(action_pos);

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
		if (alive)
		{
			if (hero_step)
			{
				if (object_type != 5 || object_type != 6)
				{
					if (Keyboard::isKeyPressed(Keyboard::Num1))
					{
						hero_acts = 1;
					}
					if (Keyboard::isKeyPressed(Keyboard::Num2))
					{
						hero_acts = 2;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::F1))
				{
					cout << "x:" << hero_pos.x << endl;
					cout << "y:" << hero_pos.y << endl;

				}
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
						if (hero_acts == 1)
						{
							if (object_type == 1)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you drunk beer, you feel good...");
								action.setPosition(action_pos);
								show_object = false;
							}
							if (object_type == 2)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you drunk poison, you died...");
								action.setPosition(action_pos);
								alive = false;
								show_hero = false;
								hero_is_killed = true;
								show_object = false;
							}
							if (object_type == 3)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you drunk monster, you died...");
								action.setPosition(action_pos);
								alive = false;
								show_hero = false;
								hero_is_killed = true;
								show_object = false;
							}
							if (object_type == 4)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you fucked girl, you feel good...");
								action.setPosition(action_pos);
								show_object = false;
							}
							if (object_type == 5 || object_type == 6)
							{
								// do nothing
							}
							direction = "0";

						}
						if (hero_acts == 2)
						{
							if (object_type == 1)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you broke beer, you feel  good...");
								action.setPosition(action_pos);
								show_object = false;
							}
							if (object_type == 2)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you broke poison, you feel  good...");
								action.setPosition(action_pos);
								show_object = false;
							}
							if (object_type == 3)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you killed monster, you feel  good...");
								action.setPosition(action_pos);
								show_object = false;
							}
							if (object_type == 4)
							{
								action_pos.x = 100;
								action_pos.y = 100;
								action.setString("you killed girl, god damn it...");
								action.setPosition(action_pos);
								show_object = false;
							}
							if (object_type == 5 || object_type == 6)
							{
								// do nothing
							}
							direction = "0";
						}
						if (direction == "up")
						{
							Vector2f heropos = hero.getPosition();

							hero_pos.x = heropos.x;
							hero_pos.y = heropos.y;

							hero_pos.y -= 32;
							hero.setPosition(hero_pos);
							stop = true;
							hero_step = false;
						}
						if (direction == "down")
						{
							Vector2f heropos = hero.getPosition();

							hero_pos.x = heropos.x;
							hero_pos.y = heropos.y;

							hero_pos.y += 32;
							hero.setPosition(hero_pos);
							stop = true;
							hero_step = false;
						}
						if (direction == "left")
						{
							Vector2f heropos = hero.getPosition();

							hero_pos.x = heropos.x;
							hero_pos.y = heropos.y;

							hero_pos.x -= 32;
							hero.setPosition(hero_pos);
							stop = true;
							hero_step = false;
						}
						if (direction == "right")
						{
							Vector2f heropos = hero.getPosition();

							hero_pos.x = heropos.x;
							hero_pos.y = heropos.y;

							hero_pos.x += 32;
							hero.setPosition(hero_pos);
							stop = true;
							hero_step = false;
						}

						direction = "0";
						hero_acts = -1;
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
		}
/////////////////////////////////////////////
///////////ACTIONS///////////////////////////
     check_hero_acrossed_border(direction);
     if (!alive)
     { 
		 if (hero_is_killed)
		 {
			 
		 }
		 else {
			 action_pos.x = 100;
			 action_pos.y = 100;
			 action.setString("you fucking died...noob");
			 action.setPosition(action_pos);
		 }
		 show_hero = false;
     }
	 if (!hero_step)
	 {
		 generate_object();
		 hero_step = true;
	 }


//////////////////////////////////////////////
//////////////////////////////////////////////
////////////DRAWING///////////////////////////
//////////////////////////////////////////////
		window.clear();
		if (show_hero)
		{
			window.draw(hero);
		}
		if (show_object)
		{
			window.draw(object);
		}
		window.draw(action);
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
	srand(time( (unsigned int) 0));
	int y = 140 + rand() % 480;
	int x = 20 + rand() % 370;

	Vector2f hero_pos;
	hero_pos.y =(float) y;
	hero_pos.x = (float)x;
	hero.setPosition(hero_pos);
}
void check_hero_acrossed_border(string direction)
{
	Vector2f hero_pos;
	hero_pos = hero.getPosition();

	if (direction == "up")
	{
		if (hero_pos.y < 140)
		{
			alive = false;
			show_object = false;
	    }
	}
	if (direction == "down")
	{
		if (hero_pos.y >540)
		{
			alive = false;
			show_object = false;
		}
	}
	if (direction == "left")
	{
		if (hero_pos.x < 5)
		{
			alive = false;
			show_object = false;
		}
	}
	if (direction == "right")
	{
		if (hero_pos.x >790)
		{
			alive = false;
			show_object = false;
		}
	}
}
void generate_object()
{
	srand(time((unsigned int)0));
	object_type = 1 + rand() % 6;
	int object_direction = 1 + rand() % 4;
	//1 - left
	//2 - right
	//3 - up
	//4 - down
	if (object_direction == 1)
	{
		object_pos.x = hero_pos.x - 32;
		object_pos.y = hero_pos.y;
	}
	if (object_direction == 2)
	{
		object_pos.x = hero_pos.x + 32;
		object_pos.y = hero_pos.y;
	}
	if (object_direction == 3)
	{
		object_pos.y = hero_pos.y - 32;
		object_pos.x = hero_pos.x;
	}
	if (object_direction == 4)
	{
		object_pos.y = hero_pos.y + 32;
		object_pos.x = hero_pos.x;
	}
	object.setPosition(object_pos);
	if (object_type == 1)
	{
		object_ = "beer";
		show_object = true;
		//it is a beer
		action_pos.x = 100;
		action_pos.y = 100;
		action.setString("you see fucking something...");
		action.setPosition(action_pos);
	}
	if (object_type == 2)
	{
		object_ = "poison";
		show_object = true;
		//it is a poison
		action_pos.x = 100;
		action_pos.y = 100;
		action.setString("you see fucking something...");
		action.setPosition(action_pos);
	}
	if (object_type == 3)
	{
		object_ = "monster";
		show_object = true;
		//it is a monster
		action_pos.x = 100;
		action_pos.y = 100;
		action.setString("you see fucking something...");
		action.setPosition(action_pos);
	}
	if (object_type == 4)
	{
		object_ = "girl";
		show_object = true;
		//it is a girl
		action_pos.x = 100;
		action_pos.y = 100;
		action.setString("you see fucking something...");
		action.setPosition(action_pos);
	}
	if (object_type == 5 || object_type == 6)
	{
		// it is nothing
		action_pos.x = 100;
		action_pos.y = 100;
		action.setString("you see fucking nothing...");
		action.setPosition(action_pos);
		object_ = "nothing";
		show_object = false;
	}
}