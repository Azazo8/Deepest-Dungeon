#pragma once
#include"raylib.h"

class Enemy
{
private:
	//Loading enemy textures
	Texture2D
		skeleton = LoadTexture("resources/stage1/graphic/characters/skeleton.png");

	//Timers for predefined paths
	int timer1 = 0;
	int timer2 = 0;
	int timer3 = 0;
	int timer4 = 0;
	int timer5 = 0;

	//Enemies statistics and starting position to be defined in a constructor
	int speed = 32;
	int id;
	int strength, vitality, dexterity, endurance;
	int hp;
	int stamina;
	int damage;
	int block;
	float pos_x, pos_y;

	//Describing enemy texture and position
	float width = 12, height = 12;
	float scale_width = 32, scale_height = 32;
	float calibrate_x = 657, calibrate_y = 280;

	//Enemy texture and position (rec2 to be filled in constructor)
	Rectangle
		rec1 = {0, 0, width, width},
		rec2;

	//Origin of the enemy texture
	Vector2
		origin = { scale_width / 2, scale_height / 2 };

	//Moving Enemies with predefined paths
	void move();

	//Declaring friend classes
	friend class Stage1;
	friend class Stage2;
public:
	//Constructor for an enemy
	Enemy(int Id, int Strength, int Vitality, int Dexterity, int Endurance, float A, float B);

	//Getters
	int get_hp();

	//Drawing enemy
	void draw();
};