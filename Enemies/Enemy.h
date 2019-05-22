#ifndef ENEMY_H
#define ENEMY_H

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include <iostream>


//Enemies colors for next phases
//You can choose whatever colors you like for your enemies
const color FIGHTER_CLR = ORANGERED;
const color FEEZER_CLR = CYAN;
const color HEALER_CLR = LIGHTGREEN;
const color WEAKEN_CLR = PURPLE;
const color COLLECTOR_CLR = YELLOW;

class Tower;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int distance = MaxDistance;	//Horizontal distance between enemy & the tower of its region
					//Always positive (ranges from 2 to 60)
	double priority;//priority of the enemy
	double Health;	//Enemy health
	double original_health;   //Enemy original health
	double power;   //Enemy attack power
	double LT =0;      //Enemy Life time 
	double KTS=0;		//Enemy Killed Time
	double FST = 0;		//Enemy Fist-shot Time
	double KD= 0;      //Enemy Killed Time delay
	double FD =0;      //Enemy First-shot delay
	double T= 0;       //Enemy Arrival time
	double RLD;     //Enemy reload period
	                //We Would Make The Enemy Reload Every 5 steps
	ENEMY_TYPE type;
	ENEMY_STATE state;          //Enemy State (Frozen,Inaction,Reloading)

	int steps = 0;              //Counting the Enemy Steps 
	Tower* Tower_Ptr;
	bool is_attacked = false;   // Flag show if it is the first time to bbe attacked or not
	double first_shoot_time;     // to store the first time shoot.
public:
	Enemy(int id, double t, double h, double Pow, double rld, REGION r_region, ENEMY_TYPE typee, Tower* ptr);
	 ~Enemy();

	 int clockIce;				//Clock for freezed time
	 int clockReload;             //Clock for reload time
	color GetColor() const;
	REGION GetRegion() const;
	void DecrementDist();
	void SetDistance(int d);
	int GetDistance() const;
	double GetHealth() const;
	void SetKD(double kd);
	ENEMY_TYPE GetType() const;
	double GetKD() const;
	void SetFD(double fd);
	double GetFD() const;
	double GetPriority() const;
	double GetArrivalTime() const;
	void SetArrivalTime(double t);
	void CalPriority();
	void Damage(double bullet);
	void frozen();                 //the enemy would be freezed for 2 time step
	void Clocks();      
	void Reloading();
	bool isKilled();
	double GetKTS() const;
	void SetKTS(double Time);
	double GetLT() const;
	void SetFST(double Time);
	double GetFST() const;
	void SetLT(double Time);
	int GetId() const;
	void setRegion(REGION reg);
	double GetOriginalHealth();
	double GetPower();
	void SetHealth(double h);
	virtual void Act() = 0;
	void SetFirst_shoot_time(double timestep);
	double GetFirst_shoot_time();
	void SetIs_attacked();
	bool GetIs_attacked();

	//


};

#endif