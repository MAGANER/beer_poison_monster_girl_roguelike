#pragma once
#include"stdafx.h"

bool show_object = false;
int  object_type;
string object_; // beer, poison, girl, monster


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