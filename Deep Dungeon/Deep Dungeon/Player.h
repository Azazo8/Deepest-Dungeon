#pragma once
#include"raylib.h"

class Player
{
private:
	//Loading fonts
	Font
		font1 = LoadFont("resources/fonts/font1.ttf"),
	    font3 = LoadFont("resources/fonts/font3.ttf");

	//Loading textures
	Texture
		player = LoadTexture("resources/stage1/graphic/characters/player.png"),
		face = LoadTexture("resources/stage1/graphic/face.png");

	//Describing player texture and position
	float width = 12, height = 12;
	float scale_width = 32, scale_height = 32;
	float calibrate_x = 657, calibrate_y = 280;
	float pos_x = 2 * scale_width + calibrate_x, pos_y = 17 * scale_height + calibrate_y;

	//Describing player statistics
	int speed = 32;
	int level = 1;
	int exp = 0;
	int strength = 6, vitality = 10, dexterity = 4, endurance = 7;
	
	//Player parameters
	int max_hp = vitality * 10;
	int stamina = endurance * 10;
	int damage = strength + GetRandomValue(4, 10);
	int block = dexterity * 3;
	int hp = 100;
	int potion_count = 0;

	//Check_interaction
	bool interact = false;
	bool item_interact = false;

	//Points for leveling
	int points_left = 0;

	Rectangle
		//Player texture and position
		prev_pos,
		rec1 = { 0, 0, width, height },
		rec2 = { pos_x, pos_y, scale_width, scale_height },

		//Player chart image
		face_rec1 = { 0, 0, 172, 174 },
		face_rec2 = { 1500, 400, 150, 150 },

		//leveling
		strength_rec = { 1650, 570, 25, 25 },
		vitality_rec = { 1650, 610, 25, 25 },
		dexterity_rec = { 1650, 650, 25, 25 },
		endurance_rec = { 1650, 690, 25, 25 },

		strength_cross1 = { 1654, 580, 17, 4 },
		strength_cross2 = { 1661, 574, 4, 17 },
		vitality_cross1 = { 1654, 620, 17, 4 },
		vitality_cross2 = { 1661, 614, 4, 17 },
		dexterity_cross1 = { 1654, 660, 17, 4 },
		dexterity_cross2 = { 1661, 654, 4, 17 },
		endurance_cross1 = { 1654, 700, 17, 4 },
		endurance_cross2 = { 1661, 694, 4, 17 };

	Vector2
		//Origin of the player texture
		origin = { scale_width / 2, scale_height / 2 },
		//To be filled with current mouse position
		mouse_pos;

	//Declaring friend classes
	friend class Stage1;
	friend class Stage2;
public:
	//Getters
	int get_hp();

	//Drawing player and player chart image
	void draw();
	void draw_chart();

	//Checking player input
	void check_input();

	//Check level up
	void level_up();
};