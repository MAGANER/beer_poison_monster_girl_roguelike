#pragma once
#include"stdafx.h"



Font font;
Text name;
GameObject skull("3872196.jpg");

void init_game_menu()
{
	skull.set_pos(120, 100);
	font.loadFromFile("9303.ttf");
	name.setFont(font);
	name.setString("WORLDOFFUCKINGSORROW");
	name.setCharacterSize(48);
	Vector2f pos;
	pos.x = 40;
	pos.y = 20;
	name.setPosition(pos);
}
void draw_main_menu(RenderWindow & window)
{
	window.draw(name);
	window.draw(skull.returnSprite());
}