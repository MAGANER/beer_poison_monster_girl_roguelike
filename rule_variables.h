#pragma once
// these variables are used to manage game
#include"stdafx.h"

bool hero_step = true;
bool stop = false;
string direction;
bool alive = true; // if hero is alive than this equals true
bool show_hero = true;
bool show_object = false;
int  object_type;
string object_; // beer, poison, girl, monster
int hero_acts;
bool hero_is_killed = false;
