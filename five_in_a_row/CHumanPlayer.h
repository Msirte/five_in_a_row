#pragma once
#include"CPlayer.h"

class CHumanPlayer : public CPlayer
{
public:
	CHumanPlayer(int);
	CHumanPlayer(int, int);
	CChessPiece nextMove(CPoint<int>);
	CPoint<int> getInput();
};