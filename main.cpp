#include"Map.h"
#include"rule_variables.h"
#include"stdafx.h"
#include<iostream>
#include"StartWindow.h"
#include"Hero.h"
#include"Object.h"
#include"Record.h"


Font font;

void init();
int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "WORLDOFFUCKINGSORROW");
	init();
	
	while (window.isOpen())
	{
//////////////////////////////////////////////
//////////EVENT///////////////////////////////
//////////////////////////////////////////////
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{

				window.close();
			}
		
		}
//////////////////////////////////////////////
/////////////////////////////////////////////
////////KEY PRESSING/////////////////////////
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

					if (Keyboard::isKeyPressed(Keyboard::R))
					{
						records = true;
						game = false;
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
									maximal_step++;
									good_actions++;
								}
								if (object_type == 2)
								{
									action_pos.x = 100;
									action_pos.y = 100;
									action.setString("you drunk poison, you died...");
									action.setPosition(action_pos);
									evil_actions++;
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
									evil_actions++;
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
									maximal_step++;
									good_actions++;
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
									maximal_step++;
									evil_actions++;
								}
								if (object_type == 2)
								{
									action_pos.x = 100;
									action_pos.y = 100;
									action.setString("you broke poison, you feel  good...");
									action.setPosition(action_pos);
									show_object = false;
									maximal_step++;
									good_actions++;
								}
								if (object_type == 3)
								{
									action_pos.x = 100;
									action_pos.y = 100;
									action.setString("you killed monster, you feel  good...");
									action.setPosition(action_pos);
									show_object = false;
									maximal_step++;
									good_actions++;
								}
								if (object_type == 4)
								{
									action_pos.x = 100;
									action_pos.y = 100;
									action.setString("you killed girl, god damn it...");
									action.setPosition(action_pos);
									show_object = false;
									maximal_step++;
									evil_actions++;
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
								maximal_step++;
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
								maximal_step++;
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
								maximal_step++;

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
								maximal_step++;
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

	   if (records)
	   {
		   if (Keyboard::isKeyPressed(Keyboard::Escape))
		   {
			   game = true;
			   records = false;
		   }
	   }
/////////////////////////////////////////////
///////////ACTIONS///////////////////////////
		if (game)
		{
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
				generate_object(object_pos, hero_pos);
				hero_step = true;
			}

		}
//////////////////////////////////////////////
//////////////////////////////////////////////
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
			draw_statistic(window);
			
			
			window.draw(action);
			draw_vertical_borders(font,window);
			draw_action_line(font, window);
			draw_borders(font, window);
			
		}
		if (!game && !records)
		{
			draw_main_menu(window);
		}
		if (!game && records)
		{
			
			draw_records(window);
		}

		window.display();
//////////////////////////////////////////////
//////////////////////////////////////////////
	}
	return 0;
}


void init()
{

	good.setFont(font);
	evil.setFont(font);
	action.setFont(font);
	hero.setCharacterSize(36);


	font.loadFromFile("9303.ttf");
	hero.setFont(font);
	hero.setCharacterSize(36);
	hero.setString("@");


	max_step.setFont(font);

	object.setFont(font);
	object.setCharacterSize(36);
	object.setString("?");
	action_pos.x = 100;
	action_pos.y = 100;
	action.setPosition(action_pos);

	commands_to_show.setFont(font);
	commands_to_go.setFont(font);
	commands_to_eat.setFont(font);
	commands_to_kill.setFont(font);
	commands_to_return.setFont(font);
	commands_to_take.setFont(font);
	set_commands_parameters();

	set_hero_on_map();
}