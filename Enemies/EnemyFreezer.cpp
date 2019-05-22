#include "EnemyFreezer.h"
#include "..\Castle\Tower.h"
#include <iostream>

EnemyFreezer::EnemyFreezer(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE typee, Tower* ptr) : Enemy(id, t, h, Pow, rld, r_region, typee, ptr)
{
	Clr = FEEZER_CLR;
}

void EnemyFreezer::Act()
{
	Reloading();
	if (clockReload == 0)
	{
		double ice_bullet = 5;
		Tower_Ptr->CountIce(ice_bullet);
	}
	clockReload--;
}


EnemyFreezer::~EnemyFreezer()
{

}