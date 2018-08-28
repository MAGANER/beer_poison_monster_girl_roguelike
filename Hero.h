#pragma once
#include"Hero.h"
#include"Object.h"
bool hero_step = true;
string direction;
bool alive = true; 
bool show_hero = true;
int hero_acts;
bool hero_is_killed = false;

void set_hero_on_map()
{
	srand(time((unsigned int)0));
	int y = 140 + rand() % 480;
	int x = 20 + rand() % 370;

	Vector2f hero_pos;
	hero_pos.y = (float)y;
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
