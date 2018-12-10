#pragma once
#include"CArray.h"
#include"CChessPiece.h"
#include"CChessBoard.h"

class CSubBoard
{
public:
	CSubBoard(CChessBoard &, CChessPiece, direction);
	int operator[](int);
	int getCount();
	int getBegin();
	int getEnd();
	int getScore();
private:
	int board[9];
	int begin, end, count, score;
};