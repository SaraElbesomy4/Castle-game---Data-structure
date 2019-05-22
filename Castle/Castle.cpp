#include "Castle.h"
#include "..\Battle.h"
#include "..\GUI\GUI.h"



Castle::Castle()
{
	for (int i = 0; i < NoOfRegions; i++)
		Towers[i].SetCastlePtr(this);
}

void Castle::SetTowerHealth(REGION TowerRegion, double h)
{
	Towers[TowerRegion].SetHealth(h);
}
void Castle::SetBattlePtr(Battle* ptr)
{
	Battle_Ptr = ptr;
}

Battle* Castle::GetBattlePtr()
{
	return Battle_Ptr;
}

Tower* Castle::getTowers()
{
	return Towers;
}