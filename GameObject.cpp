#include "GameObject.h"

float GameObject::get_x()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.x;
}
float GameObject::get_y()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.y;
}
void GameObject::set_pos(float x, float y)
{
	gobject_spr.setPosition(x, y);
}
Sprite GameObject::returnSprite()
{
	return gobject_spr;
}
GameObject::GameObject(string img_f)
{
	img_file = img_f;
	gobject_img.loadFromFile(img_file);
	gobject_img.createMaskFromColor(Color(255, 255, 255));
	gobject_textr.loadFromImage(gobject_img);
	gobject_spr.setTexture(gobject_textr);
}
GameObject::GameObject(string img_f, float x, float y)
{
	img_file = img_f;
	x_pos = x;
	y_pos = y;

	gobject_img.loadFromFile(img_file);
	gobject_img.createMaskFromColor(Color(255, 255, 255));
	gobject_textr.loadFromImage(gobject_img);
	gobject_spr.setTexture(gobject_textr);
	gobject_spr.setPosition(x_pos, y_pos);
}


GameObject::~GameObject()
{
}
