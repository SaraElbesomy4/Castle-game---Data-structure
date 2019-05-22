#pragma once
#include "Enemy.h"

class EnemyFighter : public Enemy

{

public:
	EnemyFighter(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE type, Tower* ptr);
	~EnemyFighter();
	virtual void Act();
};