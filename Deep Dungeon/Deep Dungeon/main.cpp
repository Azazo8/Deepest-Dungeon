#include"Stage1.h"
#include"Stage2.h"
#include"Menu.h"

int main()
{
	//Loading icon image
	Image icon = LoadImage("resources/icon.png");

	//Setting up window and other basics
	InitWindow(1920, 1080, "Deep Dungeon");
	InitAudioDevice();
	SetWindowIcon(icon);
	SetTargetFPS(60);

	//Creating objects
	Menu menu;
	Stage1 stage1;
	Stage2 stage2;
	Player player;
	Enemy skeleton1(1, 3, 4, 5, 7, 5, 13);
	Enemy skeleton2(2, 4, 6, 5, 8, 9, 8);
	Enemy skeleton3(3, 3, 8, 5, 9, 5, 3);
	Enemy skeleton4(4, 4, 7, 5, 9, 17, 4);
	Enemy skeleton5(5, 5, 5, 5, 8, 17, 11);

	//Setting up music sound and starting background music
	stage1.setup_sound();
	stage2.setup_sound();
	//Main game loop
	while (!WindowShouldClose() && !stage1.get_win() && !menu.get_exit() && player.get_hp() > 0)
	{
		//Looping background music
		stage1.loop_background_music();
		//Delaying a game
		WaitTime(0.1);
		//Main menu loop
		while (!menu.get_start_game() && !menu.get_exit())
		{
			stage1.loop_background_music();
			menu.draw();
			menu.check_collision();
			menu.draw_info();
		}
		BeginDrawing();

		//drawing stuff
		ClearBackground(Color{ 40, 90, 105, 255 });
		stage1.draw_eq_items(player);
		player.draw_chart();
		stage1.draw_map();
		if (skeleton1.get_hp() > 0)
		    skeleton1.draw();
		if (skeleton2.get_hp() > 0)
		    skeleton2.draw();
		if (skeleton3.get_hp() > 0)
		    skeleton3.draw();
		if (skeleton4.get_hp() > 0)
		    skeleton4.draw();
		if (skeleton5.get_hp() > 0)
		    skeleton5.draw();
		player.draw();

		//logic
		player.check_input();
		stage1.manage_collisions(player);
		player.level_up();
		stage1.check_fight1(player, skeleton1);
		if (stage1.get_fight1())
		{
			if (player.get_hp() > 0 && skeleton1.get_hp() > 0)
			{
				stage1.set_fight1(false);
				stage1.stop_music();
			}
			while (player.get_hp() > 0 && skeleton1.get_hp() > 0)
			{
				stage2.loop_music();
				stage2.draw(skeleton1, player);
			}
			stage1.loop_background_music();
			stage2.stop_sound();
			stage2.set_bars(490, 490, 490, player);
		}
		stage1.check_fight2(player, skeleton2);
		if (stage1.get_fight2())
		{
			if (player.get_hp() != 0 && skeleton2.get_hp() != 0)
			{
				stage1.set_fight2(false);
				stage1.stop_music();
			}
			while (player.get_hp() != 0 && skeleton2.get_hp() != 0)
			{
				stage2.loop_music();
				stage2.draw(skeleton2, player);
			}
			stage1.loop_background_music();
			stage2.stop_sound();
			stage2.set_bars(490, 490, 490, player);
		}
		stage1.check_fight3(player, skeleton3);
		if (stage1.get_fight3())
		{
			if (player.get_hp() != 0 && skeleton3.get_hp() != 0)
			{
				stage1.set_fight3(false);
				stage1.stop_music();
			}
			while (player.get_hp() != 0 && skeleton3.get_hp() != 0)
			{
				stage2.loop_music();
				stage2.draw(skeleton3, player);
			}
			stage1.loop_background_music();
			stage2.stop_sound();
			stage2.set_bars(490, 490, 490, player);
		}
		stage1.check_fight4(player, skeleton4);
		if (stage1.get_fight4())
		{
			if (player.get_hp() != 0 && skeleton4.get_hp() != 0)
			{
				stage1.set_fight4(false);
				stage1.stop_music();
			}
			while (player.get_hp() != 0 && skeleton4.get_hp() != 0)
			{
				stage2.loop_music();
				stage2.draw(skeleton4, player);
			}
			stage1.loop_background_music();
			stage2.stop_sound();
			stage2.set_bars(490, 490, 490, player);
		}
		stage1.check_fight5(player, skeleton5);
		if (stage1.get_fight5())
		{
			if (player.get_hp() != 0 && skeleton5.get_hp() != 0)
			{
				stage1.set_fight5(false);
				stage1.stop_music();
			}
			while (player.get_hp() != 0 && skeleton5.get_hp() != 0)
			{
				stage2.loop_music();
				stage2.draw(skeleton5, player);
			}
			stage1.loop_background_music();
			stage2.stop_sound();
			stage2.set_bars(490, 490, 490, player);
		}

		//winning or losing conditions
		if (stage1.get_win())
			stage1.ending();
		if (player.get_hp() <= 0)
			stage1.death();

		EndDrawing();
	}
	//Closing game
	CloseAudioDevice();
	CloseWindow();

	return 0;
}