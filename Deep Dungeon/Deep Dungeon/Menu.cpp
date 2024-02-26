#include "Menu.h"

//Getters
bool Menu::get_exit()
{
	return exit;
}
bool Menu::get_start_game()
{
	return start_game;
}

//Drawing main menu and information section
void Menu::draw()
{
	ClearBackground(Color{ 40, 90, 105, 255 });
	DrawRectangleLinesEx(start_button_lines, 5, BLACK);
	DrawRectangleLinesEx(info_button_lines, 5, BLACK);
	DrawRectangleLinesEx(exit_button_lines, 5, BLACK);
	DrawTextEx(font3, "Deepest Dungeon", Vector2{ 490, 100 }, 100, 4, BLACK);
	DrawTextEx(font3, "Start game", Vector2{ button_x + 170, start_button_y + 30 }, 40, 3, BLACK);
	DrawTextEx(font3, "Information", Vector2{ button_x + 162, info_button_y + 30 }, 40, 3, BLACK);
	DrawTextEx(font3, "Exit game", Vector2{ button_x + 190, exit_button_y + 30 }, 40, 3, BLACK);
	EndDrawing();
}
void Menu::draw_info()
{
	while (options)
	{
		ClearBackground(Color{ 40, 90, 105, 255 });
		check_collision();
		DrawRectangleLinesEx(return_button_lines, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 50, 50, 600, 800 }, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 80, 120, 540, 100 }, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 80, 270, 540, 100 }, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 80, 420, 540, 100 }, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 80, 570, 540, 100 }, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 80, 720, 540, 100 }, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 830, 500, 880, 350 }, 5, BLACK);
		DrawRectangleLinesEx(Rectangle{ 700, 50, 1175, 410 }, 5, BLACK);
		DrawRectangle(55, 55, 590, 790, WHITE);
		DrawRectangle(705, 55, 1165, 400, WHITE);
		DrawRectangle(835, 505, 870, 340, WHITE);
		DrawTextEx(font3, "return", Vector2{ button_x - 370, return_button_y + 30 }, 40, 3, BLACK);
		DrawTextEx(font3, "Keybindings:", Vector2{ 70, 70 }, 40, 3, BLACK);
		DrawTextEx(font3, "Information:", Vector2{ 720, 70 }, 40, 3, BLACK);
		DrawTextEx(font3, "Move up:", Vector2{ 150, 147 }, 40, 3, BLACK);
		DrawTextEx(font3, "Move down:", Vector2{ 150, 300 }, 40, 3, BLACK);
		DrawTextEx(font3, "Move left:", Vector2{ 150, 448 }, 40, 3, BLACK);
		DrawTextEx(font3, "Move right:", Vector2{ 150, 596 }, 40, 3, BLACK);
		DrawTextEx(font3, "Interaction:", Vector2{ 150, 749 }, 40, 3, BLACK);
		DrawTextEx(font3, "Interactible objects:", Vector2{ 720, 190 }, 40, 3, BLACK);
		DrawTextEx(font3, "Heal up in a fight:", Vector2{ 720, 250 }, 40, 3, BLACK);
		DrawTextEx(font3, "Heal up outside of a fight:", Vector2{ 720, 310 }, 40, 3, BLACK);
		DrawTextEx(font3, "Made with: Raylib", Vector2{ 920, 550 }, 60, 3, BLACK);
		DrawTextEx(font3, "Language: C++", Vector2{ 920, 650 }, 60, 3, BLACK);
		DrawTextEx(font3, "Author: Michal Zabost", Vector2{ 920, 750 }, 60, 3, BLACK);
		DrawTexturePro(key_w, Rectangle{ 0, 0, 9, 10 }, Rectangle{ 375, 142, 48, 48 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(key_s, Rectangle{ 0, 0, 9, 10 }, Rectangle{ 425, 292, 48, 48 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(key_a, Rectangle{ 0, 0, 9, 10 }, Rectangle{ 410, 442, 48, 48 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(key_d, Rectangle{ 0, 0, 9, 10 }, Rectangle{ 430, 592, 48, 48 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(key_e, Rectangle{ 0, 0, 9, 10 }, Rectangle{ 465, 742, 48, 48 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(bookshelf, Rectangle{ 0, 0, 12, 12 }, Rectangle{ 1230, 160, 64, 64 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(chest, Rectangle{ 0, 0, 12, 12 }, Rectangle{ 1310, 160, 64, 64 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(door_locked, Rectangle{ 0, 0, 12, 12 }, Rectangle{ 1390, 160, 64, 64 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(potion, Rectangle{ 0, 0, 12, 12 }, Rectangle{ 1120, 240, 64, 64 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		DrawTexturePro(apple, Rectangle{ 0, 0, 12, 12 }, Rectangle{ 1320, 300, 64, 64 }, Vector2{ 0, 0 }, 0, RAYWHITE);
		EndDrawing();
	}
}

//Checking collision with interactive buttons
void Menu::check_collision()
{
	mouse_pos = GetMousePosition();
	if (!options)
	{
		//Checking collision with start button
		if (CheckCollisionPointRec(mouse_pos, start_button))
		{
			if (play_sound1)
				PlaySound(button_sound);
			play_sound1 = false;
			DrawRectangleRec(start_button, DARKGREEN);
			if (IsMouseButtonPressed(0))
				start_game = true;
		}
		else
		{
			DrawRectangleRec(start_button, WHITE);
			play_sound1 = true;
		}

		//Checking collision with info button
		if (CheckCollisionPointRec(mouse_pos, info_button))
		{
			if (play_sound2)
				PlaySound(button_sound);
			play_sound2 = false;
			DrawRectangleRec(info_button, DARKGREEN);
			if (IsMouseButtonPressed(0))
				options = true;
		}
		else
		{
			DrawRectangleRec(info_button, WHITE);
			play_sound2 = true;
		}

		//Checking collision with exit button
		if (CheckCollisionPointRec(mouse_pos, exit_button))
		{
			if (play_sound3)
			    PlaySound(button_sound);
			play_sound3 = false;
			DrawRectangleRec(exit_button, DARKGREEN);
			if (IsMouseButtonPressed(0))
				exit = true;
		}
		else
		{
			DrawRectangleRec(exit_button, WHITE);
			play_sound3 = true;
		}
	}
	else if (options)
	{
		//Checking collision with return button
		if (CheckCollisionPointRec(mouse_pos, return_button))
		{
			if (play_sound4)
				PlaySound(button_sound);
			play_sound4 = false;
			DrawRectangleRec(return_button, DARKGREEN);
			if (IsMouseButtonPressed(0))
				options = false;
		}
		else
		{
			DrawRectangleRec(return_button, WHITE);
			play_sound4 = true;
		}
	}
}