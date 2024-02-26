#include "Player.h"

//Getters
int Player::get_hp()
{
	return hp;
}

//Drawing player and player chart image
void Player::draw()
{
	DrawTexturePro(player, rec1, rec2, origin, 0, RAYWHITE);
}
void Player::draw_chart()
{
	DrawRectangleRoundedLines(Rectangle{ 1380, 225, 480, 650 }, 0.1f, 0, 3, BLACK);
	DrawRectangleRoundedLines(Rectangle{ 1425, 500, 270, 300 }, 0.1f, 0, 3, BLACK);
	DrawRectangleRounded(Rectangle{ 1425, 500, 270, 300 }, 0.1, 0, WHITE);
	DrawTexturePro(face, face_rec1, face_rec2, Vector2{ face_rec2.width / 2, face_rec2.height / 2 }, 0, RAYWHITE);
	DrawTextEx(font1, "Character", Vector2{ 1510, 240 }, 60, 5, BLACK);
	DrawTextEx(font1, "Name: Joel", Vector2{ 1630, 360 }, 30, 5, BLACK);
	DrawTextEx(font1, TextFormat("Level: %d", level), Vector2{ 1630, 400 }, 30, 5, BLACK);
	DrawTextEx(font1, TextFormat("Exp: %d", exp), Vector2{ 1630, 440 }, 30, 5, BLACK);
	DrawTextEx(font1, "Stats:", Vector2{ 1440, 510 }, 30, 5, BLACK);
	DrawTextEx(font1, TextFormat("Strength: %d", strength), Vector2{ 1440, 570 }, 30, 5, BLACK);
	DrawTextEx(font1, TextFormat("Vitality: %d", vitality), Vector2{ 1440, 610 }, 30, 5, BLACK);
	DrawTextEx(font1, TextFormat("Dexterity: %d", dexterity), Vector2{ 1440, 650 }, 30, 5, BLACK);
	DrawTextEx(font1, TextFormat("Endurance: %d", endurance), Vector2{ 1440, 690 }, 30, 5, BLACK);
	DrawTextEx(font1, TextFormat("Health: %d", hp), Vector2{ 1440, 760 }, 30, 5, BLACK);
}

//Checking player input
void Player::check_input()
{
	mouse_pos = GetMousePosition();
	prev_pos = rec2;
	if (IsKeyDown(KEY_W))
		rec2.y -= speed;
	if (IsKeyDown(KEY_S))
		rec2.y += speed;
	if (IsKeyDown(KEY_A))
		rec2.x -= speed;
	if (IsKeyDown(KEY_D))
		rec2.x += speed;
	if (IsKeyPressed(KEY_E))
		interact = true;
	if (IsMouseButtonPressed(1))
		item_interact = true;
	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D))
		interact = false;
}

//Check level up
void Player::level_up()
{
	if (exp == 100)
	{
		points_left = 5;
		level++;
		exp = 0;
	}
	if (points_left > 0)
	{
		mouse_pos = GetMousePosition();
		DrawRectangleRec(strength_rec, BLACK);
		DrawRectangleRec(vitality_rec, BLACK);
		DrawRectangleRec(dexterity_rec, BLACK);
		DrawRectangleRec(endurance_rec, BLACK);
		DrawRectangleRec(strength_cross1, WHITE);
		DrawRectangleRec(strength_cross2, WHITE);
		DrawRectangleRec(vitality_cross1, WHITE);
		DrawRectangleRec(vitality_cross2, WHITE);
		DrawRectangleRec(dexterity_cross1, WHITE);
		DrawRectangleRec(dexterity_cross2, WHITE);
		DrawRectangleRec(endurance_cross1, WHITE);
		DrawRectangleRec(endurance_cross2, WHITE);
		if (CheckCollisionPointRec(mouse_pos, Rectangle{ strength_rec.x, strength_rec.y - 20, strength_rec.width, strength_rec.height }) && IsMouseButtonPressed(0) && points_left > 0)
		{
			points_left--;
			strength++;
		}
		if (CheckCollisionPointRec(mouse_pos, Rectangle{ vitality_rec.x, vitality_rec.y - 20, vitality_rec.width, vitality_rec.height }) && IsMouseButtonPressed(0) && points_left > 0)
		{
			points_left--;
			hp += 10;
			vitality++;
			max_hp = vitality * 10;
		}
		if (CheckCollisionPointRec(mouse_pos, Rectangle{ dexterity_rec.x, dexterity_rec.y - 20, dexterity_rec.width, dexterity_rec.height }) && IsMouseButtonPressed(0) && points_left > 0)
		{
			points_left--;
			dexterity++;
		}
		if (CheckCollisionPointRec(mouse_pos, Rectangle{ endurance_rec.x, endurance_rec.y - 20, endurance_rec.width, endurance_rec.height }) && IsMouseButtonPressed(0) && points_left > 0)
		{
			points_left--;
			endurance++;
		}
		DrawTextEx(font3, "LEVEL UP!", Vector2{ 1430, 810 }, 60, 3, RED);
	}
}