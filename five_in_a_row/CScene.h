#pragma once
#include"CPoint.h"
#include"CArray.h"
#include"CUint.h"

class CScene
{
public:
	CScene();
	CScene(int);
	int findNum(int);
	int getUnitNum();
	void placeUnit(CUnit);
	void delUnit(CUnit&);
	CScene& getSituation();
	CUnit& getLastUnit();
	void mvUnit(CUnit&, CPoint<int>);
	void clrPlayer(int);
	void changeUnitOwner(CUnit&, int);
private:
	int m_numPlayer;
	CArray<CUnit> arr_unitList;
};