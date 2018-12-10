#include"CScene.h"

CScene::CScene()
{
	m_numPlayer = 2;
	arr_unitList = CArray<CUnit>(m_numPlayer);
}

CScene::CScene(int num)
{
	m_numPlayer = num;
	arr_unitList = CArray<CUnit>(m_numPlayer);
}

int CScene::findNum(int num)
{
	int length = arr_unitList.getLength();
	for (int i = 0; i < length; i++)
	{
		if (arr_unitList[i].getNum() == num)
			return i;
	}
	return -1;
}

int CScene::getUnitNum()
{
	return arr_unitList.getLength();
}

void CScene::placeUnit(CUnit unit)
{
	arr_unitList.pushBack(unit);
}

void CScene::delUnit(CUnit& unit)
{
	int num = unit.getNum();
	int index = findNum(num);
	arr_unitList.erase(index);
}

CScene& CScene::getSituation()
{
	return *this;
}

CUnit& CScene::getLastUnit()
{
	return arr_unitList.last();
}

void CScene::mvUnit(CUnit& unit, CPoint<int> pos)
{
	unit.movePosition(pos.getx(), pos.gety());
}

void CScene::clrPlayer(int player)
{
	int length = arr_unitList.getLength();
	for (int i = 0; i < length; i++)
	{
		if (arr_unitList[i].getOwner() == player)
			arr_unitList.erase(i);
	}
}

void CScene::changeUnitOwner(CUnit& unit, int player)
{
	unit.changeOwner(player);
}