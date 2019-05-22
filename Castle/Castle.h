#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include <vector>
#include "Tower.h"

class Battle;

class Castle
{

	Tower Towers[NoOfRegions];
	Battle* Battle_Ptr;
	
public:

	Castle();
	void SetBattlePtr(Battle* ptr);
	Battle* GetBattlePtr();
	void SetTowerHealth(REGION TowerRegion, double h);
	Tower* getTowers();
	
};
