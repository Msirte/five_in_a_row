#pragma once
#include"CUint.h"

class CChessPiece : public CUnit
{
public:
	CChessPiece();
	CChessPiece(int, int, CPoint<int>);
};