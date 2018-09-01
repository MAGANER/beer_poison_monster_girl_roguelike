#pragma once
#include"StartWindow.h"


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

Vector2f commandsts_pos;
Text commands_to_show;

void set_commands_parameters()
{
	commands_to_return.setCharacterSize(36);
	commands_to_return.setString("Esc - to return to life/game");
	commandstr_pos.x = 100;
	commandstr_pos.y = 200;
	commands_to_return.setPosition(commandstr_pos);

	commands_to_take.setCharacterSize(36);
	commands_to_take.setString("Space - to take action");
	commandstt_pos.x = 100;
	commandstt_pos.y = 250;
	commands_to_take.setPosition(commandstt_pos);

	commands_to_kill.setCharacterSize(36);
	commands_to_kill.setString("2 - to kill");
	commandstk_pos.x = 100;
	commandstk_pos.y = 150;
	commands_to_kill.setPosition(commandstk_pos);

	commands_to_eat.setCharacterSize(36);
	commands_to_eat.setString("1 - to eat/drink/fuck");
	commandste_pos.x = 100;
	commandste_pos.y = 100;
	commands_to_eat.setPosition(commandste_pos);

	commands_to_go.setCharacterSize(36);
	commands_to_go.setString("W,S,D,A - move hero");
	commandstg_pos.x = 100;
	commandstg_pos.y = 50;
	commands_to_go.setPosition(commandstg_pos);

	commands_to_show.setCharacterSize(36);
	commands_to_show.setString("R - to show statistic");
	commandsts_pos.x = 100;
	commandsts_pos.y = 300;
	commands_to_show.setPosition(commandsts_pos);
}
void draw_main_menu(RenderWindow & window)
{
	window.draw(commands_to_go);
	window.draw(commands_to_eat);
	window.draw(commands_to_kill);
	window.draw(commands_to_return);
	window.draw(commands_to_take);
	window.draw(commands_to_show);
}