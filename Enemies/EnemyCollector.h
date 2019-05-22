#pragma once
#include "Enemy.h"

class EnemyCollector : public Enemy

{

public:
	EnemyCollector(int id, double t, double h, double Pow, double rld, REGION r_region,ENEMY_TYPE type, Tower* ptr);
	~EnemyCollector();
	virtual void Act();
};