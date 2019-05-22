#include "EnemyHealer.h"
#include "..\Castle\Tower.h"
#include "..\Battle.h"
#include <iostream>

EnemyHealer::EnemyHealer(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE typpe, Tower* ptr) : Enemy(id, t, h, Pow, rld, r_region, typpe, ptr)
{
	Clr = HEALER_CLR;
}

void EnemyHealer::Act()
{

	double distance_of_healer = GetDistance();
	int const Array_size = 100;
	int enemies_counter;

	Enemyheap<MaxEnemyCount> *ActiveEnemies_copy = Tower_Ptr->GetCastlePtr()->GetBattlePtr()->GetActiveList(GetRegion());
	Enemy* healed_enemy = ActiveEnemies_copy->Dequeue(); // note: performing dequeue to enable us to access the enemy class items
	Enemy *Enemy_Array[MaxEnemyCount];

	int k = 0;
	double health_increase = 2;

	while (healed_enemy != nullptr)
	{
		double distance_of_enemyH = healed_enemy->GetDistance();
		double relative_distanceH = abs(distance_of_enemyH - distance_of_healer);    // distance relative to healer
		double currenthealth_of_enemyH = healed_enemy->GetHealth();
		double originalhealth_of_enemyH = healed_enemy->GetOriginalHealth();
		if (relative_distanceH <= 2 && currenthealth_of_enemyH <= (originalhealth_of_enemyH * (3.0 / 4.0)) && GetId() != healed_enemy->GetId())
		{
			double new_health = health_increase + healed_enemy->GetHealth();
			healed_enemy->SetHealth(new_health);
			//cout << new_health << "          " << currenthealth_of_enemy << endl;  //this is just for testing
		}
		Enemy_Array[k] = healed_enemy;
		k++;
		healed_enemy = ActiveEnemies_copy->Dequeue();
	}

	for (int i = 0; i < k; i++)
		ActiveEnemies_copy->Enqueue(Enemy_Array[i]);
}


EnemyHealer::~EnemyHealer()
{

}