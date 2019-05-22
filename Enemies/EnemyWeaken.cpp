#include "EnemyWeaken.h"
#include "..\Castle\Tower.h"
#include <iostream>

EnemyWeaken::EnemyWeaken(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE typee, Tower* ptr) : Enemy(id, t, h, Pow, rld, r_region, typee, ptr)
{
	Clr = WEAKEN_CLR;
}

void EnemyWeaken::Act()
{
	Reloading();
		if (clockReload == 0)
		{
			double current_power = Tower_Ptr->GetPower();
			double power_weaken = 0.01*current_power * GetDistance() / (double(MaxDistance));
			double new_power = current_power - power_weaken;
			Tower_Ptr->SetPower(new_power);
		}
	clockReload--;
}

EnemyWeaken::~EnemyWeaken()
{

}