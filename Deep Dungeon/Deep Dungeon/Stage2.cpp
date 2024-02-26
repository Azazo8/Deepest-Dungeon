#include "Stage2.h"

//Setters
void Stage2::set_bars(int E_hp, int E_st, int P_st, Player& player)
{
	rec_enemy_health.width = E_hp;
	rec_enemy_stamina.width = E_st;
	rec_player_stamina.width = P_st;
	player.stamina = player.endurance * 10;
	rec_player_health.width = player.hp * (500 / (player.vitality * 10));
}

//Managing music
void Stage2::loop_music()
{
	if (!IsSoundPlaying(fight_background_music))
		PlaySound(fight_background_music);
}
void Stage2::setup_sound()
{
	SetSoundVolume(fight_background_music, 0.05);
	SetSoundVolume(attack_light_sound, 0.3);
	SetSoundVolume(attack_medium_sound, 0.3);
	SetSoundVolume(attack_heavy_sound, 0.2);
	SetSoundVolume(protect_sound, 0.3);
	SetSoundVolume(potion_sound, 0.3);
	SetSoundVolume(skeleton_death_sound, 0.2);
	SetSoundVolume(player_death_sound, 0.3);
	SetSoundVolume(defend_sound, 0.5);
}
void Stage2::stop_sound()
{
	StopSound(fight_background_music);
}

//Drawing other stuff
void Stage2::draw_floor()
{
	for (int i = 0; i < 4; i++)
	{
		DrawTextureRec(floor, rec_floor, Vector2{ i * floor_width, 1080 - floor_height }, RAYWHITE);
	}
}
void Stage2::draw_bars(Player& player, Enemy& enemy)
{
	DrawRectangle(620, 865, 680, 140, WHITE);
	DrawTexturePro(protect_icon, rec1_icon, rec2_icon1, origin, 0, RAYWHITE);
	DrawTexturePro(attack_light_icon, rec1_icon, rec2_icon2, origin, 0, RAYWHITE);
	DrawTexturePro(attack_medium_icon, rec1_icon, rec2_icon3, origin, 0, RAYWHITE);
	DrawTexturePro(attack_heavy_icon, rec1_icon, rec2_icon4, origin, 0, RAYWHITE);
	DrawTexturePro(potion_icon, rec1_potion, rec2_icon5, origin, 0, RAYWHITE);
	DrawRectangleLinesEx(Rectangle{ 50, 50, 500, 50 }, 5, WHITE);
	DrawRectangleLinesEx(Rectangle{ 1380, 50, 500, 50 }, 5, WHITE);
	DrawRectangleLinesEx(Rectangle{ 50, 120, 500, 50 }, 5, WHITE);
	DrawRectangleLinesEx(Rectangle{ 1380, 120, 500, 50 }, 5, WHITE);
	DrawRectangleRec(rec_player_health, RED);
	DrawRectangleRec(rec_player_stamina, GREEN);
	DrawRectangleRec(rec_enemy_health, RED);
	DrawRectangleRec(rec_enemy_stamina, GREEN);
	DrawTextEx(player.font1, TextFormat("%d", player.hp), Vector2{ rec_player_health.x + 15, rec_player_health.y }, 50, 3, WHITE);
	DrawTextEx(player.font1, TextFormat("%d", player.stamina), Vector2{ rec_player_stamina.x + 15, rec_player_stamina.y }, 50, 3, WHITE);
	DrawTextEx(player.font1, TextFormat("%d", enemy.hp), Vector2{ rec_enemy_health.x + 440, rec_enemy_health.y }, 50, 3, WHITE);
	DrawTextEx(player.font1, TextFormat("%d", enemy.stamina), Vector2{ rec_enemy_stamina.x + 440, rec_enemy_stamina.y }, 50, 3, WHITE);
	DrawTextEx(player.font1, TextFormat("%d", player.potion_count), Vector2{ rec2_icon5.x + 115, rec2_icon5.y + 100 }, 30, 3, WHITE);
}

//Randomizing damage
void Stage2::damage_randomization_player(Player& player)
{
	SetRandomSeed(GetRandomValue(0, 10000));
	if(CheckCollisionPointRec(mouse_pos, rec2_icon2) && IsMouseButtonPressed(0))
	    player.damage = player.strength + GetRandomValue(1, 3);
	if(CheckCollisionPointRec(mouse_pos, rec2_icon3) && IsMouseButtonPressed(0))
	    player.damage = player.strength + GetRandomValue(4, 6);
	if(CheckCollisionPointRec(mouse_pos, rec2_icon4) && IsMouseButtonPressed(0))
	    player.damage = player.strength + GetRandomValue(8, 10);
}
void Stage2::damage_randomization_enemy(Enemy& enemy)
{
	SetRandomSeed(GetRandomValue(0, 10000));
	if (choice == 1)
		enemy.damage = enemy.strength + GetRandomValue(1, 3);
	if (choice == 2)
		enemy.damage = enemy.strength + GetRandomValue(4, 6);
	if (choice == 3)
		enemy.damage = enemy.strength + GetRandomValue(8, 10);
}

//Checking actions
bool Stage2::check_player_block(Enemy& enemy)
{
	int pool = GetRandomValue(0, 100);
	if (pool < enemy.block)
		return true;
	else
		return false;
}
bool Stage2::check_enemy_block(Player& player)
{
	int pool = GetRandomValue(0, 100);
	if (pool < player.block)
		return true;
	else
		return false;
}
void Stage2::check_player_action(Player& player, Enemy& enemy)
{
	if (!clicked)
		mouse_pos = GetMousePosition();
	else
		mouse_pos = { -10, -10 };
	if (player.block > player.dexterity * 3)
		player.block = player.dexterity * 3;
	if (CheckCollisionPointRec(mouse_pos, rec2_icon1))
		DrawTextEx(font1, "defend", Vector2{ rec2_icon1.x + 20, rec2_icon1.y + 140 }, 40, 3, WHITE);
	if (CheckCollisionPointRec(mouse_pos, rec2_icon2))
		DrawTextEx(font1, "light attack", Vector2{ rec2_icon2.x - 0, rec2_icon2.y + 140 }, 40, 3, WHITE);
	if (CheckCollisionPointRec(mouse_pos, rec2_icon3))
		DrawTextEx(font1, "medium attack", Vector2{ rec2_icon3.x - 30, rec2_icon3.y + 140 }, 40, 3, WHITE);
	if (CheckCollisionPointRec(mouse_pos, rec2_icon4))
		DrawTextEx(font1, "heavy attack", Vector2{ rec2_icon4.x - 20, rec2_icon4.y + 140 }, 40, 3, WHITE);
	if (CheckCollisionPointRec(mouse_pos, rec2_icon5))
		DrawTextEx(font1, "heal up", Vector2{ rec2_icon5.x + 20, rec2_icon5.y + 140 }, 40, 3, WHITE);

	if (CheckCollisionPointRec(mouse_pos, rec2_icon1) && IsMouseButtonPressed(0))
	{
		player_protect = true;
		player.block += 10;
		PlaySound(defend_sound);
	}
	else if (CheckCollisionPointRec(mouse_pos, rec2_icon2) && IsMouseButtonPressed(0))
	{
		clicked = true;
		player_light_attack = true;
		if (!check_player_block(enemy))
		{
			PlaySound(attack_light_sound);
			damage_randomization_player(player);
			if (player.damage > enemy.hp)
				player.damage = enemy.hp;
			enemy.hp -= player.damage;
			if (rec_enemy_health.width > 0)
				rec_enemy_health.width -= player.damage * ((health_enemy_width + 10) / (enemy.vitality * 10));
		}
		else
			PlaySound(protect_sound);
		player.stamina -= 10;
		rec_player_stamina.width -= 10 * ((stamina_player_width + 10) / (player.endurance * 10));
		if (player.stamina < 0)
		{
			player.stamina = 0;
			rec_player_stamina.width = 0;
		}
	}
	else if (CheckCollisionPointRec(mouse_pos, rec2_icon3) && IsMouseButtonPressed(0))
	{
		clicked = true;
		player_medium_attack = true;
		enemy.block += 10;
		if (!check_player_block(enemy))
		{
			PlaySound(attack_medium_sound);
			damage_randomization_player(player);
			if (player.damage > enemy.hp)
				player.damage = enemy.hp;
			enemy.hp -= player.damage;
			if (rec_enemy_health.width > 0)
				rec_enemy_health.width -= player.damage * ((health_enemy_width + 10) / (enemy.vitality * 10));
		}
		else
			PlaySound(protect_sound);
		player.stamina -= 20;
		rec_player_stamina.width -= 20 * ((stamina_player_width + 10) / (player.endurance * 10));
		if (player.stamina < 0)
		{
			player.stamina = 0;
			rec_player_stamina.width = 0;
		}
		enemy.block -= 15;
	}
	else if (CheckCollisionPointRec(mouse_pos, rec2_icon4) && IsMouseButtonPressed(0))
	{
		clicked = true;
		player_heavy_attack = true;
		enemy.block += 20;
		if (!check_player_block(enemy))
		{
			PlaySound(attack_heavy_sound);
			damage_randomization_player(player);
			if (player.damage > enemy.hp)
				player.damage = enemy.hp;
			enemy.hp -= player.damage;
			if (rec_enemy_health.width > 0)
				rec_enemy_health.width -= player.damage * ((health_enemy_width + 10) / (enemy.vitality * 10));
		}
		else
			PlaySound(protect_sound);
		player.stamina -= 30;
		rec_player_stamina.width -= 30 * ((stamina_player_width + 10) / (player.endurance * 10));
		if (player.stamina < 0)
		{
			player.stamina = 0;
			rec_player_stamina.width = 0;
		}
		enemy.block -= 20;
	}
	else if (CheckCollisionPointRec(mouse_pos, rec2_icon5) && IsMouseButtonPressed(0))
	{
		clicked = false;
		if (player.potion_count > 0)
		{
			PlaySound(potion_sound);
			if (player.hp > player.max_hp)
				player.hp -= player.hp - player.max_hp;
			else
				player.hp += 20;
			rec_player_health.width = player.hp * (500 / (player.vitality * 10));
			player.potion_count -= 1;
			enemy_turn = true;
			player_turn = false;
		}
	}
}
void Stage2::logic_animation_player(Player& player, Enemy& enemy)
{
	if (enemy.hp == 0)
	{
		player.exp += 50;
		PlaySound(skeleton_death_sound);
	}
	if (player_heavy_attack)
	{
		delay2_player++;
		if (delay2_player % 600 == 0)
		{
			timer2_player++;
			rec1_player.x += (rec1_player.width * timer2_player);
		}
		DrawTexturePro(attack_heavy_player, Rectangle{ rec1_player.width * timer2_player, rec1_player.y, rec1_player.width, rec1_player.height }, rec2_player, origin, 0, RAYWHITE);
		if (delay2_player == 3600)
		{
			timer2_player = 0;
			delay2_player = 0;
			enemy_turn = true;
			player_turn = false;
			player_heavy_attack = false;
		}
	}
	if (player_medium_attack)
	{
		delay3_player++;
		if (delay3_player % 600 == 0)
		{
			timer3_player++;
			rec1_player.x += (rec1_player.width * timer3_player);
		}
		DrawTexturePro(attack_medium_player, Rectangle{ rec1_player.width * timer3_player, rec1_player.y, rec1_player.width, rec1_player.height }, rec2_player, origin, 0, RAYWHITE);
		if (delay3_player == 3000)
		{
			timer3_player = 0;
			delay3_player = 0;
			enemy_turn = true;
			player_turn = false;
			player_medium_attack = false;
		}
	}
	if (player_light_attack)
	{
		delay4_player++;
		if (delay4_player % 600 == 0)
		{
			timer4_player++;
			rec1_player.x += (rec1_player.width * timer4_player);
		}
		DrawTexturePro(attack_light_player, Rectangle{ rec1_player.width * timer4_player, rec1_player.y, rec1_player.width, rec1_player.height }, rec2_player, origin, 0, RAYWHITE);
		if (delay4_player == 3600)
		{
			timer4_player = 0;
			delay4_player = 0;
			enemy_turn = true;
			player_turn = false;
			player_light_attack = false;
		}
	}
	if (player_protect)
	{
		delay5_player++;
		DrawTexturePro(attack_light_player, Rectangle{ rec1_player.width, rec1_player.y, rec1_player.width, rec1_player.height }, rec2_player, origin, 0, RAYWHITE);
		if (delay5_player == 3600)
		{
			delay5_player = 0;
			enemy_turn = true;
			player_turn = false;
			player_protect = false;
		}
	}
}
void Stage2::skeleton_action_choice(Player& player, Enemy& enemy)
{
	if (delay2_enemy == 0 && delay3_enemy == 0 && delay4_enemy == 0 && delay5_enemy == 0)
	{
		choice = GetRandomValue(0, 3);
		if (enemy.block > enemy.dexterity * 3)
			enemy.block = enemy.dexterity * 3;
		switch (choice)
		{
		case 0:
			enemy_protect = true;
			enemy.block += 10;
			PlaySound(defend_sound);
			break;
		case 1:
			enemy_light_attack = true;
			if (!check_enemy_block(player))
			{
				PlaySound(attack_light_sound);
				damage_randomization_enemy(enemy);
				if (enemy.damage > player.hp)
					enemy.damage = player.hp;
				player.hp -= enemy.damage;
				if (rec_player_health.width > 0)
					rec_player_health.width -= enemy.damage * ((health_player_width + 10) / (player.vitality * 10));
			}
			else
				PlaySound(protect_sound);
			enemy.stamina -= 10;
			rec_enemy_stamina.width -= 10 * ((stamina_enemy_width + 10) / (enemy.endurance * 10));
			if (enemy.stamina < 0)
			{
				enemy.stamina = 0;
				rec_enemy_stamina.width = 0;
			}
			break;
		case 2:
			enemy_medium_attack = true;
			player.block += 10;
			if (!check_enemy_block(player))
			{
				PlaySound(attack_medium_sound);
				damage_randomization_enemy(enemy);
				if (enemy.damage > player.hp)
					enemy.damage = player.hp;
				player.hp -= enemy.damage;
				if (rec_player_health.width > 0)
					rec_player_health.width -= enemy.damage * ((health_player_width + 10) / (player.vitality * 10));
			}
			else
				PlaySound(protect_sound);
			enemy.stamina -= 20;
			rec_enemy_stamina.width -= 20 * ((stamina_enemy_width + 10) / (enemy.endurance * 10));
			if (enemy.stamina < 0)
			{
				enemy.stamina = 0;
				rec_enemy_stamina.width = 0;
			}
			player.block -= 10;
			break;
		case 3:
			enemy_heavy_attack = true;
			player.block += 20;
			if (!check_enemy_block(player))
			{
				PlaySound(attack_heavy_sound);
				damage_randomization_enemy(enemy);
				if (enemy.damage > player.hp)
					enemy.damage = player.hp;
				player.hp -= enemy.damage;
				if (rec_player_health.width > 0)
					rec_player_health.width -= enemy.damage * ((health_player_width + 10) / (player.vitality * 10));
			}
			else
				PlaySound(protect_sound);
			enemy.stamina -= 30;
			rec_enemy_stamina.width -= 30 * ((stamina_enemy_width + 10) / (enemy.endurance * 10));
			if (enemy.stamina < 0)
			{
				enemy.stamina = 0;
				rec_enemy_stamina.width = 0;
			}
			player.block -= 20;
			break;
		}
	}
}
void Stage2::logic_animation_enemy(Player& player, Enemy& enemy)
{
	if (player.hp == 0)
		PlaySound(player_death_sound);
	if (enemy_heavy_attack)
	{
		delay2_enemy++;
		if (delay2_enemy % 600 == 0)
		{
			timer2_enemy++;
			rec1_enemy.x += (rec1_enemy.width * timer2_enemy);
		}
		DrawTexturePro(attack_heavy_enemy, Rectangle{ 512 - rec1_enemy.width * timer2_enemy, rec1_enemy.y, rec1_enemy.width, rec1_enemy.height }, rec2_enemy, origin, 0, RAYWHITE);
		if (delay2_enemy == 3000)
		{
			timer2_enemy = 0;
			delay2_enemy = 0;
			player_turn = true;
			enemy_turn = false;
			enemy_heavy_attack = false;
			clicked = false;
		}
	}
	if (enemy_medium_attack)
	{
		delay3_enemy++;
		if (delay3_enemy % 600 == 0)
		{
			timer3_enemy++;
			rec1_enemy.x += (rec1_enemy.width * timer3_enemy);
		}
		DrawTexturePro(attack_medium_enemy, Rectangle{ 640 - rec1_enemy.width * timer3_enemy, rec1_enemy.y, rec1_enemy.width, rec1_enemy.height }, rec2_enemy, origin, 0, RAYWHITE);
		if (delay3_enemy == 3600)
		{
			timer3_enemy = 0;
			delay3_enemy = 0;
			player_turn = true;
			enemy_turn = false;
			enemy_medium_attack = false;
			clicked = false;
		}
	}
	if (enemy_light_attack)
	{
		delay4_enemy++;
		if (delay4_enemy % 600 == 0)
		{
			timer4_enemy++;
			rec1_enemy.x += (rec1_enemy.width * timer4_enemy);
		}
		DrawTexturePro(attack_light_enemy, Rectangle{ 768 - rec1_enemy.width * timer4_enemy, rec1_enemy.y, rec1_enemy.width, rec1_enemy.height }, rec2_enemy, origin, 0, RAYWHITE);
		if (delay4_enemy == 4200)
		{
			timer4_enemy = 0;
			delay4_enemy = 0;
			player_turn = true;
			enemy_turn = false;
			enemy_light_attack = false;
			clicked = false;
		}
	}
	if (enemy_protect)
	{
		delay5_enemy++;
		DrawTexturePro(protect_enemy, Rectangle{ rec1_enemy.width, rec1_enemy.y, rec1_enemy.width, rec1_enemy.height }, rec2_enemy, origin, 0, RAYWHITE);
		if (delay5_enemy == 6000)
		{
			delay5_enemy = 0;
			player_turn = true;
			enemy_turn = false;
			enemy_protect = false;
			clicked = false;
		}
	}
}

//Drawing fight scene
void Stage2::draw(Enemy& enemy, Player& player)
{
	ClearBackground(RAYWHITE);
	DrawTexturePro(background, rec1_fight_background, rec2_fight_background, origin, 0, RAYWHITE);
	draw_floor();
	draw_bars(player, enemy);

	if (!enemy_heavy_attack && !enemy_medium_attack && !enemy_light_attack && !enemy_protect && enemy.hp > 0)
	{
		delay1_enemy++;
		if (delay1_enemy % 1200 == 0)
		{
			timer1_enemy++;
			rec1_enemy.x += (rec1_enemy.width * timer1_enemy);
		}
		DrawTexturePro(idle_enemy, Rectangle{ rec1_enemy.width * timer1_enemy, rec1_enemy.y, rec1_enemy.width, rec1_enemy.height }, rec2_enemy, origin, 0, RAYWHITE);
		if (delay1_enemy == 6000)
		{
			timer1_enemy = 0;
			delay1_enemy = 0;
		}
	}
	if (!player_heavy_attack && !player_medium_attack && !player_light_attack && !player_protect && player.hp > 0)
	{
		delay1_player++;
		if (delay1_player % 1200 == 0)
			timer1_player++;
		DrawTexturePro(idle_player, Rectangle{ 896 - rec1_player.width * timer1_player, rec1_player.y, rec1_player.width, rec1_player.height }, rec2_player, origin, 0, RAYWHITE);
		if (delay1_player == 6000)
		{
			timer1_player = 0;
			delay1_player = 0;
		}
	}
	if (player_turn)
	{
		check_player_action(player, enemy);
		logic_animation_player(player, enemy);
	}
	if (enemy_turn)
	{
		skeleton_action_choice(player, enemy);
		logic_animation_enemy(player, enemy);
	}
	if (player.stamina == 0)
	{
		player.stamina += 50;
		rec_player_stamina.width = player.stamina * (500 / (player.endurance * 10));
		if (player.hp < 10)
		{
			player.hp = 0;
			rec_player_health.width = 0;
			PlaySound(player_death_sound);
		}
		else
		{
			player.hp -= 10;
			rec_player_health.width = player.hp * (500 / (player.vitality * 10));
		}
	}
	if (enemy.stamina == 0)
	{
		enemy.stamina += 50;
		rec_enemy_stamina.width = enemy.stamina * (500 / (enemy.endurance * 10));
		if (enemy.hp < 10)
		{
			enemy.hp = 0;
			rec_enemy_health.width = 0;
			player.exp += 50;
			PlaySound(skeleton_death_sound);
		}
		else
		{
			enemy.hp -= 10;
			rec_enemy_health.width = enemy.hp * (500 / (enemy.vitality * 10));
		}
	}
	EndDrawing();
}