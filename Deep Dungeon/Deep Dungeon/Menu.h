#pragma once
#include"raylib.h"

class Menu
{
private:
	//Loading fonts
	Font
		font3 = LoadFont("resources/fonts/font3.ttf");

	//Loading sound button
	Sound
		button_sound = LoadSound("resources/stage1/sound/button.wav");

	//Loading textures to be displayed in information section
	Texture2D
		key_w = LoadTexture("resources/stage1/graphic/keys/w_key.png"),
		key_s = LoadTexture("resources/stage1/graphic/keys/s_key.png"),
		key_a = LoadTexture("resources/stage1/graphic/keys/a_key.png"),
		key_d = LoadTexture("resources/stage1/graphic/keys/d_key.png"),
		key_e = LoadTexture("resources/stage1/graphic/keys/e_key.png"),
		chest = LoadTexture("resources/stage1/graphic/decors/chest.png"),
		bookshelf = LoadTexture("resources/stage1/graphic/decors/bookshelf.png"),
		door_locked = LoadTexture("resources/stage1/graphic/blocks/door_locked.png"),
		apple = LoadTexture("resources/stage1/graphic/pickups/apple.png"),
		potion = LoadTexture("resources/stage1/graphic/pickups/potion.png");

	//Operating menu
	bool options = false;
	bool start_game = false;
	bool exit = false;
	bool play_sound1 = false;
	bool play_sound2 = false;
	bool play_sound3 = false;
	bool play_sound4 = false;

	//Properties of interactive buttons
	float button_width = 600, button_height = 100;
	float button_x = 630;
	float start_button_y = 400;
	float info_button_y = 550;
	float exit_button_y = 700;
	float return_button_y = 900;

	//Creating interactive buttons
	Rectangle
		start_button = { button_x, start_button_y, button_width, button_height },
		info_button = { button_x, info_button_y, button_width, button_height },
		exit_button = { button_x, exit_button_y, button_width, button_height },
		return_button = { button_x - 580, return_button_y, button_width, button_height },

		start_button_lines = { button_x - 5, start_button_y - 5, button_width + 10, button_height + 10 },
		info_button_lines = { button_x - 5, info_button_y - 5, button_width + 10, button_height + 10 },
		exit_button_lines = { button_x - 5, exit_button_y - 5, button_width + 10, button_height + 10 },
		return_button_lines = { button_x - 585, return_button_y - 5, button_width + 10, button_height + 10 };

	//To be filled with current mouse position
	Vector2
		mouse_pos;
public:
	//Getters
	bool get_exit();
	bool get_start_game();

	//Drawing main menu and information section
	void draw();
	void draw_info();

	//Checking collision with interactive buttons
	void check_collision();
};