#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Defs.h"

using namespace std;

void InputGenerator(int factor)
{
	ofstream output;
	output.open("input.txt");
	srand(time(0));
	int maxNo = 10 + rand() % (10);
	int startPower = (250 + rand() % (60 - 10 + 1)) * (factor);
	int InitialHealth = 1500 * factor;
	output << InitialHealth << "\t" << maxNo << "\t" << startPower << endl;
	int noHealers = 0;
	int noFighters = 0;
	vector<int> randomRoles;
	vector<char> randomPlace;
	vector<int> randomPower;
	vector<int> randomHealth;
	vector<int> randomReload;
	vector<int> randomTime;
	for (int i = 1; i <= MaxEnemyCount; i++)
	{
		int x = 1 + rand() % (MaxEnemyCount);
		if (x <= 60)
		{
			noHealers++;
			randomRoles.push_back(2);
		}
		else
		{
			noFighters++;
			randomRoles.push_back(1);
		}
	}
	for (int i = 1; i <= MaxEnemyCount; i++)
	{
		int x = rand() % (100);
		if (0 <= x && x < 25)
		{
			randomPlace.push_back('A');          //Region A
		}
		if (25 <= x && x < 50)
		{
			randomPlace.push_back('B');          //Region B
		}
		if (50 <= x && x < 75)
		{
			randomPlace.push_back('C');         //Region C
		}
		if (75 <= x && x < 100)
		{
			randomPlace.push_back('D');         //Region D
		}
	}

	for (int i = 1; i <= MaxEnemyCount; i++)
	{
		int x = 1 + rand() % (50);
		randomHealth.push_back(150 + x);

	}
	for (int i = 1; i <= MaxEnemyCount; i++)
	{
		int x = 1 + rand() % (50);
		randomPower.push_back(150 + x);
	}
	//randomized reload time with at least 1 time step reload time and 4 as maximum
	for (int i = 1; i <= MaxEnemyCount; i++)
	{
		int x = 1 + rand() % 4;
		randomReload.push_back(x);
	}
	//randomized arrival time with at maximum value as MaxTimeStep(defined in Defs.h)
	//that means that at time step 25 all enemies are spawned
	for (int i = 1; i <= MaxEnemyCount; i++)
	{
		int x = rand() % (MaxTimeStep);
		randomTime.push_back(x);
	}
	sort(randomTime.begin(), randomTime.end());
	for (int i = 1; i <= MaxEnemyCount; i++)
	{

		output << i << "\t" << randomRoles[i - 1] << "\t" << randomTime[i - 1] << "\t" << randomHealth[i - 1] << "\t" << randomPower[i - 1] << "\t" << randomReload[i - 1] << "\t" << randomPlace[i - 1] << endl;

	}

	output << -1 << endl;
	output.close();
}