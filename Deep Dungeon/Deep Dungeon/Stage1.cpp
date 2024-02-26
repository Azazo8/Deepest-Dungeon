#include "Stage1.h"

//Getters
bool Stage1::get_win()
{
	return win;
}
bool Stage1::get_fight1()
{
	return fight1;
}
bool Stage1::get_fight2()
{
	return fight2;
}
bool Stage1::get_fight3()
{
	return fight3;
}
bool Stage1::get_fight4()
{
	return fight4;
}
bool Stage1::get_fight5()
{
	return fight5;
}

//Setters
void Stage1::set_fight1(bool Fight1)
{
	fight1 = Fight1;
}
void Stage1::set_fight2(bool Fight2)
{
	fight2 = Fight2;
}
void Stage1::set_fight3(bool Fight3)
{
	fight3 = Fight3;
}
void Stage1::set_fight4(bool Fight4)
{
	fight4 = Fight4;
}
void Stage1::set_fight5(bool Fight5)
{
	fight5 = Fight5;
}

//Managing music and sounds
void Stage1::setup_sound()
{
	SetSoundVolume(background_music, 0.02);
	SetSoundVolume(web_sound, 0.3);
	SetSoundVolume(door_through_sound, 0.3);
	SetSoundVolume(blood_sound, 0.8);
	SetSoundVolume(bone_sound, 0.3);
	SetSoundVolume(coin_sound, 0.5);
	SetSoundVolume(pickup_sound, 0.6);
	SetSoundVolume(door_locked_sound, 0.1);
	SetSoundVolume(door_unlock_sound, 0.3);
	SetSoundVolume(ending_music, 0.05);
	SetSoundVolume(death_music, 0.05);
}
void Stage1::loop_background_music()
{
	if (!IsSoundPlaying(background_music))
		PlaySound(background_music);
}
void Stage1::stop_music() 
{
	StopSound(background_music);
}

//Checking collisions private
void Stage1::check_win_collision(Player& player, int i, int j)
{
	Rectangle win_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(win_collide, player.rec2))
		win = true;
}
void Stage1::check_stop_collision(Player& player, int i, int j)
{
	Rectangle stop_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(player.rec2, stop_collide))
		player.rec2 = player.prev_pos;
}
void Stage1::check_no_collision(Player& player,int i, int j)
{
	Rectangle no_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(no_collide, player.rec2) && !player.interact)
	{
		play = true;
		play_item = true;
	}
}
void Stage1::check_sound_collision(Player& player, int i, int j)
{
	Rectangle bone_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(bone_collide, player.rec2) && play && (map[i][j] == 'd' || map[i][j] == 'e' || map[i][j] == 'f'))
	{
		PlaySound(bone_sound);
		play = false;
	}
	Rectangle blood_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(blood_collide, player.rec2) && play && (map[i][j] == 'b' || map[i][j] == 'c'))
	{
		PlaySound(blood_sound);
		play = false;
	}
	Rectangle door_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(door_collide, player.rec2) && play && map[i][j] == '3')
	{
		PlaySound(door_through_sound);
		play = false;
	}
	Rectangle web_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(web_collide, player.rec2) && play && map[i][j] == 'i')
	{
		PlaySound(web_sound);
		play = false;
	}
}
void Stage1::check_coin_collision(Player& player, int i, int j)
{
	Rectangle coin_collide = { j * scale_width + calibrate_x, i * scale_height + calibrate_y, scale_width, scale_height };
	if (CheckCollisionRecs(coin_collide, player.rec2))
	{
		map[i][j] = '2';
		gold_count += 200;
		PlaySound(coin_sound);
	}
}
void Stage1::check_item1(Player& player) 
{
	play_item = true;
	if (CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact && item1_1_count_ch > 0)
	{
		item1_1_count_ch--;
		item1_count++;
		if (item1_1_count_ch == 0)
		    item1_1_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item1_blank, BLACK);
	}
	if (CheckCollisionPointRec(player.mouse_pos, item2) && player.item_interact && item2_1_count_ch > 0)
	{
		item2_1_count_ch--;
		item2_count++;
		if (item2_1_count_ch == 0)
		    item2_1_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item2_blank, BLACK);
	}
	if (!CheckCollisionPointRec(player.mouse_pos, item2) && player.item_interact || !CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact)
		player.item_interact = false;
}
void Stage1::check_item2(Player& player)
{
	play_item = true;
	if (CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact && item1_2_appear)
	{
		item1_2_count_ch--;
		item1_count++;
		if (item1_2_count_ch == 0)
		    item1_2_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item1_blank, BLACK);
	}
	if (!CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact)
		player.item_interact = false;
}
void Stage1::check_item3(Player& player)
{
	play_item = true;
	if (CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact && item1_3_appear)
	{
		item1_3_count_ch--;
		item1_count++;
		if (item1_3_count_ch == 0)
		    item1_3_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item1_blank, BLACK);
	}
	if (CheckCollisionPointRec(player.mouse_pos, item2) && player.item_interact && item2_3_appear)
	{
		item2_3_count_ch--;
		item2_count++;
		if (item2_3_count_ch == 0)
		    item2_3_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item2_blank, BLACK);
	}
	if (CheckCollisionPointRec(player.mouse_pos, item3) && player.item_interact && item3_3_appear)
	{
		item3_3_count_ch--;
		item3_count++;
		if (item3_3_count_ch == 0)
		    item3_3_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item3_blank, BLACK);
	}
	if (CheckCollisionPointRec(player.mouse_pos, item4) && player.item_interact && item4_3_appear)
	{
		item4_3_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item4_blank, BLACK);
		gold_count += 1000;
		PlaySound(coin_sound);
	}
	if (!CheckCollisionPointRec(player.mouse_pos, item2) && player.item_interact || !CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact ||
		!CheckCollisionPointRec(player.mouse_pos, item3) && player.item_interact || !CheckCollisionPointRec(player.mouse_pos, item4) && player.item_interact)
		player.item_interact = false;
}
void Stage1::check_item4(Player& player)
{
	play_item = true;
	if (CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact && item1_4_appear)
	{
		item1_4_count_ch--;
		item1_count++;
		if (item1_4_count_ch == 0)
		    item1_4_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item1_blank, BLACK);
	}
	if (CheckCollisionPointRec(player.mouse_pos, item2) && player.item_interact && item2_4_appear)
	{
		item2_4_count_ch--;
		item2_count++;
		if (item2_4_count_ch == 0)
		    item2_4_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item2_blank, BLACK);
	}
	if (CheckCollisionPointRec(player.mouse_pos, item3) && player.item_interact && item3_4_appear)
	{
		item3_4_count_ch--;
		item3_count++;
		if (item3_4_count_ch == 0)
		    item3_4_appear = false;
		if (play_item)
		{
			play_item = false;
			PlaySound(pickup_sound);
		}
		DrawRectangleRec(item3_blank, BLACK);
	}
	if (!CheckCollisionPointRec(player.mouse_pos, item2) && player.item_interact || !CheckCollisionPointRec(player.mouse_pos, item1) && player.item_interact ||
		!CheckCollisionPointRec(player.mouse_pos, item3) && player.item_interact)
		player.item_interact = false;
}
void Stage1::check_bookshelf_collision(Player& player)
{
	if (CheckCollisionPointRec(bookshelf1_1_pos, player.rec2) && player.interact)
	{
		if (play)
		{
			play = false;
			SetSoundVolume(book_sound, 0.2);
			PlaySound(book_sound);
		}
		DrawTexturePro(book, book1, book2, book_origin, 0, RAYWHITE);
		DrawTextEx(font2, "My memories", text_title_pos, 50, 3, BLACK);
		DrawTextEx(font2, "In this grim dungeon, each day seemed to stretch", text_pos, 30, 3, BLACK);
		DrawTextEx(font2, "into eternity. Day by day, amidst despair and", Vector2{ text_pos.x, text_pos.y + book_move_y }, 30, 3, BLACK);
		DrawTextEx(font2, "flickers of hope, I began to cherish the smallest", Vector2{ text_pos.x, text_pos.y + book_move_y * 2 }, 30, 3, BLACK);
		DrawTextEx(font2, "details. The flickering light of a candle became", Vector2{ text_pos.x, text_pos.y + book_move_y * 3 }, 30, 3, BLACK);
		DrawTextEx(font2, "my sole anchor in the darkness swaying with each", Vector2{ text_pos.x, text_pos.y + book_move_y * 4 }, 30, 3, BLACK);
		DrawTextEx(font2, "breath of wind. Memories from before my", Vector2{ text_pos.x, text_pos.y + book_move_y * 5 }, 30, 3, BLACK);
		DrawTextEx(font2, "of family, love, and dreams for the future", Vector2{ text_pos.x, text_pos.y + book_move_y * 6 }, 30, 3, BLACK);
		DrawTextEx(font2, "gradually blurred into vague visions, lost in", Vector2{ text_pos.x, text_pos.y + book_move_y * 7 }, 30, 3, BLACK);
		DrawTextEx(font2, "the labyrinth of fear and despair. Yet, with", Vector2{ text_pos.x, text_pos.y + book_move_y * 8 }, 30, 3, BLACK);
		DrawTextEx(font2, "desperate determination, I began to inscribe them", Vector2{ text_pos.x, text_pos.y + book_move_y * 9 }, 30, 3, BLACK);
		DrawTextEx(font2, "onto the pages of an old book, as if it could help", Vector2{ text_pos.x, text_pos.y + book_move_y * 10 }, 30, 3, BLACK);
		DrawTextEx(font2, " me hold onto what little remained of them.", Vector2{ text_pos.x, text_pos.y + book_move_y * 11 }, 30, 3, BLACK);
		DrawTextEx(font2, "Everything that was once clear now drowned in", Vector2{ text_pos.x, text_pos.y + book_move_y * 12 }, 30, 3, BLACK);
		DrawTextEx(font2, "darkness, submerged in the labyrinth of suffering.", Vector2{ text_pos.x, text_pos.y + book_move_y * 13 }, 30, 3, BLACK);
		DrawTextEx(font2, "Will I ever find a way out of this hell? Will", Vector2{ text_pos.x, text_pos.y + book_move_y * 14 }, 30, 3, BLACK);
		DrawTextEx(font2, "this book serve as a testament to my survival, or", Vector2{ text_pos.x, text_pos.y + book_move_y * 15 }, 30, 3, BLACK);
		DrawTextEx(font2, "merely a reminder of lost dreams?", Vector2{ text_pos.x, text_pos.y + book_move_y * 16 }, 30, 3, BLACK);
		DrawTextEx(font2, "Though the answers to these questions remain out", Vector2{ text_pos.x + book_move_x, text_pos.y }, 30, 3, BLACK);
		DrawTextEx(font2, "of reach, I've resolved to continue recording my", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y }, 30, 3, BLACK);
		DrawTextEx(font2, "memories, step by step, page by page. Perhaps", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 2 }, 30, 3, BLACK);
		DrawTextEx(font2, "someday, in the meantime, I'll find the key to", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 3 }, 30, 3, BLACK);
		DrawTextEx(font2, "escape this dark dungeon and reclaim what", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 4 }, 30, 3, BLACK);
		DrawTextEx(font2, "I've lost.", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 5 }, 30, 3, BLACK);
	}
	if ((CheckCollisionPointRec(bookshelf2_1_pos, player.rec2) || CheckCollisionPointRec(bookshelf2_2_pos, player.rec2)) && player.interact)
	{
		if (play)
		{
			play = false;
			SetSoundVolume(book_sound, 0.2);
			PlaySound(book_sound);
		}
		DrawTexturePro(book, book1, book2, book_origin, 0, RAYWHITE);
		DrawTextEx(font2, "Deepest dungeon", text_title_pos, 50, 3, BLACK);
		DrawTextEx(font2, "The Deepest Dungeon stands as a forgotten place", text_pos, 30, 3, BLACK);
		DrawTextEx(font2, "etched in history as one of the most grim and", Vector2{ text_pos.x, text_pos.y + book_move_y }, 30, 3, BLACK);
		DrawTextEx(font2, "mysterious locations in the world. According to", Vector2{ text_pos.x, text_pos.y + book_move_y * 2 }, 30, 3, BLACK);
		DrawTextEx(font2, "legends, these dungeons were constructed", Vector2{ text_pos.x, text_pos.y + book_move_y * 3 }, 30, 3, BLACK);
		DrawTextEx(font2, "centuries ago by an ancient civilization as an", Vector2{ text_pos.x, text_pos.y + book_move_y * 4 }, 30, 3, BLACK);
		DrawTextEx(font2, "underground prison for the most dangerous", Vector2{ text_pos.x, text_pos.y + book_move_y * 5 }, 30, 3, BLACK);
		DrawTextEx(font2, "criminals and creatures. As the tales go,", Vector2{ text_pos.x, text_pos.y + book_move_y * 6 }, 30, 3, BLACK);
		DrawTextEx(font2, "the Deepest Dungeon was initially meant to be", Vector2{ text_pos.x, text_pos.y + book_move_y * 7 }, 30, 3, BLACK);
		DrawTextEx(font2, "an exceptionally severe form of justice,", Vector2{ text_pos.x, text_pos.y + book_move_y * 8 }, 30, 3, BLACK);
		DrawTextEx(font2, "where convicts would serve a lifetime sentence", Vector2{ text_pos.x, text_pos.y + book_move_y * 9 }, 30, 3, BLACK);
		DrawTextEx(font2, "in darkness, deprived of light and hope for", Vector2{ text_pos.x, text_pos.y + book_move_y * 10 }, 30, 3, BLACK);
		DrawTextEx(font2, "freedom. However, over time, these dungeons", Vector2{ text_pos.x, text_pos.y + book_move_y * 11 }, 30, 3, BLACK);
		DrawTextEx(font2, "gradually fell into obscurity, and their true", Vector2{ text_pos.x, text_pos.y + book_move_y * 12 }, 30, 3, BLACK);
		DrawTextEx(font2, "nature became increasingly shrouded in", Vector2{ text_pos.x, text_pos.y + book_move_y * 13 }, 30, 3, BLACK);
		DrawTextEx(font2, "mystery. Stories of the Deepest Dungeon", Vector2{ text_pos.x, text_pos.y + book_move_y * 14 }, 30, 3, BLACK);
		DrawTextEx(font2, "attracted adventurers and scholars from around", Vector2{ text_pos.x, text_pos.y + book_move_y * 15 }, 30, 3, BLACK);
		DrawTextEx(font2, "the world, though few returned to tell of", Vector2{ text_pos.x, text_pos.y + book_move_y * 16 }, 30, 3, BLACK);
		DrawTextEx(font2, "into the darkness of these dungeons often", Vector2{ text_pos.x + book_move_x, text_pos.y }, 30, 3, BLACK);
		DrawTextEx(font2, "spoke of unimaginable obstacles: from traps", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y }, 30, 3, BLACK);
		DrawTextEx(font2, "and ambushes to dark creatures lurking", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 2 }, 30, 3, BLACK);
		DrawTextEx(font2, "living in the shadows.", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 3 }, 30, 3, BLACK);
		DrawTextEx(font2, "According to some legends, the Deepest", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 4 }, 30, 3, BLACK);
		DrawTextEx(font2, "Dungeon is also saturated with mysterious", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 5 }, 30, 3, BLACK);
		DrawTextEx(font2, "magic, causing time and space to behave", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 6 }, 30, 3, BLACK);
		DrawTextEx(font2, " differently than on the surface.", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 7 }, 30, 3, BLACK);
	}
	if ((CheckCollisionPointRec(bookshelf3_1_pos, player.rec2) || CheckCollisionPointRec(bookshelf3_2_pos, player.rec2)) && player.interact)
	{
		if (play)
		{
			play = false;
			SetSoundVolume(book_sound, 0.2);
			PlaySound(book_sound);
		}
		DrawTexturePro(book, book1, book2, book_origin, 0, RAYWHITE);
		DrawTextEx(font2, "Guard's Journal", text_title_pos, 50, 3, BLACK);
		DrawTextEx(font2, "Today is the day. I can feel it in my bones. It's", text_pos, 30, 3, BLACK);
		DrawTextEx(font2, "something deeper, darker, something even the", Vector2{ text_pos.x, text_pos.y + book_move_y }, 30, 3, BLACK);
		DrawTextEx(font2, " boldest of guards would have to ignore to", Vector2{ text_pos.x, text_pos.y + book_move_y * 2 }, 30, 3, BLACK);
		DrawTextEx(font2, "maintain their sanity.", Vector2{ text_pos.x, text_pos.y + book_move_y * 3 }, 30, 3, BLACK);
		DrawTextEx(font2, "My body doesn't react as it used to. Wounds", Vector2{ text_pos.x, text_pos.y + book_move_y * 4 }, 30, 3, BLACK);
		DrawTextEx(font2, "heal too quickly, and the pain becomes ", Vector2{ text_pos.x, text_pos.y + book_move_y * 5 }, 30, 3, BLACK);
		DrawTextEx(font2, "increasingly unfamiliar. This morning, when I", Vector2{ text_pos.x, text_pos.y + book_move_y * 6 }, 30, 3, BLACK);
		DrawTextEx(font2, "looked into the mirror, I saw a reddish glow in my", Vector2{ text_pos.x, text_pos.y + book_move_y * 7 }, 30, 3, BLACK);
		DrawTextEx(font2, "eyes, and my skin seemed paler than usual.", Vector2{ text_pos.x, text_pos.y + book_move_y * 8 }, 30, 3, BLACK);
		DrawTextEx(font2, "My last shifts at the outpost have been weird. I", Vector2{ text_pos.x, text_pos.y + book_move_y * 9 }, 30, 3, BLACK);
		DrawTextEx(font2, "felt as if someone or something was watching me", Vector2{ text_pos.x, text_pos.y + book_move_y * 10 }, 30, 3, BLACK);
		DrawTextEx(font2, "from the shadows. Now, as evening approaches, I", Vector2{ text_pos.x, text_pos.y + book_move_y * 11 }, 30, 3, BLACK);
		DrawTextEx(font2, "must examine myself. I don't know what this night", Vector2{ text_pos.x, text_pos.y + book_move_y * 12 }, 30, 3, BLACK);
		DrawTextEx(font2, "will bring, but I'm prepared for what's to come.", Vector2{ text_pos.x, text_pos.y + book_move_y * 13 }, 30, 3, BLACK);
		DrawTextEx(font2, "May this journal remain a testament to my life.", Vector2{ text_pos.x, text_pos.y + book_move_y * 14 }, 30, 3, BLACK);
		DrawTextEx(font2, "I perish or am transformed into something I can't", Vector2{ text_pos.x, text_pos.y + book_move_y * 15 }, 30, 3, BLACK);
		DrawTextEx(font2, "imagine, may it endure as a warning to others.", Vector2{ text_pos.x, text_pos.y + book_move_y * 16 }, 30, 3, BLACK);
		DrawTextEx(font2, "This may be my last entry. But if I survive,", Vector2{ text_pos.x + book_move_x, text_pos.y }, 30, 3, BLACK);
		DrawTextEx(font2, "I promise to return and tell the whole story.", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y }, 30, 3, BLACK);
		DrawTextEx(font2, "Farewell, those of you who read these words.", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 2 }, 30, 3, BLACK);
		DrawTextEx(font2, "Prayers for safety are welcome.", Vector2{ text_pos.x + book_move_x, text_pos.y + book_move_y * 3 }, 30, 3, BLACK);
	}
}
void Stage1::check_door_collision(Player& player, int i, int j)
{
	if (CheckCollisionPointRec(door1_pos, player.rec2) && map[13][7] != '3')
	{
		if (item1_count == 1)
			door1_locked = false;
		else if (item1_count == 0)
			door1_locked = true;

		if (player.interact && !door1_locked)
		{
			player.interact = false;
			PlaySound(door_unlock_sound);
			map[13][7] = '3';
			item1_count = 0;
		}
		else if (player.interact && door1_locked)
		{
			player.interact = false;
			PlaySound(door_locked_sound);
		}
	}
	else if (CheckCollisionPointRec(door2_pos, player.rec2) && map[3][3] != '3')
	{
		if (item1_count == 1)
			door2_locked = false;
		else if (item1_count == 0)
			door2_locked = true;

		if (player.interact && !door2_locked)
		{
			player.interact = false;
			PlaySound(door_unlock_sound);
			map[3][3] = '3';
			item1_count = 0;
		}
		else if (player.interact && door2_locked)
		{
			player.interact = false;
			PlaySound(door_locked_sound);
		}
	}
	else if (CheckCollisionPointRec(door3_pos, player.rec2) && map[3][17] != '3')
	{
		if (item1_count == 1)
			door3_locked = false;
		else if (item1_count == 0)
			door3_locked = true;

		if (player.interact && !door3_locked)
		{
			player.interact = false;
			PlaySound(door_unlock_sound);
			map[3][17] = '3';
			item1_count = 0;
		}
		else if (player.interact && door3_locked)
		{
			player.interact = false;
			PlaySound(door_locked_sound);
		}
	}
	else if (CheckCollisionPointRec(door4_pos, player.rec2) && map[15][17] != '3')
	{
		if (item1_count == 1)
			door4_locked = false;
		else if (item1_count == 0)
			door4_locked = true;

		if (player.interact && !door4_locked)
		{
			player.interact = false;
			PlaySound(door_unlock_sound);
			map[15][17] = '3';
			item1_count = 0;
		}
		else if (player.interact && door4_locked)
		{
			player.interact = false;
			PlaySound(door_locked_sound);
		}
	}
}
void Stage1::check_chest_collision(Player& player)
{
	if ((CheckCollisionPointRec(chest1_1_pos, player.rec2) || CheckCollisionPointRec(chest1_2_pos, player.rec2)) && player.interact)
	{
		if (play)
		{
			play = false;
			SetSoundVolume(chest_sound, 0.3);
			PlaySound(chest_sound);
		}
		check_item1(player);
		if (item1_1_appear)
		{
			DrawTexturePro(key, rec1, item1, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item1_1_count_ch), Vector2{ 220, 818 }, 20, 5, WHITE);
		}
		if (item2_1_appear)
		{
			DrawTexturePro(apple, rec1, item2, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item2_1_count_ch), Vector2{ 333, 818 }, 20, 5, WHITE);
		}
		DrawRectangleLinesEx(item1, 5, DARKGREEN);
		DrawRectangleLinesEx(item2, 5, DARKGREEN);
	}
	else if ((CheckCollisionPointRec(chest2_1_pos, player.rec2) || CheckCollisionPointRec(chest2_2_pos, player.rec2)) && player.interact)
	{
		if (play)
		{
			play = false;
			SetSoundVolume(chest_sound, 0.3);
			PlaySound(chest_sound);
		}
		check_item2(player);
		if (item1_2_appear)
		{
			DrawTexturePro(key, rec1, item1, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item1_2_count_ch), Vector2{ 220, 818 }, 20, 5, WHITE);
		}
		DrawRectangleLinesEx(item1, 5, DARKGREEN);
	}
	else if ((CheckCollisionPointRec(chest3_1_pos, player.rec2) || CheckCollisionPointRec(chest3_2_pos, player.rec2)) && player.interact)
	{
		if (play)
		{
			play = false;
			SetSoundVolume(chest_sound, 0.3);
			PlaySound(chest_sound);
		}
		check_item3(player);
		if (item1_3_appear)
		{
			DrawTexturePro(key, rec1, item1, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item1_3_count_ch), Vector2{ 220, 818 }, 20, 5, WHITE);
		}
		if (item2_3_appear)
		{
			DrawTexturePro(apple, rec1, item2, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item2_3_count_ch), Vector2{ 333, 818 }, 20, 5, WHITE);
		}
		if (item3_3_appear)
		{
			DrawTexturePro(potion, rec1, item3, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item3_3_count_ch), Vector2{ 446, 818 }, 20, 5, WHITE);
		}
		if (item4_3_appear)
		{
			DrawTexturePro(gold_bar, rec1, item4, origin_item, 0, WHITE);
		}
		DrawRectangleLinesEx(item1, 5, DARKGREEN);
		DrawRectangleLinesEx(item2, 5, DARKGREEN);
		DrawRectangleLinesEx(item3, 5, DARKGREEN);
		DrawRectangleLinesEx(item4, 5, DARKGREEN);
	}
	else if ((CheckCollisionPointRec(chest4_1_pos, player.rec2) || CheckCollisionPointRec(chest4_2_pos, player.rec2)) && player.interact)
	{
		if (play)
		{
			play = false;
			SetSoundVolume(chest_sound, 0.3);
			PlaySound(chest_sound);
		}
		check_item4(player);
		if (item1_4_appear)
		{
			DrawTexturePro(key, rec1, item1, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item1_4_count_ch), Vector2{ 220, 818 }, 20, 5, WHITE);
		}
		if (item2_4_appear)
		{
			DrawTexturePro(apple, rec1, item2, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item2_4_count_ch), Vector2{ 333, 818 }, 20, 5, WHITE);
		}
		if (item3_4_appear)
		{
			DrawTexturePro(potion, rec1, item3, origin_item, 0, WHITE);
			DrawTextEx(font1, TextFormat("%d", item3_4_count_ch), Vector2{ 446, 818 }, 20, 5, WHITE);
		}
		DrawRectangleLinesEx(item1, 5, DARKGREEN);
		DrawRectangleLinesEx(item2, 5, DARKGREEN);
		DrawRectangleLinesEx(item3, 5, DARKGREEN);
	}
}

//Assigning textures to map values
void Stage1::manage_tiles(int i, int j)
{
	switch (map[i][j])
	{
	case '0':
		DrawTexturePro(wall1, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '1':
		DrawTexturePro(wall2, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '2':
		DrawTexturePro(floor1, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '3':
		DrawTexturePro(door, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '4':
		DrawTexturePro(upstairs, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '5':
		DrawTexturePro(floor2, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '6':
		DrawTexturePro(floor3, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '7':
		DrawTexturePro(floor4, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '8':
		DrawTexturePro(prison_wall, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case '9':
		DrawTexturePro(wall_window, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'a':
		DrawTexturePro(wall_bars, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'b':
		DrawTexturePro(blood1, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'c':
		DrawTexturePro(blood2, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'd':
		DrawTexturePro(skulls_pile, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'e':
		DrawTexturePro(skull_bones, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'f':
		DrawTexturePro(bones, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'g':
		DrawTexturePro(bed, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'h':
		DrawTexturePro(barrel, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'i':
		DrawTexturePro(spider_web, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'j':
		DrawTexturePro(passage, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'k':
		DrawTexturePro(door_locked, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'l':
		DrawTexturePro(chest, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'm':
		DrawTexturePro(coins, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'n':
		DrawTexturePro(bookshelf, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'o':
		DrawTexturePro(closet, rec1, rec2, origin, 0, RAYWHITE);
		break;

	case 'u':
		DrawTexturePro(shelf, rec1, rec2, origin, 0, RAYWHITE);
		break;
	}
}

//Checking collisions public
void Stage1::manage_collisions(Player& player)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == '9' || map[i][j] == 'a' || map[i][j] == '8' || map[i][j] == 'g' || map[i][j] == 'h' ||
				map[i][j] == 'u' || map[i][j] == 'o' || map[i][j] == 'n' || map[i][j] == 'l' || map[i][j] == 'k')
				check_stop_collision(player, i, j);
			if (map[i][j] == '3' || map[i][j] == 'b' || map[i][j] == 'c' || map[i][j] == 'd' || map[i][j] == 'e' || map[i][j] == 'f' ||
				map[i][j] == 'i')
				check_sound_collision(player, i, j);
			if (map[i][j] == '2' || map[i][j] == '5' || map[i][j] == '6' || map[i][j] == '7' || map[i][j] == 'j' || map[i][j] == 'n')
				check_no_collision(player, i, j);
			if (map[i][j] == 'm')
				check_coin_collision(player, i, j);
		    if (map[i][j] == 'n')
				check_bookshelf_collision(player);
			if (map[i][j] == '4')
				check_win_collision(player, i, j);
			if (map[i][j] == 'l')
				check_chest_collision(player);
			if (map[i][j] == 'k')
				check_door_collision(player, i, j);
		}
	}
}
void Stage1::check_fight1(Player& player, Enemy& enemy)
{
	if (CheckCollisionRecs(player.rec2, enemy.rec2))
		fight1 = true;
}
void Stage1::check_fight2(Player& player, Enemy& enemy)
{
	if (CheckCollisionRecs(player.rec2, enemy.rec2))
		fight2 = true;
}
void Stage1::check_fight3(Player& player, Enemy& enemy)
{
	if (CheckCollisionRecs(player.rec2, enemy.rec2))
		fight3 = true;
}
void Stage1::check_fight4(Player& player, Enemy& enemy)
{
	if (CheckCollisionRecs(player.rec2, enemy.rec2))
		fight4 = true;
}
void Stage1::check_fight5(Player& player, Enemy& enemy)
{
	if (CheckCollisionRecs(player.rec2, enemy.rec2))
		fight5 = true;
}

//Drawing map and equipment
void Stage1::draw_map()
{
	DrawRectangleRoundedLines(Rectangle{ 602, 225 , 720, 720 }, 0.1f, 0, 3, BLACK);
	DrawTextEx(font1, "Deepest dungeon", Vector2{ 680, 80 }, 100, 5, BLACK);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			rec2.x = float(j * scale_width + calibrate_x);
			rec2.y = float(i * scale_height + calibrate_y);
			manage_tiles(i, j);
		}
	}
}
void Stage1::draw_eq_items(Player& player)
{
	DrawRectangleRoundedLines(Rectangle{ x1_eq, y1_eq, width1_eq, height1_eq }, 0.1f, 0, 3, BLACK);
	DrawRectangleRoundedLines(Rectangle{ x2_eq, y2_eq, width2_eq, height2_eq }, 0.1f, 0, 3, BLACK);
	DrawRectangleRoundedLines(Rectangle{ x1_items, y1_items, width1_items, height1_items }, 0.1f, 0, 3, BLACK);
	DrawRectangleRoundedLines(Rectangle{ x2_items, y2_items, width2_items, height2_items }, 0.1f, 0, 3, BLACK);
	DrawRectangleRounded(Rectangle{ x2_eq, y2_eq, width2_eq, height2_eq }, 0.1f, 0, WHITE);
	DrawRectangleRounded(Rectangle{ x2_items, y2_items, width2_items, height2_items }, 0.1f, 0, WHITE);
	DrawTextEx(font1, "Equipment", eq_pos, 60, 5, BLACK);
	DrawTextEx(font1, TextFormat("Gold: %d", gold_count), gold_pos, 30, 5, BLACK);
	DrawTextEx(font1, "Items", items_pos, 60, 5, BLACK);
	DrawRectangleLinesEx(ch_item1, 5, DARKGREEN);
	DrawRectangleLinesEx(ch_item2, 5, DARKGREEN);
	DrawRectangleLinesEx(ch_item3, 5, DARKGREEN);
	DrawRectangleLinesEx(ch_item4, 5, DARKGREEN);
	DrawRectangleLinesEx(ch_item5, 5, DARKGREEN);
	DrawRectangleLinesEx(ch_item6, 5, DARKGREEN);

	if (item1_count > 0)
		DrawTexturePro(key, rec1, eq_item1, origin_item, 0, RAYWHITE);
	if (item2_count > 0)
		DrawTexturePro(apple, rec1, eq_item2, origin_item, 0, RAYWHITE);

	if (!item1_2_appear)
		DrawTexturePro(key, rec1, eq_item1, origin_item, 0, RAYWHITE);

	if (!item1_3_appear)
		DrawTexturePro(key, rec1, eq_item1, origin_item, 0, RAYWHITE);
	if (!item2_3_appear)
		DrawTexturePro(apple, rec1, eq_item2, origin_item, 0, RAYWHITE);
	if (!item3_3_appear)
		DrawTexturePro(potion, rec1, eq_item3, origin_item, 0, RAYWHITE);

	if (!item1_4_appear)
		DrawTexturePro(key, rec1, eq_item1, origin_item, 0, RAYWHITE);
	if (!item2_4_appear)
		DrawTexturePro(apple, rec1, eq_item2, origin_item, 0, RAYWHITE);
	if (!item3_4_appear)
		DrawTexturePro(potion, rec1, eq_item3, origin_item, 0, RAYWHITE);

	if (item1_count == 0)
		DrawRectangleRec(eq_item1, RAYWHITE);
	if (item2_count == 0)
		DrawRectangleRec(eq_item2, RAYWHITE);
	if (CheckCollisionPointRec(player.mouse_pos, eq_item2) && player.hp < player.max_hp && player.item_interact && item2_count > 0)
	{
		player.hp += 10;
		if (player.hp > player.max_hp)
			player.hp -= player.hp - player.max_hp;
		item2_count -= 1;
		player.item_interact = false;
	}
	player.potion_count = item3_count;

	DrawTextEx(font1, TextFormat("%d", item1_count), Vector2{ ch_item1.x + 80, ch_item1.y + 70 }, 20, 5, WHITE);
	DrawTextEx(font1, TextFormat("%d", item2_count), Vector2{ ch_item2.x + 80, ch_item2.y + 70 }, 20, 5, WHITE);
	DrawTextEx(font1, TextFormat("%d", item3_count), Vector2{ ch_item3.x + 80, ch_item3.y + 70 }, 20, 5, WHITE);

	DrawTextEx(font1, "0", Vector2{ ch_item4.x + 80, ch_item4.y + 70}, 20, 5, WHITE);
	DrawTextEx(font1, "0", Vector2{ ch_item5.x + 80, ch_item5.y + 70 }, 20, 5, WHITE);
	DrawTextEx(font1, "0", Vector2{ ch_item6.x + 80, ch_item6.y + 70 }, 20, 5, WHITE);
}

//Bad ending and good ending
void Stage1::ending()
{
	stop_music();
	PlaySound(ending_music);
	while (!quit)
	{
		if (!IsSoundPlaying(ending_music))
			PlaySound(ending_music);
		ClearBackground(Color{ 40, 90, 105, 255 });
		DrawRectangleRec(Rectangle{ 450, 280, 1000, 500 }, WHITE);
		DrawRectangleLinesEx(Rectangle{ 450, 280, 1000, 500 }, 5, BLACK);
		DrawTextEx(font1, "After leaving the dungeon, the knight felt the", Vector2{ 500, 340 }, 60, 3, BLACK);
		DrawTextEx(font1, "the sun's rays on his skin. Ahead of him", Vector2{ 500, 400 }, 60, 3, BLACK);
		DrawTextEx(font1, "land full of dangers and mysteries. From the", Vector2{ 500, 460 }, 60, 3, BLACK);
		DrawTextEx(font1, "depths of the dungeon emerged a hero, ready", Vector2{ 500, 520 }, 60, 3, BLACK);
		DrawTextEx(font1, "for new adventures and challenges that awaited", Vector2{ 500, 580 }, 60, 3, BLACK);
		DrawTextEx(font1, "him on the surface.", Vector2{ 500, 640 }, 60, 3, BLACK);
		DrawTextEx(font1, "Press Enter to exit...", Vector2{ 725, 850 }, 60, 3, BLACK);
		if (IsKeyPressed(KEY_ENTER))
			quit = true;
		EndDrawing();
	}
}
void Stage1::death()
{
	stop_music();
	PlaySound(death_music);
	while (!quit)
	{
		if (!IsSoundPlaying(death_music))
			PlaySound(death_music);
		ClearBackground(Color{ 40, 90, 105, 255 });
		DrawRectangleRec(Rectangle{ 450, 280, 1000, 500 }, WHITE);
		DrawRectangleLinesEx(Rectangle{ 450, 280, 1000, 500 }, 5, BLACK);
		DrawTextEx(font1, "You are dead!", Vector2{ 635, 455 }, 150, 3, BLACK);
		DrawTextEx(font1, "Press Enter to exit...", Vector2{ 730, 850 }, 60, 3, BLACK);
		if (IsKeyPressed(KEY_ENTER))
			quit = true;
		EndDrawing();
	}
}