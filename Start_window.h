#pragma once
#include"stdafx.h"



// show that at the begging

Vector2f commandstg_pos;
Text commands_to_go;


Vector2f commandste_pos;
Text commands_to_eat;


Vector2f commandstk_pos;
Text commands_to_kill;


Vector2f commandstr_pos;
Text commands_to_return;


Vector2f commandstt_pos;
Text commands_to_take;

void draw_main_menu(RenderWindow & window)
{
	window.draw(commands_to_go);
	window.draw(commands_to_eat);
	window.draw(commands_to_kill);
	window.draw(commands_to_return);
	window.draw(commands_to_take);
}