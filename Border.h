#pragma once
#include"stdafx.h"

void draw_borders(Font font, RenderWindow & window)
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
void draw_vertical_borders(Font font, RenderWindow & window)
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
void draw_action_line(Font font, RenderWindow & window)
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
