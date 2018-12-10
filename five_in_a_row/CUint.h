#pragma once
#include"CPoint.h"

class CUnit
{
public:
	CUnit();
	CUnit(int, int, CPoint<int>);
	int getOwner();
	void changeOwner(int);
	int getType();
	int getNum();
	CPoint<int> getPosition();
	void setPosition(int, int);
	void movePosition(int, int);
	CUnit & operator=(CUnit &);
private:
	int m_num;
	int m_owner;
	int m_type;
	CPoint<int> m_position;
	static int totalNum;
};