#pragma once
#include"Player.h"
#include"Enemy.h"

class Stage1
{
private:
	//Loading fonts
	Font
		font1 = LoadFont("resources/fonts/font1.ttf"),
		font2 = LoadFont("resources/fonts/font2.ttf");

	Sound
		//Loading Sounds for interaction
		chest_sound = LoadSound("resources/stage1/sound/chest.wav"),
		door_through_sound = LoadSound("resources/stage1/sound/door_through.wav"),
		coin_sound = LoadSound("resources/stage1/sound/coin.wav"),
		web_sound = LoadSound("resources/stage1/sound/web.wav"),
		blood_sound = LoadSound("resources/stage1/sound/blood.wav"),
		bone_sound = LoadSound("resources/stage1/sound/bone.wav"),
		book_sound = LoadSound("resources/stage1/sound/book.wav"),
		pickup_sound = LoadSound("resources/stage1/sound/pickup.wav"),
		door_unlock_sound = LoadSound("resources/stage1/sound/door_unlock.wav"),
		door_locked_sound = LoadSound("resources/stage1/sound/door_locked.wav"),

		//Loading music
		background_music = LoadSound("resources/stage1/sound/background.wav"),
		ending_music = LoadSound("resources/stage1/sound/ending.wav"),
		death_music = LoadSound("resources/stage1/sound/death.wav");

	Texture2D
		//Loading building blocks
		floor1 = LoadTexture("resources/stage1/graphic/blocks/floor1.png"),
		floor2 = LoadTexture("resources/stage1/graphic/blocks/floor2.png"),
		floor3 = LoadTexture("resources/stage1/graphic/blocks/floor3.png"),
		floor4 = LoadTexture("resources/stage1/graphic/blocks/floor4.png"),
		wall1 = LoadTexture("resources/stage1/graphic/blocks/wall1.png"),
		wall2 = LoadTexture("resources/stage1/graphic/blocks/wall2.png"),
		wall_bars = LoadTexture("resources/stage1/graphic/blocks/wall_bars.png"),
		wall_window = LoadTexture("resources/stage1/graphic/blocks/wall_window.png"),
		prison_wall = LoadTexture("resources/stage1/graphic/blocks/prison_wall.png"),
		door = LoadTexture("resources/stage1/graphic/blocks/door.png"),
		door_locked = LoadTexture("resources/stage1/graphic/blocks/door_locked.png"),
		passage = LoadTexture("resources/stage1/graphic/blocks/passage.png"),
		upstairs = LoadTexture("resources/stage1/graphic/blocks/upstairs.png"),

		//Loading decors and interactive blocks
		blood1 = LoadTexture("resources/stage1/graphic/decors/blood1.png"),
		blood2 = LoadTexture("resources/stage1/graphic/decors/blood2.png"),
		skulls_pile = LoadTexture("resources/stage1/graphic/decors/skulls_pile.png"),
		skull_bones = LoadTexture("resources/stage1/graphic/decors/skull_bones.png"),
		bones = LoadTexture("resources/stage1/graphic/decors/bones.png"),
		chest = LoadTexture("resources/stage1/graphic/decors/chest.png"),
		bed = LoadTexture("resources/stage1/graphic/decors/bed.png"),
		shelf = LoadTexture("resources/stage1/graphic/decors/shelf.png"),
		barrel = LoadTexture("resources/stage1/graphic/decors/barrel.png"),
		bookshelf = LoadTexture("resources/stage1/graphic/decors/bookshelf.png"),
		closet = LoadTexture("resources/stage1/graphic/decors/closet.png"),
		spider_web = LoadTexture("resources/stage1/graphic/decors/spider_web.png"),

		//Loading pickups
		key = LoadTexture("resources/stage1/graphic/pickups/key.png"),
		apple = LoadTexture("resources/stage1/graphic/pickups/apple.png"),
		potion = LoadTexture("resources/stage1/graphic/pickups/potion.png"),
		gold_bar = LoadTexture("resources/stage1/graphic/pickups/gold_bar.png"),
		coins = LoadTexture("resources/stage1/graphic/pickups/coins.png"),

		//Loading book texture
		book = LoadTexture("resources/stage1/graphic/book.png");

	//Variables related with winning or losing conditions
	bool quit = false;
	bool win = false;

	//To play sound or not to play
	bool play = false;
	bool play_item = false;

	//Checking if fight shoul occur
	bool fight1 = false;
	bool fight2 = false;
	bool fight3 = false;
	bool fight4 = false;
	bool fight5 = false;

	//Equipment chart properties
	float width1_eq = 480, height1_eq = 400;
	float width2_eq = 420, height2_eq = 300;
	float x1_eq = 65, y1_eq = 155;
	float x2_eq = 95, y2_eq = 230;

	//Items chart properties
	float width1_items = 480, height1_items = 400;
	float width2_items = 420, height2_items = 300;
	float x1_items = 65, y1_items = 625;
	float x2_items = 95, y2_items = 700;

	//Map building textures properties
	float width = 12, height = 12;
	float scale_width = 32, scale_height = 32;
	float calibrate_x = 657, calibrate_y = 280;

	//Books defining variables
	float book_width = 328, book_height = 220;
	float book_scale_width = 1200, book_scale_height = 1000;
	float book_x = 920, book_y = 530;
	float title_x = 590, title_y = 100;
	float text_x = 480, text_y = 170;
	float book_move_x = 460, book_move_y = 40;

	//Items in chests properties
	float item_x = 140, item_y = 745;
	float item1_x = 140, item1_y = 270;
	float item_scale_width = 96, item_scale_height = 96;

	//How many items of a sort I have in equipment
	int gold_count = 0;
	int item1_count = 0;
	int item2_count = 0;
	int item3_count = 0;

	//How many items of a sort is there in a chest
	int item1_1_count_ch = 1;
	int item2_1_count_ch = 4;
	int item1_2_count_ch = 1;
	int item1_3_count_ch = 1;
	int item2_3_count_ch = 2;
	int item3_3_count_ch = 2;
	int item1_4_count_ch = 1;
	int item2_4_count_ch = 1;
	int item3_4_count_ch = 2;

	//Are there any items of a sort left in chest or in equipment
	bool item1_1_appear = true;
	bool item2_1_appear = true;
	bool item1_2_appear = true;
	bool item1_3_appear = true;
	bool item2_3_appear = true;
	bool item3_3_appear = true;
	bool item4_3_appear = true;
	bool item1_4_appear = true;
	bool item2_4_appear = true;
	bool item3_4_appear = true;

	//Are given doors locked or open
	bool door1_locked = true;
	bool door2_locked = true;
	bool door3_locked = true;
	bool door4_locked = true;


	Rectangle
		//Map textures
		rec1 = { 0, 0, width, height },
		rec2 = { 0, 0, scale_width, scale_height },

		//Books
		book1 = { 0, 0, book_width, book_height },
		book2 = { book_x, book_y, book_scale_width, book_scale_height },

		//Items in chests
		item1 = { item_x, item_y, item_scale_width, item_scale_height },
		item2 = { item_x + 115, item_y, item_scale_width, item_scale_height },
		item3 = { item_x + 230, item_y, item_scale_width, item_scale_height },
		item4 = { item_x, item_y + 115, item_scale_width, item_scale_height },

		//Replacement for items in chests if empty
		item1_blank = { item_x + 5 , item_y + 5, item_scale_width - 10, item_scale_height - 10 },
		item2_blank = { item_x + 120, item_y + 5, item_scale_width - 10, item_scale_height - 10 },
		item3_blank = { item_x + 235, item_y + 5, item_scale_width - 10, item_scale_height - 10 },
		item4_blank = { item_x + 5, item_y + 120, item_scale_width - 10, item_scale_height - 10 },

		//Placeholders for items in chests
		ch_item1 = { item1_x, item1_y, item_scale_width, item_scale_height },
		ch_item2 = { item1_x + 115, item1_y, item_scale_width, item_scale_height },
		ch_item3 = { item1_x + 230, item1_y, item_scale_width, item_scale_height },
		ch_item4 = { item1_x, item1_y + 115, item_scale_width, item_scale_height },
		ch_item5 = { item1_x + 115, item1_y + 115, item_scale_width, item_scale_height },
		ch_item6 = { item1_x + 230, item1_y + 115, item_scale_width, item_scale_height },

		//Placeholders for items in inventory
		eq_item1 = { item1_x + 5, item1_y + 5, item_scale_width - 10, item_scale_height - 10 },
		eq_item2 = { item1_x + 120, item1_y + 5, item_scale_width - 10, item_scale_height - 10 },
		eq_item3 = { item1_x + 235, item1_y + 5, item_scale_width - 10, item_scale_height - 10 };

	Vector2
		//Positions for collision with interactibles
		chest1_1_pos = { 849, 824 },
		chest1_2_pos = { 817, 856 },
		chest2_1_pos = { 817, 536 },
		chest2_2_pos = { 785, 568 },
		chest3_1_pos = { 721, 344 },
		chest3_2_pos = { 689, 312 },
		chest4_1_pos = { 1201, 344 },
		chest4_2_pos = { 1233, 312 },
		bookshelf1_1_pos = { 817, 664 },
		bookshelf2_2_pos = { 785, 472 },
		bookshelf2_1_pos = { 817, 504 },
		bookshelf3_2_pos = { 817, 408 },
		bookshelf3_1_pos = { 849, 376 },
		door1_pos = { 849, 696 },
		door2_pos = { 785, 376 },
		door3_pos = { 1201, 408 },
		door4_pos = { 1201, 728 },

		//Origins
		origin = { scale_width / 2, scale_height / 2 },
		origin_item = { 0, 0 },
		book_origin = { book_scale_width / 2, book_scale_height / 2 },

		//Positions for book texts
		text_title_pos = { title_x, title_y },
		text_pos = { text_x, text_y },

		//Positions for item and equpiment charts
		eq_pos = { 180, 165 },
		items_pos = { 235, 640 },
		gold_pos = { 130, 495 };

	//Tile map
	char map[20][20]
	{
		{'0', '0', '1', '0', '1', '9', '1', '1', '0', '0', '1', '1', '9', '0', '0', '0', '0', '1', '1', '0'},
		{'1', '6', 'l', '8', 'i', 'm', 'm', '1', 'm', '5', '0', 'h', 'h', 'h', '1', 'g', 'm', 'm', '2', '1'},
		{'1', '5', '2', '8', '2', 'm', 'm', '0', '6', '7', '0', 'h', 'h', 'h', '0', '2', 'd', '7', 'l', '0'},
		{'0', 'b', '2', 'k', '2', '7', '6', '3', '5', '2', '3', '2', '6', '5', '1', '8', '8', 'k', '8', '1'},
		{'0', 'g', 'd', '8', 'o', '2', 'n', '1', '2', '7', '1', '7', '2', 'm', '0', 'c', '2', '2', 'o', '1'},
		{'1', '0', '0', '1', '1', '0', '0', '0', '5', '2', '1', '0', 'm', 'm', '0', '2', '2', '5', '6', '0'},
		{'0', 'o', '2', '6', '7', 'n', '1', 'h', '6', '5', 'h', '0', '1', '1', '1', '1', '1', '3', '0', '1'},
		{'0', 'm', '7', '5', '2', '7', '1', 'h', '5', '2', 'h', '0', 'u', '5', '2', '2', '6', '2', 'i', '0'},
		{'9', 'm', 'i', '7', '5', '2', 'j', '7', '2', '2', '7', 'j', '7', '2', '2', '5', '7', 'm', 'm', '0'},
		{'1', '2', '5', '6', '2', 'l', '0', '6', '5', '2', '5', '1', '2', '2', '7', '2', '2', 'b', 'm', '0'},
		{'1', '1', 'a', '0', '0', '0', '0', 'm', '2', '5', 'i', '0', '0', '0', '1', '0', '2', '2', '6', '9'},
		{'0', 'h', '7', 'u', 'o', 'n', '1', '0', '6', '2', '0', '0', 'n', 'o', 'b', 'a', '7', '2', '2', '0'},
		{'0', 'h', '2', '2', '2', '6', '2', '0', '2', '7', '0', 'f', '5', '5', 'g', 'a', '2', '5', 'h', '0'},
		{'1', 'm', 'i', '2', '7', '2', '5', 'k', '5', '6', '0', '8', '9', '8', '8', '0', '7', '2', 'h', '0'},
		{'0', 'm', '2', '6', '5', '7', '2', '0', '7', '2', '5', '6', '7', 'm', 'm', '0', '6', '5', 'h', '0'},
		{'0', '0', '3', '1', '1', '3', '0', '1', '2', '6', '7', '5', '2', 'm', 'm', '0', '0', 'k', '0', '1'},
		{'0', '2', '7', '2', '1', '2', '5', '1', '7', '2', '0', '8', '9', '8', '8', '0', '2', '6', '2', '1'},
		{'0', '6', '2', '7', 'a', '5', '7', '0', '2', '7', '0', 'e', '2', '7', 'g', '1', '2', '4', '7', '1'},
		{'1', 'u', 'b', '2', '0', '2', 'l', '0', 'h', 'h', '1', 'n', 'c', '6', 'o', '1', 'm', 'm', 'm', '0'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '1', '0', '0', '1', '0', '0', '1', '1'}
	};

	//Checking collisions private
	void check_win_collision(Player& player, int i, int j);
	void check_stop_collision(Player& player, int i, int j);
	void check_no_collision(Player& player, int i, int j);
	void check_sound_collision(Player& player, int i, int j);
	void check_coin_collision(Player& player, int i, int j);
	void check_item1(Player& player);
	void check_item2(Player& player);
	void check_item3(Player& player);
	void check_item4(Player& player);
	void check_bookshelf_collision(Player& player);
	void check_door_collision(Player& player, int i, int j);
	void check_chest_collision(Player& player);

	//Assigning textures to map values
	void manage_tiles(int i, int j);
public:
	//Getters
	bool get_win();
	bool get_fight1();
	bool get_fight2();
	bool get_fight3();
	bool get_fight4();
	bool get_fight5();

	//Setters
	void set_fight1(bool Fight1);
	void set_fight2(bool Fight2);
	void set_fight3(bool Fight3);
	void set_fight4(bool Fight4);
	void set_fight5(bool Fight5);

	//Managing music and sounds
	void setup_sound();
	void loop_background_music();
	void stop_music();

	//Checking collisions public
	void manage_collisions(Player& player);
	void check_fight1(Player& player, Enemy& enemy);
	void check_fight2(Player& player, Enemy& enemy);
	void check_fight3(Player& player, Enemy& enemy);
	void check_fight4(Player& player, Enemy& enemy);
	void check_fight5(Player& player, Enemy& enemy);

	//Drawing map, equipment and items chart
	void draw_map();
	void draw_eq_items(Player& player);

	//Bad ending and good ending
	void ending();
	void death();
};