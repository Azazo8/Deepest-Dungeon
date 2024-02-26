#include "Enemy.h"

//Moving Enemies with predefined paths
void Enemy::move()
{
	if (hp > 0)
	{
		if (id == 1)
		{
			timer1++;
			if (timer1 == 3 || timer1 == 9 || timer1 == 12)
				rec2.x -= speed;
			else if (timer1 == 6)
				rec2.y -= speed;
			else if (timer1 == 21 || timer1 == 24 || timer1 == 30)
				rec2.x += speed;
			else if (timer1 == 27)
				rec2.y += speed;
			else if (timer1 == 36)
				timer1 = 0;
		}
		if (id == 2)
		{
			timer2++;
			if (timer2 == 3)
				rec2.x -= speed;
			else if (timer2 == 6 || timer2 == 9 || timer2 == 12 || timer2 == 15 || timer2 == 18 || timer2 == 21 || timer2 == 24)
				rec2.y -= speed;
			else if (timer2 == 27)
				rec2.x += speed;
			else if (timer2 == 30 || timer2 == 33 || timer2 == 36 || timer2 == 39 || timer2 == 42 || timer2 == 45 || timer2 == 48)
				rec2.y += speed;
			else if (timer2 == 51)
			{
				rec2.x -= speed;
				timer2 = 3;
			}
		}
		if (id == 3)
		{
			timer3++;
			if (timer3 == 3)
				rec2.x += speed;
			else if (timer3 == 6 || timer3 == 9)
				rec2.y -= speed;
			else if (timer3 == 12 || timer3 == 15)
				rec2.x -= speed;
			else if (timer3 == 18 || timer3 == 21)
				rec2.y += speed;
			else if (timer3 == 24 || timer3 == 27)
			{
				rec2.x += speed;
				timer3 = 0;
			}
		}
		if (id == 4)
		{
			timer4++;
			if (timer4 == 3 || timer4 == 6)
				rec2.x -= speed;
			else if (timer4 == 21 || timer4 == 24)
				rec2.x += speed;
			else if (timer4 == 27)
				timer4 = 0;
		}
		if (id == 5)
		{
			timer5++;
			if (timer5 == 3 || timer5 == 6 || timer5 == 9)
				rec2.y -= speed;
			else if (timer5 == 12 || timer5 == 15 || timer5 == 18)
				rec2.x -= speed;
			else if (timer5 == 21 || timer5 == 30 || timer5 == 33)
				rec2.y += speed;
			else if (timer5 == 24 || timer5 == 27 || timer5 == 36)
				rec2.x += speed;
			else if (timer5 == 39)
				timer5 = 0;
		}
	}
}

//Constructor for an enemy
Enemy::Enemy(int Id, int Strength, int Vitality, int Dexterity, int Endurance, float A, float B)
{
	id = Id;
	strength = Strength;
	vitality = Vitality;
	dexterity = Dexterity;
	endurance = Endurance;
	pos_x = A * scale_width + calibrate_x;
	pos_y = B * scale_height + calibrate_y;
	rec2 = { pos_x, pos_y, scale_width, scale_height };
	hp = 10 * vitality;
	stamina = endurance * 10;
	damage = strength + GetRandomValue(4, 10);
	block = dexterity * 3;
}

//Getters
int Enemy::get_hp()
{
	return hp;
}

//Drawing enemy
void Enemy::draw()
{
	DrawTexturePro(skeleton, rec1, rec2, origin, 0, RAYWHITE);
	move();
}