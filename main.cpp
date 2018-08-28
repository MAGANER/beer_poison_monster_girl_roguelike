#include"rule_variables.h"
#include"stdafx.h"
#include"objects.h"
#include<iostream>
#include"Hero.h"
#include"Start_window.h"
#include"Border.h"
#include"Object.h"
#include"Action.h"

void init(Font font);

int main()
{
	Font font;
	RenderWindow window(sf::VideoMode(800, 600), "WORLDOFFUCKINGSORROW");

	

	init(font);
	
	while (window.isOpen())
	{

//////////EVENT CHECKING//////////////////////
//////////////////////////////////////////////
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

////////KEY PRESSING/////////////////////////
/////////////////////////////////////////////
		if (game)
		{
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
							//eat or kill object
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

							//gowing
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
			if (!alive)
			{
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					show_hero = true;
					alive = true;
					set_hero_on_map();
					action_pos.x = 100;
					action_pos.y = 100;
					action.setString("you was born...again");
					action.setPosition(action_pos);
				}
			}
		}
       else {
		   if (Keyboard::isKeyPressed(Keyboard::Space))
		   {
			   game = true;
		   }
       }

///////////ACTIONS///////////////////////////
/////////////////////////////////////////////
		if (game)
		{
			check_hero_acrossed_border(direction, show_object);
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
				generate_object(hero_pos, action, action_pos);
				hero_step = true;
			}

		}

////////////DRAWING///////////////////////////
//////////////////////////////////////////////
		window.clear();
		if (game)
		{
			if (show_hero)
			{
				window.draw(hero);
			}
			if (show_object)
			{
				window.draw(object);
			}
			window.draw(action);
			draw_vertical_borders(font, window);
			draw_action_line(font, window);
			draw_borders(font, window);
			
		}
		else {
			draw_main_menu(window);
		}
		window.display();
//////////////////////////////////////////////

	}

	return 0;
}
void init(Font font)
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

	commands_to_go.setFont(font);
	commands_to_go.setCharacterSize(36);
	commands_to_go.setString("W,S,D,A - move hero");
	commandstg_pos.x = 100;
	commandstg_pos.y = 100;
	commands_to_go.setPosition(commandstg_pos);


	commands_to_eat.setFont(font);
	commands_to_eat.setCharacterSize(36);
	commands_to_eat.setString("1 - to eat/drink/fuck");
	commandste_pos.x = 100;
	commandste_pos.y = 250;
	commands_to_eat.setPosition(commandste_pos);


	commands_to_kill.setFont(font);
	commands_to_kill.setCharacterSize(36);
	commands_to_kill.setString("2 - to kill");
	commandstk_pos.x = 100;
	commandstk_pos.y = 350;
	commands_to_kill.setPosition(commandstk_pos);


	commands_to_return.setFont(font);
	commands_to_return.setCharacterSize(36);
	commands_to_return.setString("Esc - to return to life");
	commandstr_pos.x = 100;
	commandstr_pos.y = 450;
	commands_to_return.setPosition(commandstr_pos);


	commands_to_take.setFont(font);
	commands_to_take.setCharacterSize(36);
	commands_to_take.setString("Space - to take action");
	commandstt_pos.x = 100;
	commandstt_pos.y = 550;
	commands_to_take.setPosition(commandstt_pos);
	set_hero_on_map();
}


