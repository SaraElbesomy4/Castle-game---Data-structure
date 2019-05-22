#pragma once
#include "Enemy.h"

class EnemyWeaken : public Enemy

{

public:
	EnemyWeaken(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE type, Tower* ptr);
	~EnemyWeaken();
	virtual void Act();

};