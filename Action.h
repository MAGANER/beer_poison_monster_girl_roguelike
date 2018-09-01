#pragma once
#include"stdafx.h"

Vector2f action_pos;
Text action;


int good_actions = 0;
Vector2f good_pos;
Text good;


int evil_actions = 0;
Vector2f evil_pos;
Text evil;

void set_statitic()
{
	good.setString("good: " + to_string(good_actions));
    evil.setString("evil: " + to_string(evil_actions));
}
void draw_statistic(RenderWindow & window)
{
	set_statitic();

	good_pos.x = 60;
	good_pos.y = 60;

	good.setCharacterSize(36);
	good.setPosition(good_pos);

	evil_pos.y = 60;
	evil_pos.x = 400;
	
	evil.setCharacterSize(36);
	evil.setPosition(evil_pos);

	window.draw(good);
	window.draw(evil);
}