#pragma once
#include "Enemy.h"

class EnemyFreezer : public Enemy

{

public:
	EnemyFreezer(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE typee, Tower* ptr);
	~EnemyFreezer();
	virtual void Act();
};