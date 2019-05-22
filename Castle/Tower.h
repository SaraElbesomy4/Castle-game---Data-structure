#ifndef TOWER_H
#define TOWER_H

#include "..\Defs.h"
#include "..\Enemies\Enemy.h"

class Castle;

class Tower
{
private:

	double Health;			   //Tower Health
	double Power;			   //Tower Power
	TOWER_STATE state = Active;//Tower state(Active,Freezed,Killed)
	int EnemiesNumber;		   //active enemies number	
	int KilledEnemiesNumber;   //killed enemies number
	double freezed = 0;
	REGION regioon;
	int attackCapacity;          //the number of enemies the tower could attack every time step
	double sum_of_ice = 0;       // the sum of ice thrown on the tower by the enemies
	Castle *Castle_Ptr;


public:

	Tower();
	~Tower();
	//setter and getters
	void SetHealth(double h);
	double GetHealth() const;
	void SetPower(double Power);
	int clockIcee = 0;
	void SetRegion(int x);
	double GetPower() const;
	void SetEnemiesNumber(int EnemiesNumber);
	int GetEnemiesNumber() const;
	void IncrementKilledEnemies();
	int GetKilledEnemiesNumber() const;
	void Damaged(double h);
	TOWER_STATE GetState();
	void SetattackCapacity(int attack_number);
	int GetattackCapacity() const;
	REGION getRegion();
	void setState(TOWER_STATE statee);

	void SetCastlePtr(Castle* ptr);
	Castle* GetCastlePtr();
	
	//action methods
	void attack(Enemy* e);
	// function to count the ice on the tower
	void CountIce(double icebullet);
	//void freeze();
	//
	

};

#endif