#pragma once

#define NoOfRegions 4
#define MaxDistance  60         // the maximum distance between any enemy and its tower
#define MinDistance  2          // the minimum distance between any enemy and its tower
#define MaxVerticalEnemies  15   // the maximum number of enemies that can be drawn
		                        // if they are in the same region and same distance
								// (will be drawn vertical to each other)
#define MaxEnemyCount 300      // the maximum number of enemies the application can work on
#define MaxTimeStep 70		    //Maximum TimeStep for simulation Iteration


//The four regions: A, B, C , and D
enum REGION {	
	A_REG = 0,
	B_REG = 1,
	C_REG = 2, 
	D_REG = 3
};

enum MODE {
	INTERACTIVE = 0,
	SILENT
};

// The three states of any enemy in Active enemiesheap
enum ENEMY_STATE {
	Frozen,
	Inaction,
	Reloading,
	KILLED
};

enum ENEMY_TYPE {
	FIGHTER = 1,
	FREEZER = 2,
	HEALER = 3,
	WEAKEN = 4,
	COLLECTOR = 5
};

// The tree tower states 
enum TOWER_STATE {
	Active = 0,
	Freezed = 1,
	Killed = 2,
	NoPower = 3
};


enum MenuItem
{
	//Note: menu icons are ordered here as they appear in menu
	//If you want to change the menu icons order, change the order here

	MENU_LOAD,
	MENU_EXIT,

	//TODO: Add more items names here
	//      for the 3 modes of the application
				
	MENU_ITM_COUNT	//no. of menu icons ==> This should be the last line in this enum
};

struct Point
{
	int x;
	int y;
	Point(int a=0, int b=0)	//constructor
	{ x=a;	y=b;	}
};