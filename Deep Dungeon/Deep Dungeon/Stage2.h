#pragma once
#include"Player.h"
#include"Enemy.h"

class Stage2
{
private:
	Font
		font1 = LoadFont("resources/fonts/font1.ttf");

	Sound
		//Loading fighting sounds
		attack_heavy_sound = LoadSound("resources/stage2/sound/attack_heavy.wav"),
		attack_light_sound = LoadSound("resources/stage2/sound/attack_light.wav"),
		attack_medium_sound = LoadSound("resources/stage2/sound/attack_medium.wav"),
		player_death_sound = LoadSound("resources/stage2/sound/player_death.wav"),
		protect_sound = LoadSound("resources/stage2/sound/protect.wav"),
		skeleton_death_sound = LoadSound("resources/stage2/sound/skeleton_death.wav"),
		potion_sound = LoadSound("resources/stage2/sound/potion.wav"),
		defend_sound = LoadSound("resources/stage2/sound/defend.wav"),

		//Loading fight music
		fight_background_music = LoadSound("resources/stage2/sound/fight_background_music.wav");

	Texture2D
		//Loading background
		background = LoadTexture("resources/stage2/graphic/background/background.png"),
		floor = LoadTexture("resources/stage2/graphic/background/floor.png"),

		//Loading player for fight
		attack_heavy_player = LoadTexture("resources/stage2/graphic/player/attack_heavy_player.png"),
		attack_light_player = LoadTexture("resources/stage2/graphic/player/attack_light_player.png"),
		attack_medium_player = LoadTexture("resources/stage2/graphic/player/attack_medium_player.png"),
		idle_player = LoadTexture("resources/stage2/graphic/player/idle_player.png"),
		protect_player = LoadTexture("resources/stage2/graphic/player/protect_player.png"),

		//Loading skeleton for fight
		attack_heavy_enemy = LoadTexture("resources/stage2/graphic/skeleton/attack_heavy_skeleton.png"),
		attack_light_enemy = LoadTexture("resources/stage2/graphic/skeleton/attack_light_skeleton.png"),
		attack_medium_enemy = LoadTexture("resources/stage2/graphic/skeleton/attack_medium_skeleton.png"),
		idle_enemy = LoadTexture("resources/stage2/graphic/skeleton/idle_skeleton.png"),
		protect_enemy = LoadTexture("resources/stage2/graphic/skeleton/protect_skeleton.png"),

		//Loading skill icons
		attack_heavy_icon = LoadTexture("resources/stage2/graphic/skill_icons/attack_heavy.png"),
		attack_light_icon = LoadTexture("resources/stage2/graphic/skill_icons/attack_light.png"),
		attack_medium_icon = LoadTexture("resources/stage2/graphic/skill_icons/attack_medium.png"),
		protect_icon = LoadTexture("resources/stage2/graphic/skill_icons/protect.png"),
		potion_icon = LoadTexture("resources/stage1/graphic/pickups/potion.png");

	//Player animation timers
	int timer1_player = 0;
	int timer2_player = 0;
	int timer3_player = 0;
	int timer4_player = 0;
	int timer5_player = 0;
	int timer6_player = 0;

	//Enemy animation timers
	int timer1_enemy = 0;
	int timer2_enemy = 0;
	int timer3_enemy = 0;
	int timer4_enemy = 0;
	int timer5_enemy = 0;
	int timer6_enemy = 0;

	//Delay for player
	int delay1_player = 0;
	int delay2_player = 0;
	int delay3_player = 0;
	int delay4_player = 0;
	int delay5_player = 0;
	int delay6_player = 0;

	//Delay for enemy
	int delay1_enemy = 0;
	int delay2_enemy = 0;
	int delay3_enemy = 0;
	int delay4_enemy = 0;
	int delay5_enemy = 0;
	int delay6_enemy = 0;

	//Checking events
	bool player_light_attack = false;
	bool player_medium_attack = false;
	bool player_heavy_attack = false;
	bool player_protect = false;
	bool enemy_light_attack = false;
	bool enemy_medium_attack = false;
	bool enemy_heavy_attack = false;
	bool enemy_protect = false;
	bool clicked = false;

	//Skeleton action randomizer
	int choice;

	//Checking turns
	bool player_turn = true;
	bool enemy_turn = false;

	//Background image properties
	float fight_background_width = 512, fight_background_height = 352;
	float fight_background_scale_width = 1920, fight_background_scale_height = 1080;
	float floor_width = 512, floor_height = 310;

	//Player image properties
	float player_width = 128, player_height = 128;
	float player_width_scale = 800, player_height_scale = 800;
	float player_x = 200, player_y = floor_height - 335;

	//Enemy image properties
	float enemy_width = 128, enemy_height = 128;
	float enemy_width_scale = 800, enemy_height_scale = 800;
	float enemy_x = 1100, enemy_y = player_y;

	//Icon image properties
	float icon_width = 32, icon_height = 32;
	float potion_width = 12, potion_height = 12;
	float icon_width_scale = 130, icon_height_scale = 130;
	float icon_x = 355, icon_y = 870;

	//Player health, stamina bars properties
	float health_player_x = 55, health_player_y = 55;
	float health_player_width = 490, health_player_height = 40;
	float stamina_player_x = 55, stamina_player_y = 125;
	float stamina_player_width = 490, stamina_player_height = 40;

	//Enemy health, stamina bars properties
	float health_enemy_x = 1385, health_enemy_y = 55;
	float health_enemy_width = 490, health_enemy_height = 40;
	float stamina_enemy_x = 1385, stamina_enemy_y = 125;
	float stamina_enemy_width = 490, stamina_enemy_height = 40;

	Rectangle
		//Background image
		rec1_fight_background = { 0, 0, fight_background_width, fight_background_height },
		rec2_fight_background = { 0, 0, fight_background_scale_width, fight_background_scale_height },
		rec_floor = { 0, 0, floor_width, floor_height },

		//Player image
		rec1_player = { 0, 0, player_width, player_height },
		rec2_player = { player_x, player_y, player_width_scale, player_height_scale },

		//Enemy image
		rec1_enemy = { 0, 0, enemy_width, enemy_height },
		rec2_enemy = { enemy_x, enemy_y, enemy_width_scale, enemy_height_scale },

		//Icon image
		rec1_icon = { 0, 0, icon_width, icon_height },
		rec1_potion = { 0, 0, potion_width, potion_height },
		rec2_icon1 = { icon_x + 270, icon_y, icon_width_scale, icon_height_scale },
		rec2_icon2 = { icon_x + 405, icon_y, icon_width_scale, icon_height_scale },
		rec2_icon3 = { icon_x + 540, icon_y, icon_width_scale, icon_height_scale },
		rec2_icon4 = { icon_x + 675, icon_y, icon_width_scale, icon_height_scale },
		rec2_icon5 = { icon_x + 810, icon_y, icon_width_scale, icon_height_scale },

		//Player health, stamina bars
		rec_player_health = { health_player_x, health_player_y, health_player_width, health_player_height },
	    rec_player_stamina = { stamina_player_x, stamina_player_y, stamina_player_width, stamina_player_height },

		//Enemy health, stamina bars
		rec_enemy_health = { health_enemy_x, health_enemy_y, health_enemy_width, health_enemy_height },
		rec_enemy_stamina = { stamina_enemy_x, stamina_enemy_y, stamina_enemy_width, stamina_enemy_height };

	Vector2
		//origin for rectangles
		origin = { 0, 0 },

		//To be filled with current mouse position
		mouse_pos;

	//Drawing other stuff
	void draw_floor();
	void draw_bars(Player& player, Enemy& enemy);

	//Randomizing damage
	void damage_randomization_player(Player& player);
	void damage_randomization_enemy(Enemy& enemy);

	//Checking actions
	bool check_player_block(Enemy& enemy);
	bool check_enemy_block(Player& player);
	void check_player_action(Player& player, Enemy& enemy);
	void logic_animation_player(Player& player, Enemy& enemy);
	void skeleton_action_choice(Player& player, Enemy& enemy);
	void logic_animation_enemy(Player& player, Enemy& enemy);
public:

	bool finish = false;
	//Setters
	void set_bars(int E_hp, int E_st, int P_st, Player& player);

	//Managing music
	void loop_music();
	void setup_sound();
	void stop_sound();

	//Drawing fight scene
	void draw(Enemy& enemy, Player& player);
};