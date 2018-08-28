#pragma once
#include"stdafx.h"

Font font;

Vector2f hero_pos;
Vector2f action_pos;
Vector2f object_pos;
RenderWindow window(sf::VideoMode(800, 600), "WORLDOFFUCKINGSORROW");

Text action;
Text hero;
Text object;

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
