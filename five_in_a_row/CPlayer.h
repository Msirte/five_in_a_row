#pragma once
#include"CUint.h"
#include"CChessPiece.h"

class CPlayer
{
public:
	CPlayer(int);
	CPlayer(int, int);
	int getNum();
	int getType();
	virtual CChessPiece nextMove(CPoint<int>) = 0;
private:
	int num;
	int type;
};