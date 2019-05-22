#include "EnemyFighter.h"
#include "..\Castle\Tower.h"
#include <iostream>

EnemyFighter::EnemyFighter(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE typee, Tower* ptr) : Enemy(id, t, h, Pow, rld, r_region, typee, ptr)
{
	Clr = FIGHTER_CLR;
}

void EnemyFighter::Act()
{
	Reloading();
	if (clockReload == 0)
	{

		int current_distance = GetDistance();
		double current_health = GetHealth();
		double current_power = GetPower();
		double Tower_damage;
		if (current_health <= 0.5* original_health)
		{
			Tower_damage = (0.5 / current_distance)* current_power;
		}
		else
		{
			Tower_damage = (1.0 / current_distance)* current_power;
		}
		Tower_Ptr->Damaged(Tower_damage);

	}

	clockReload--;
}

EnemyFighter::~EnemyFighter()
{
	
}