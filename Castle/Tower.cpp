#include "Tower.h"
#include "Castle.h"
#include <cstdlib>
#include <ctime>

Tower::Tower()
{
	EnemiesNumber = 0;
	KilledEnemiesNumber = 0;
}

void Tower::SetCastlePtr(Castle* ptr)
{
	Castle_Ptr = ptr;
}

Castle* Tower::GetCastlePtr()
{
	return Castle_Ptr;
}

void Tower::SetHealth(double h)
{
	if (h > 0)
		Health = h;
	else
	{
		Health = 0; // killed
		state = Killed;
	}
}

// function to count the ice on the tower
void Tower::CountIce(double icebullet)
{

	sum_of_ice = sum_of_ice + icebullet;

	if (sum_of_ice >= (Health *0.1))
	{
		clockIcee = 1;
		state = Freezed;
		sum_of_ice = 0;
	}
}

double Tower::GetHealth() const
{
	return Health;
}
void Tower::SetPower(double power)
{
	Power = power;
	if (Power <= 0)
	{
		state = NoPower;
		Power = 0;
	}
}
double Tower::GetPower() const
{
	return Power;
}
void Tower::SetEnemiesNumber(int enemiesNumber)
{
	EnemiesNumber = enemiesNumber;
}
int Tower::GetEnemiesNumber() const
{
	return EnemiesNumber;
}
void Tower::IncrementKilledEnemies()
{
	KilledEnemiesNumber++;
}
int Tower::GetKilledEnemiesNumber() const
{
	return KilledEnemiesNumber;
}

TOWER_STATE Tower::GetState()
{
	return state;
}


void Tower::Damaged(double h)
{
	Health = Health - h;
	if (Health <= 0)
	{
		Health = 0;
		state = Killed;
	}
}

void Tower::SetRegion(int x)
{
	regioon = (REGION)x;
}

//randomize the fires to make 20% of it as ice

void Tower::attack(Enemy* e)
{
	srand(time(0));
	int x = rand() % 100;

	if (clockIcee == 0)
		state = Active;

	if (state == Freezed)
		clockIcee--;

	if (state == Active)
	{
		int distance = e->GetDistance();
		double bulletHealer = (Power * (1.0 / distance)) / 2.0;
		double bulletFire = (Power * (1.0 / distance));

		if ( x >= 20 ) // the tower shoots fire
		{

			if ((e->GetType() == FIGHTER) || (e->GetType() == FREEZER))
			{
				e->Damage(bulletFire);
			}
			else if (e->GetType() == COLLECTOR)
			{
				e->Damage(bulletFire);
			}
			else if  (e->GetType() == WEAKEN)
			{
				e->Damage(bulletFire);
			}
			else if (e->GetType() == HEALER)
			{
				e->Damage(bulletHealer);
			}
		}
		//in case the tower shoots ice on enemies 
		else 
		{
			e->frozen();
		}
	}
}

void Tower::SetattackCapacity(int attack_number)
{
	attackCapacity = attack_number;
}
int Tower::GetattackCapacity() const
{
	return attackCapacity;
}

Tower::~Tower()
{

}

REGION Tower::getRegion()
{
	return regioon;
}

void Tower::setState(TOWER_STATE statte)
{
	state = statte;
}