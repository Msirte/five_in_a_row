#pragma once
#include"CPlayer.h"
#include"CChessBoard.h"

class CAI : public CPlayer
{
public:
	CAI(int);
	CAI(int, int);
	virtual CChessPiece nextMove(CPoint<int>);
	CPoint<int> calculate(CChessBoard);
private:
	int score[15][15];
	int loss[15][15];
};
