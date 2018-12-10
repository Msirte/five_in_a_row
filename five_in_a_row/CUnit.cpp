#include"CUint.h"

int CUnit::totalNum = 0;

CUnit::CUnit()
{
	m_owner = 0;
	m_type = 0;
	m_position.set(0, 0);
	totalNum++;
	m_num = totalNum;
}

CUnit::CUnit(int owner, int type, CPoint<int> pos)
{
	m_owner = owner;
	m_type = type;
	m_position.set(pos.getx(), pos.gety());
	totalNum++;
	m_num = totalNum;
}

int CUnit::getOwner()
{
	return m_owner;
}

void CUnit::changeOwner(int owner)
{
	m_owner = owner;
}

int CUnit::getType()
{
	return m_type;
}

int CUnit::getNum()
{
	return m_num;
}

CPoint<int> CUnit::getPosition()
{
	return m_position;
}

void CUnit::setPosition(int x, int y)
{
	m_position.set(x, y);
}

void CUnit::movePosition(int x, int y)
{
	m_position.move(x, y);
}

CUnit & CUnit::operator=(CUnit & unit)
{
	if (this == &unit)
		return *this;
	m_owner = unit.m_owner;
	m_type = unit.m_type;
	m_position.set(unit.getPosition().getx(), unit.getPosition().gety());
	totalNum++;
	m_num = totalNum;
}