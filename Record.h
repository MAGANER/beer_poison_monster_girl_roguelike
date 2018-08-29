#pragma once
#include"stdafx.h"
#include<fstream>

int maximal_step = 0;

Text max_step;
Vector2f max_step_pos;

void draw_records(RenderWindow & window)
{
	max_step_pos.x = 100;
	max_step_pos.y = 100;

	max_step.setPosition(max_step_pos);
	max_step.setString("maximal step:"+to_string(maximal_step));

	window.draw(max_step);
}
void get_max_step_from_file()
{
	ifstream file("d");
	file >> maximal_step;
	file.close();
}
void set_max_step_to_file()
{
	ofstream file("d");
	file << maximal_step;
	file.close();
}

